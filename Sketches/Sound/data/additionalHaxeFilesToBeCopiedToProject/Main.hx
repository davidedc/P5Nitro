import nme.Lib;
import nme.Timer;
import nme.display.Bitmap;
import nme.display.BitmapData;
import nme.media.Sound;


class Bang extends Bitmap
{
   static var mImage : BitmapData = null;
   static var mSound1 : Sound = null;
   static var mSound2 : Sound = null;
   static var mSound3 : Sound = null;
   static var mOffX = 0;
   static var mOffY = 0;


   public function new(inX:Float, inY:Float)
   {
      super();

      if (mImage==null)
      {
         mImage = BitmapData.load("bang.png");
         mOffX = -Math.round(mImage.width/2);
         mOffY = -Math.round(mImage.height/2);


         // Can only play 1 mp3 at a time...
         // AND it seems that only .wav files and .mp3 can be played
         // ... no ogg or waiffs
        
         //mSound1 = new Sound( new nme.net.URLRequest("drum.ogg") );
         mSound1 = new Sound( new nme.net.URLRequest("bass.wav") );

         //mSound2 = new Sound( new nme.net.URLRequest("drums.aiff") );
         mSound2 = new Sound( new nme.net.URLRequest("bass.wav") );

         mSound3 = new Sound( new nme.net.URLRequest("bass.wav") );
      }

      bitmapData = mImage;
      x = inX + mOffX;
      y = inY + mOffY;

      if (inY<100)
         mSound2.play(0,0);
      else if (inY>200)
         mSound3.play(0,0);
      else
         mSound1.play(0,0);


      var me = this;
      haxe.Timer.delay( function() me.Remove(), 200 );
   }

   function Remove()
   {
      parent.removeChild(this);
   }


}



class Main extends nme.display.Sprite
{
   public function new()
   {
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

   public function onClick(inEvent:nme.events.MouseEvent)
   {
      addChild( new Bang( inEvent.stageX, inEvent.stageY ) );
   }

   public static function main()
   {
      new Main();
   }

}
