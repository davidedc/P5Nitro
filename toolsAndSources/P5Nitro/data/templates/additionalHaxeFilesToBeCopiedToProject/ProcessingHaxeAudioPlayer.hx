/*

   This class maps the behaviour of the AudioPlayer class of Minim
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

class ProcessingHaxeAudioPlayer extends ProcessingHaxeAudioSnippet {

   public function new(theFilename : String) : Void {
       // the second parameter forces the AudioSnipper class
       // to load the file as music instead of as Sound as normal
	   super(theFilename, true);
   }

}
