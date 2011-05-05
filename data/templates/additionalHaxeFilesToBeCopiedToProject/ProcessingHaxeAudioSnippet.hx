/*

   This class maps the behaviour of the AudioSnippet class of Minim
   onto the underlying nekonme implementation, which is based on the
   flash.media.Sound and flash.media.SoundChannel APIs
   
   The two behaviours are a bit different. In nekonme, one Sound can be played
   any number of times concurrently by calling its play method. The play()
   method allows you to specify if the sound is looped. It also allows
   you to specify a startTime (but not an end time like minim).
   Invoking play gives you back a SoundChannel which can you only stop(), or change its
   volume and pan. You can't pause or resume a SoundChannel.
   
   In Minim each AudioSnippet can play one one sound at a time and you can pause it, rewind
   it, play it, in a similar way to a cassette player.
   
   There are some quirky behaviours that make sense if you think in terms of a cassette
   player, i.e. if you hit rewind() while you play a loop, it rewinds to the beginning
   of the track rather than to the beginning of the loop. The loop resumes to its normal
   start and end points after the head reached the loop end point.
   
   The only piece of semantics that couldn't be implemented is the loop endPoint. There
   is no concept of any endPoint in the underlying Sound/SoundChannel API, so to implement
   that one would have to put some kind of polling in place checking the head position
   - which could be done.
   
   Another difference between the two APIs is that Minim gives you no way of being
   notified upon completion of a play, while the Sound/SoundChannel API provides for that.
   
   The Sound/SoundChannel API is available from the Adobe web site, their implementation is in the
   nekonme Google Docs repo, in the following files:
   Sound.hx and SoundChannel.hx, ExternailInterface.cpp AND the target-specific implementations,
   which for the iPhone is all contained in the Sound.mm file.
   
*/


import nme.media.Sound;
import nme.media.SoundChannel;
import nme.media.SoundTransform;
import nme.events.Event;

class ProcessingHaxeAudioSnippet {
   public var currentSoundTransform: SoundTransform;
   public var userAskedForLoops : Bool;
   public var loopStart : Int;
   public var currentSound : Sound;
   public var currentSoundChannel : SoundChannel;
   public var cue : Int;
   public var length : Int;
   public var playHeadIsGoing : Bool;
   public var fileName : String;
   public var ignoreTheNextLoopEndCallback : Bool;


   public function new(theFilename : String, ?forceLoadAsMusic : Bool) : Void {
	  //trace("ProcessingHaxeAudioSnippet constructor \n");
   	  fileName = theFilename;
   	  currentSoundTransform = new SoundTransform();
   	  // the true flag is to force the use of AVAudioPlayer,
   	  // which streams mp3s instead of keeping them
   	  // uncompressed in memory
   	  
   	  // the false flag means that it's loaded as sound and not as music
   	  // this means that it's going to stay in memory uncompressed
   	  // the true flag is set only if the second parameter has been specified, which only
   	  // happens when called from the ProcessingHaxeAudioSnippet subclass.
   	  currentSound = new Sound( new nme.net.URLRequest(fileName), null, (forceLoadAsMusic != null) ? true : false );
   	  length = Std.int(currentSound.length);
   	  loopStart = 0;
   	  cue = 0;
   }

   public function setVolumeArgCount1(theVolume:Float) : Void {
	  //trace("ProcessingHaxeAudioSnippet setVolumeArgCount1 \n");
	  currentSoundTransform.volume = theVolume;
	  if (currentSoundChannel != null) {
	    currentSoundChannel.soundTransform = currentSoundTransform;
	  }
   }

   public function setPanArgCount1(thePan:Float) : Void {
	  //trace("ProcessingHaxeAudioSnippet setPanArgCount1 \n");
	  currentSoundTransform.pan = thePan;
   }

   public function positionArgCount0() : Int {
	  //trace("ProcessingHaxeAudioSnippet positionArgCount0 \n");
	  if (currentSoundChannel != null) {
	    return Std.int(currentSoundChannel.position);
	  }
	  else {
	    //trace("returning cue because curentSoundChannel is null \n");
	  	return cue;
	  }
   }

   public function cueArgCount1(position:Int) : Void {
	 //trace("ProcessingHaxeAudioSnippet cueArgCount1 \n");
	 stopSoundChannel();
	 cue = position;
     startSoundChannel();

   }

   public function setGainArgCount1(theGain:Float) : Void {
	  //trace("ProcessingHaxeAudioSnippet setGainArgCount1 \n");
	  // theGain is between -80 and 14 and we'll map it
	  // to the range 0, +1
	  // Note that in theory gain and volume are two separate
	  // concepts, we are mapping gain into volume in a
	  // simplified way
	  setVolumeArgCount1((theGain + 80)/94);
   }

