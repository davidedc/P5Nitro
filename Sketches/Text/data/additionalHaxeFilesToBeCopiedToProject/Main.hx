import nme.Lib;
import nme.events.MouseEvent;
import nme.events.Event;
import nme.display.DisplayObject;
import nme.display.IGraphicsData;
import nme.display.BitmapData;
import nme.display.Bitmap;
import nme.display.GradientType;
import nme.display.Sprite;
import nme.display.StageDisplayState;
import nme.geom.Matrix;

// from the samples/02-Text directory of NME (Google Code)

class Main extends Sprite
{
   public function new()
   {
   super();
   var text = new nme.text.TextField();
   text.x = 100;
   text.y = 100;
   text.text = "Hello !";
   Lib.stage.addChild(text);

   }

   public static function main()
   {
      new Main();
   }
}
