import nme.events.Event;
import nme.net.URLLoader;
import nme.net.URLRequest;
import nme.net.URLLoaderDataFormat;
import nme.events.IOErrorEvent;
import nme.events.ProgressEvent;
import nme.errors.SecurityError;
import nme.errors.TypeError;

// [todo]
// There are a couple of problems with this class
// One: it's quite brittle. There is some parsing going on that
// is really prone to failure as of now.
// Two: it's based on a "higher level" implementation, so some of the
// detailed controls and info are missing.
// This is partly because in flash there are a number of restrictions in terms
// of what kinds of requests you can make, so it's all rather abstract, you can't
// just bang straight characters into a TCP connection.
// Also the nekonme implementation is not complete, for example one can't
// specify not to automatically follow redirects.
// Also URLLoader waits to load the complete file before making the data available.
// (while URLStream class doesn't, but it's not implemented yet)
// In particular, nme.net.URLLoader and nme.net.Request
// return the data already stripped from the headers.
// Which in a way is good, because headers can get a little complicated and your data could
// be split into chunks, http responses can be convoluted and involve redirects (which in this
// implementation are handled completely transparently.
// The trouble though is that a part of the header that gives you the HTTP response
// status and the length of the message are missing from your data, and I'd expect
// some people to rely on the complete HTTP header being sent back together with the data
// All the data below that I'd receive from the same sketch done in processing
// are missing:
/*
HTTP/1.1 200 OK
Date: Mon, 11 Apr 2011 17:00:08 GMT
Expires: -1
Cache-Control: private, max-age=0
Content-Type: text/html; charset=ISO-8859-1
Set-Cookie: PREF=ID=1ad6ce7f93c62738...
Set-Cookie: NID=45=c0OYk8OIwI3p4iHGK...
Server: gws
X-XSS-Protection: 1; mode=block
Transfer-Encoding: chunked

1000
[start of the first chunk of 1000 bytes]
*/

// In theory the most minimal http response header that one has to
// send is only the status line followed by the content.
// see http://www.jmarshall.com/easy/http/#headerlines
// So in theory we should re-build the reply header (also taking into account whether the
// user issued an HTTP/1.0 or HTTP/1.1 request)


class ProcessingHaxeClient {
   var socketNumber:Int;
   var serverNameOrIp:String;
   var requestString:String;
   var itsAGet:Bool;
   var itsAPost:Bool;
   var theFileToBeFetched:String;
   var request:URLRequest;
   var loader:URLLoader;
   var dataBufferIsNotEmpty:Bool;
   var finalDataBuffer:nme.utils.ByteArray;
   var httpHeaderVersionSecondDigit:Int;
   var originalContentLength:Int;
   var url:String;

   public function new(theMain:Main, theServerNameOrIp:String, theSocketNumber:Int) : Void {
      serverNameOrIp = theServerNameOrIp;
      socketNumber = theSocketNumber;
      // note that we don't do anything with the first parameter
   }

   // [todo] this implementation is less then ideal for a couple
   // of reasons.
   // First off, we buffer the whole request until a double
   // carriage return is found. Which in theory is unnecessary, in
   // a socket we should send the data as soon as it is available
   // Second reason: we extract the url in a rather brittle way
   // because we expect the request to be written with a specific format
   // like this:
   //   c = new Client(this, "www.google.com", 80); // Connect to server on port 80
   //   c.write("GET /search?q=test HTTP/1.1\r\n\r\n");
   // which is a big assumption, as the write could really split the request in any
   // number of chunks, or send other data such as referrer, etc.
   // So, all in all this makeshift parsing is only going to work in basic cases

