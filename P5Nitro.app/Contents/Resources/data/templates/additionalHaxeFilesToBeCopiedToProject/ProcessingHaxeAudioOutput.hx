
class ProcessingHaxeAudioOutput
{

   public function new() : Void
   {
		// do nothing
		//trace("ProcessingHaxeAudioOutput constructor \n");
   }

   public function hasGainControlArgCount0()
   {
	  //trace("ProcessingHaxeAudioOutput hasGainControlArgCount0 \n");
      return false;
   }

   public function hasVolumeControlArgCount0()
   {
	  //trace("ProcessingHaxeAudioOutput hasVolumeControlArgCount0 \n");
      return true;
   }

   public function hasPanControlArgCount0()
   {
	  //trace("ProcessingHaxeAudioOutput hasPanControlArgCount0 \n");
      return true;
   }

}
