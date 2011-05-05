import processing.net.*;

Client c;
String data;

void setup() {
  size(200, 200);
  background(50);
  fill(200);
  //c = new Client(this, "www.google.co.uk", 80); // Connect to server on port 80
  c = new Client(this, "search.twitter.com", 80); // Connect to server on port 80
  //c.write("GET /images/nav_logo40.png HTTP/1.1\r\n"); // Use the HTTP "GET" command to ask for a Web page
  //c.write("GET /search?q=test HTTP/1.1\r\n\r\n"); // Use the HTTP "GET" command to ask for a Web page
  
  c.write("GET /search.json?q=love HTTP/1.1\r\n"); // Use the HTTP "GET" command to ask for a Web page
  c.write("Host: search.twitter.com\r\n\r\n"); // Use the HTTP "GET" command to ask for a Web page
  //c.write("User-Agent: Mozilla/5.0\r\n"); // Use the HTTP "GET" command to ask for a Web page

  //c.write("Accept-language: en-us,en;q=0.5\r\n"); 
  //c.write("Accept-charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n"); 
  //c.write("Cache-control: max-age=0\r\n"); 
  //c.write("Client-ip: 172.16.64.1\r\n"); 
  //c.write("Connection: close\r\n\r\n"); 
  
  //c.write("GET /search.html HTTP/1.1\r\n\r\n"); // Use the HTTP "GET" command to ask for a Web page
  //c.write("Host: davidedc.com\r\n"); // Use the HTTP "GET" command to ask for a Web page
  //c.write("User-Agent: MSIE\r\n\r\n"); // Use the HTTP "GET" command to ask for a Web page
  //c.write("Host: my_domain_name.com\n\n"); // Be polite and say who we are
}

void draw() {
  if (c.available() > 0) { // If there's incoming data from the client...
    println("printing out the data now");
    data = c.readString(); // ...then grab it and print it    
    println("length of data:"+data.length());
    println(data);
  }
}