   public function writeArgCount1(theString:String):Void {
	   requestString = requestString + theString;
	   //trace("writeArgCount1 started");
	   
	   if ( theString.indexOf("GET ") ==  0 ) {
	       //trace("writeArgCount1 > oh it starts with GET");
	       
	       if ( theString.indexOf("HTTP/1.0") !=  -1 ) {
	       	httpHeaderVersionSecondDigit = 0;
	   	   }
	       else if ( theString.indexOf("HTTP/1.1") !=  -1 ) {
	       	httpHeaderVersionSecondDigit = 1;
	   	   }
	       
	       // this shoud extract the filename from something like
	       // "GET /search?q=test HTTP/1.1\r\n\r\n"
	       // or "GET /search?q=test HTTP/1.1\n\n\n\n"
	       // or "GET /search?q=test HTTP/1.1\r\n"
	       // or "GET /search?q=test HTTP/1.1\n"
	       // or like the above but with HTTP/1.0
		   itsAGet = true;
		   theFileToBeFetched = theString.substr(4); // eliminates the GET
		   theFileToBeFetched = StringTools.replace(theFileToBeFetched,"\\n","");
		   theFileToBeFetched = StringTools.replace(theFileToBeFetched,"\\r","");
		   theFileToBeFetched = StringTools.replace(theFileToBeFetched," HTTP/1.1","");
		   theFileToBeFetched = StringTools.replace(theFileToBeFetched," HTTP/1.0","");
		   theFileToBeFetched = StringTools.replace(theFileToBeFetched," ","");
	       //trace("writeArgCount1 > the file to be fetched is: " + theFileToBeFetched);
	   }
	   else if ( theString.indexOf("POST ") ==  0 ) {
		   itsAPost = true;
	   }

	   // if the string ends with a double carriage return then
	   //trace("writeArgCount1 > indexOf " + theString.indexOf("\\r\\n\\r\\n"));
	   //trace("writeArgCount1 > indexOf2 " + theString.indexOf("\r\n\r\n"));
	   //trace("writeArgCount1 > length " + theString.length);
	   if (
	   	(theString.indexOf("\n\n") ==  (theString.length - 2) ) ||
	   	(theString.indexOf("\r\n\r\n") ==  (theString.length - 4) )
	   ) {
	        //trace("writeArgCount1 > found the end of the request");
	        // [todo] - this is brittle stuff
	        // We are going to combine the url and the file path
	        // into one single valid url.
	        // Again, brittle method to try to cater
	        // for the cases where the user has omitted "http://" from the url
	        // or the trailing slash in the path.
	        url = "http://" + serverNameOrIp + "/" + theFileToBeFetched;
	        url = StringTools.replace(url,"http://http://","http://");
	        url = StringTools.replace(url,"//","/");
	        url = StringTools.replace(url,"http:/","http://");
	        //trace("writeArgCount1 > url is: " + url);
	        
            request = new URLRequest(url);

			loader = new URLLoader();
            loader.dataFormat = URLLoaderDataFormat.BINARY;
            
			
			try {
				loader.load(request);
			}
			catch (error:SecurityError)
			{
				trace("A SecurityError has occurred.");
			}
			
			loader.addEventListener(IOErrorEvent.IO_ERROR, errorHandler);
			// we could do something when the loader is complete or progresses,
			// but processing doesn't handle this, so there is no need here
			loader.addEventListener(Event.COMPLETE, loaderCompleteHandler);
			loader.addEventListener(ProgressEvent.PROGRESS, onProgress);

	   }
   }
   
   function onProgress(event:ProgressEvent) {
	    //trace("Loaded " + event.bytesLoaded + "/" + event.bytesTotal );
	    //dataBufferIsNotEmpty = true;
   }
   
