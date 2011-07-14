import nme.media.Sound;

class ProcessingHaxeMinim {

   public function new() : Void {
	  //trace("ProcessingHaxeMinim constructor \n");
      // does nothing
   }

   public function loadSnippetArgCount1(fileName:String):ProcessingHaxeAudioSnippet {
	  //trace("ProcessingHaxeMinim loadSnippetArgCount1 \n");
      return new ProcessingHaxeAudioSnippet(fileName);
   }

   public function loadFileArgCount1(fileName:String):ProcessingHaxeAudioPlayer {
	  //trace("ProcessingHaxeMinim loadFileArgCount1 \n");
      return new ProcessingHaxeAudioPlayer(fileName);
   }

   public function closeArgCount1() {
	  //trace("ProcessingHaxeMinim closeArgCount1 \n");
      // does nothing
   }

   public function stopArgCount0() {
	  //trace("ProcessingHaxeMinim stopArgCount0 \n");
      // does nothing
   }

   public function getLineOutArgCount0() {
	  //trace("ProcessingHaxeMinim getLineOutArgCount0 \n");
      return new ProcessingHaxeAudioOutput();
   }   

}
