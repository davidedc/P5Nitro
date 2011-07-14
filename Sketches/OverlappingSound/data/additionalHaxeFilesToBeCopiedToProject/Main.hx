import nme.Lib;
import nme.Timer;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.media.Sound;

class Bang extends Bitmap{

   static var mImage : BitmapData = null;
   static var mOffX = 0;
   static var mOffY = 0;

   public function new(inX:Float, inY:Float) {
      super();

      var mSound : Sound = null;
      if (mImage==null) {
         mImage = BitmapData.load("bang.png");
         mOffX = -Math.round(mImage.width/2);
         mOffY = -Math.round(mImage.height/2);

         // Can only play 1 mp3 at a time...
         // and it seems that only .wav files and .mp3 can be played
        
         mSound = new Sound( new nme.net.URLRequest("drums.aiff") );
      }

      bitmapData = mImage;
      x = inX + mOffX;
      y = inY + mOffY;

	  mSound.play(0,-1);

      var me = this;
      
      // however long you want the bang image to stay on screen
      // the sound will keep playing anyways if the image
      // is removed
      haxe.Timer.delay( function() me.Remove(), 300 );
   }

   function Remove() {
   	trace("removing bang image");
      parent.removeChild(this);
   }
}



class Main extends nme.display.Sprite {
   public function new() {
      super();

      nme.Lib.current.stage.addChild(this);

      var sound_name = "Party_Gu-Jeremy_S-8250_hifi.mp3";
      var sound = new Sound( new nme.net.URLRequest(sound_name) );
      var channel = sound.play(0,-1);
      channel.addEventListener( nme.events.Event.SOUND_COMPLETE, function(_) { trace("Complete"); } );

      var bmp = new Bitmap();
      bmp.bitmapData = BitmapData.load("drum_kit.jpg");
      addChild(bmp);
      addEventListener( nme.events.MouseEvent.MOUSE_DOWN, onClick );
   }

   public function onClick(inEvent:nme.events.MouseEvent) {
      addChild( new Bang( inEvent.stageX, inEvent.stageY ) );
   }

   public static function main() {
      new Main();
   }

}