   private function loaderCompleteHandler(event:Event):Void {
		//trace("Complete");
		
		originalContentLength = loader.data.length;
		dataBufferIsNotEmpty = true;
		finalDataBuffer = new nme.utils.ByteArray();
		
		// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
		//finalDataBuffer.writeUTFBytes("HTTP/1."+ httpHeaderVersionSecondDigit +" 200 OK\r\n");
		
		// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
		//finalDataBuffer.writeUTFBytes("Content-Length: "+ originalContentLength +"\r\n");
		
		// for a list of mime types see http://www.w3schools.com/media/media_mimeref.asp
		if (url.indexOf(".html") != -1) {
			// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
			//finalDataBuffer.writeUTFBytes("Content-Type: text/html\r\n");
		}
		else if (url.indexOf(".txt") != -1) {
			// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
			//finalDataBuffer.writeUTFBytes("Content-Type: text/plain\r\n");
		}
		else if (url.indexOf(".gif") != -1) {
			// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
			//finalDataBuffer.writeUTFBytes("Content-Type: image/gif\r\n");
		}
		else if (url.indexOf(".jpeg") != -1) {
			// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
			//finalDataBuffer.writeUTFBytes("Content-Type: image/jpeg\r\n");
		}
		else if (url.indexOf(".jpg") != -1) {
			// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
			//finalDataBuffer.writeUTFBytes("Content-Type: image/jpeg\r\n");
		}
		else if (url.indexOf(".png") != -1) {
			// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
			//finalDataBuffer.writeUTFBytes("Content-Type: image/png\r\n");
		}
		
		// final new line before data starts
		// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
		//finalDataBuffer.writeUTFBytes("\r\n");

		
		// [todo] in theory one could try to deduce the mime filetype and put it here
		finalDataBuffer.writeBytes(loader.data,0,loader.data.length);
		finalDataBuffer.position = 0;
		//trace("\nData without header length: "+ loader.data.length);
		//trace("\nData with header: "+ finalDataBuffer.asString());
		//trace("\nData with header length: "+ finalDataBuffer.length);
		loader = null;
    }

	// in theory it could be other errors, but let's take the
	// most common case here, we assume that the problem
	// is that the page doesn't exist.
	private function errorHandler(e:IOErrorEvent):Void {
	    // trace("errorHandler > something bad happened: " + e);
		dataBufferIsNotEmpty = true;
		finalDataBuffer = new nme.utils.ByteArray();
		// COMMENTEDOUTBECAUSEOFwriteUTFBytesToBufferERROR
		// finalDataBuffer.writeUTFBytes("HTTP/1."+ httpHeaderVersionSecondDigit +" 404 Not Found\r\n\r\n");
		finalDataBuffer.position = 0;	    
	}


public function availableArgCount0():Int{
	//trace("availableArgCount0  starting");
	if (!dataBufferIsNotEmpty) {
	    //trace("availableArgCount0  nothing moved so far ");
		return 0;
	}
	// Returns the number of bytes in the buffer waiting to be read
    //trace("\nData with header length: "+ finalDataBuffer.length);
	//trace("\nData with header position: "+ finalDataBuffer.position);
	//trace("availableArgCount0  returning: " + finalDataBuffer.bytesAvailable);
	return finalDataBuffer.bytesAvailable;
}

public function readArgCount0():Int{
	// Returns a byte from the buffer
	return finalDataBuffer.readByte();
}

public function readCharArgCount0():String{
	// Returns the next byte in the buffer as a char
	return finalDataBuffer.readString(1);
}

public function readBytesArgCount0(): haxe.io.Bytes{
	// Reads everything in the buffer
	return finalDataBuffer.getBytes();
}

// readBytesUntil()	Reads from the buffer of bytes up to and including a particular character
public function readStringArgCount0():String {
// Returns the buffer as a String
    //trace(" returning " + finalDataBuffer.bytesAvailable + " bytes as string ");
	return finalDataBuffer.readString(finalDataBuffer.bytesAvailable);
}

// readStringUntil()	Returns the buffer as a String up to and including a particular character

// write()	Writes bytes, chars, ints, bytes[], Strings
// clear()	Clears the buffer
// stop()	Disconnects from the server
// ip()	Returns the IP address of the machine as a String

} // end of class
