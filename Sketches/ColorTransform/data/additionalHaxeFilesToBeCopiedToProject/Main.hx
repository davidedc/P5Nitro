// from the samples/11-ColorTransform directory of NME (Google Code)

#if !flash
import nme.display.Sprite;
import nme.events.Event;
import nme.geom.Rectangle;
import nme.display.BitmapData;
import nme.display.Graphics;
import nme.display.GradientType;
import nme.Lib;
import nme.display.Shape;
import nme.text.TextField;
import nme.geom.Matrix;
import nme.geom.ColorTransform;
import nme.events.MouseEvent;
import nme.geom.Transform;
#else
import flash.display.Sprite;
import flash.events.Event;
import flash.geom.Rectangle;
import flash.display.BitmapData;
import flash.display.Graphics;
import flash.display.GradientType;
import flash.Lib;
import flash.display.Shape;
import flash.text.TextField;
import flash.geom.Matrix;
import flash.geom.ColorTransform;
import flash.events.MouseEvent;
#end



class Main extends Sprite
{
   public function new()
   {
      super();
      Lib.current.addChild(this);

      var target:Sprite = new Sprite();
      draw(target);
      addChild(target);
      var data = nme.display.BitmapData.load("Image.jpg");
      var bmp = new nme.display.Bitmap(data);
      bmp.alpha = 0.5;
      bmp.x = 50;
      bmp.y = 50;
      target.addChild(bmp);
      target.alpha = 0.5;


      //target.useHandCursor = true;
      //target.buttonMode = true;
      target.addEventListener(MouseEvent.CLICK, clickHandler);
   }

   public function draw(sprite:Sprite)
   {
      var red = 0xFF0000;
      var green = 0x00FF00;
      var blue = 0x0000FF;
      var size = 100.0;
      var mat:Matrix = new Matrix();

      sprite.graphics.beginGradientFill(GradientType.LINEAR, [red, blue, green], [1, 0.5, 1], [0.0, 200, 255]);

      sprite.graphics.drawRect(0, 0, 100, 100);
   }

   public function clickHandler(event:MouseEvent)
   {
      var d:nme.display.DisplayObject = event.target;
      var t:Transform = d.transform;
      var rOffset = t.colorTransform.redOffset + 25;
      var bOffset = t.colorTransform.redOffset - 25;
      var a = d.alpha;
      t.colorTransform = new ColorTransform(1, 1, 1, a*0.9, rOffset, 0, bOffset, 0);
   }


   public static function main()
   {
      new Main();
   }
}