   public function loopCompleted( event:Event ) : Void {
     if (ignoreTheNextLoopEndCallback) {
       //trace("loop end from a stoppped track - ignoring");
       ignoreTheNextLoopEndCallback = false;
       return;
     }
     //trace("loop end");
     if (userAskedForLoops) {
       //trace("going back to start of the loop");
       currentSoundChannel = currentSound.play((loopStart==-1?0:loopStart),0,currentSoundTransform);
       currentSoundChannel.addEventListener( nme.events.Event.SOUND_COMPLETE, loopCompleted );
       playHeadIsGoing = true;
     }
   }

   public function playArgCount0() : Void {
	 //trace("ProcessingHaxeAudioSnippet playArgCount0 \n");
     // todo: doesn't take care of pause yet
     userAskedForLoops = false;
     startSoundChannel();
   }

   private function startSoundChannel() : Void {
	 //trace("ProcessingHaxeAudioSnippet startSoundChannel \n");
   	 stopSoundChannel();
     currentSoundChannel = currentSound.play(cue,0,currentSoundTransform);
     currentSoundChannel.addEventListener( nme.events.Event.SOUND_COMPLETE, loopCompleted );
     playHeadIsGoing = true;
   }

   public function pauseArgCount0() : Void {
	 //trace("ProcessingHaxeAudioSnippet pauseArgCount0 \n");
   	 if (currentSoundChannel != null) {
   	 	cue = Std.int(currentSoundChannel.position);
   	    stopSoundChannel();
   	 }
   	 playHeadIsGoing = false;
   }

   public function rewindArgCount0() : Void {
	 //trace("ProcessingHaxeAudioSnippet rewindArgCount0 \n");
	 cue = 0;
   	 if (playHeadIsGoing) {
	    //trace("playHead is going\n");
		 if (currentSoundChannel != null) {
			 currentSoundChannel.stop();
			 ignoreTheNextLoopEndCallback = true;
		 }
		 currentSoundChannel = null;
   	    // when you hit rewind you always start from the beginning,
   	    // then loop start and stop will kick off again when the playhead
   	    // reaches the end.
     	currentSoundChannel = currentSound.play(0,0,currentSoundTransform);
        currentSoundChannel.addEventListener( nme.events.Event.SOUND_COMPLETE, loopCompleted );
   	 }
   	 else {
	    //trace("playHead is not going\n");
   	 }
   }

   public function loopArgCount0() : Void {
	 //trace("ProcessingHaxeAudioSnippet loopArgCount0 \n");
   	 stopSoundChannel();
   	 userAskedForLoops = true;
   	 cue = loopStart;
   	 startSoundChannel();
   	 playHeadIsGoing = true;
   }

   public function lengthArgCount0() : Int {
	//trace("ProcessingHaxeAudioSnippet lengthArgCount0 \n");
    // for some reason this is a float in flash, need
    // to convert it.
   	return Std.int(currentSound.length);
   }

   private function stopArgCount0() : Void {
	 //trace("ProcessingHaxeAudioSnippet stopArgCount0 \n");
     userAskedForLoops = false;
	 stopSoundChannel();
   }

   private function stopSoundChannel() : Void {
	 //trace("ProcessingHaxeAudioSnippet stopSoundChannel \n");
   	 if (currentSoundChannel != null) {
		 currentSoundChannel.stop();
		 currentSoundChannel = null;
		 ignoreTheNextLoopEndCallback = true;
   	 }
   }

   public function getControlsArgCount0() : String {
	 //trace("ProcessingHaxeAudioSnippet getControlsArgCount0 \n");
   	 return "mewww";
   }

   public function getMinimumGainArgCount0() : Float {
	 //trace("ProcessingHaxeAudioSnippet getMinimumGainArgCount0 \n");
   	 return -80;
   }

   public function getMaximumGainArgCount0() : Float {
	 //trace("ProcessingHaxeAudioSnippet getMaximumGainArgCount0 \n");
   	 return 14;
   }

   public function closeArgCount0() {
	 //trace("ProcessingHaxeAudioSnippet closeArgCount0 \n");
     // does nothing
   }

   public function setLoopPointsArgCount2( a:Int, b:Int) {
	 //trace("ProcessingHaxeAudioSnippet setLoopPointsArgCount2 \n");

	 // If you invoke setLoopPoints AFTER you invoked a loop(),
	 // what happens is that the currently ongoing loop goes ahead till the end of
	 // the track, and then the loop repeats from the new start and end points
	 
   	 stopSoundChannel();
   	 loopStart = a;
   }

}
