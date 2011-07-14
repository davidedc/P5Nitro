// from the samples/10-Masks directory of NME (Google Code)


import nme.events.MouseEvent;
import nme.display.InteractiveObject;
import nme.display.Sprite;
import nme.display.DisplayObject;
import nme.geom.Rectangle;

import nme.display.Sprite;
import nme.events.Event;
import nme.geom.Rectangle;
import nme.display.BitmapData;
import nme.display.Graphics;
import nme.Lib;
import nme.display.Shape;
import nme.text.TextField;
import nme.geom.Matrix;
import nme.events.MouseEvent;
import nme.filters.GlowFilter;
import nme.filters.BitmapFilter;


class Scrollbar extends Sprite
{
   var mThumbHeight:Float;
   var mPage:Float;
   var mHeight:Float;
   var mRange:Float;
   var mThumb:Sprite;
   var mRemoveFrom:DisplayObject;

   public function new(inWidth:Float, inHeight:Float, inRange:Float, inPage:Float)
   {
      super();
      var gfx = graphics;
      gfx.lineStyle(1,0x404040);
      gfx.beginFill(0xeeeeee);
      gfx.drawRect(0,0,inWidth,inHeight);

      mThumbHeight = inHeight * inPage / inRange;
      mRange = inRange;
      mHeight = inHeight;
      mPage = inPage;
      var thumb = new Sprite();
      var gfx = thumb.graphics;
      gfx.lineStyle(1,0x000000);
      gfx.beginFill(0xffffff);
      gfx.drawRect(0,0,inWidth,mThumbHeight);
      addChild(thumb);
      mThumb = thumb;

      thumb.addEventListener( MouseEvent.MOUSE_DOWN, thumbStart );
   }

   dynamic public function scrolled(inTo:Float)
   {
   }

   function onScroll(e:MouseEvent)
   {
      var denom = mHeight-mThumbHeight;
      if (denom>0)
      {
         var ratio = mThumb.y/denom;
         scrolled(ratio*mRange);
      }
   }

   function thumbStart(e:MouseEvent)
   {
      mRemoveFrom = stage;
      mThumb.addEventListener( MouseEvent.MOUSE_UP, thumbStop );
      mRemoveFrom.addEventListener( MouseEvent.MOUSE_UP, thumbStop );
      mRemoveFrom.addEventListener( MouseEvent.MOUSE_MOVE, onScroll );
      mThumb.startDrag(false, new Rectangle(0,0,0,mHeight-mThumbHeight));
   }
   function thumbStop(e:MouseEvent)
   {
      mThumb.stopDrag();
      mThumb.removeEventListener( MouseEvent.MOUSE_UP, thumbStop );
      mRemoveFrom.removeEventListener( MouseEvent.MOUSE_UP, thumbStop );
      mRemoveFrom.removeEventListener( MouseEvent.MOUSE_MOVE, onScroll );
   }
}




class Main extends Sprite
{
   var mask_obj:Sprite;

   public function new()
   {
      super();
      Lib.current.addChild(this);

          var window = new Sprite();
          addChild(window);

      var scrollbar = new Scrollbar(20, 404, 1024-400, 404*400/1024);
      scrollbar.x = 76;
      scrollbar.y = 38;
      addChild(scrollbar);
      scrollbar.scrolled = function(inTo:Float)
      {
            window.scrollRect = new Rectangle(0,inTo,440,400);
      };

      var gfx = graphics;
          gfx.lineStyle(1,0x000000);
          gfx.drawRect(98,38, 444, 404);
          //window.scrollRect = new Rectangle(0,0,440,400);
          window.x = 100;
          window.y = 40;
          //window.cacheAsBitmap = true;


      var bg = new Sprite();
      var gfx = bg.graphics;
      gfx.beginFill(0x808080);
      gfx.drawRect(0,0,1024,1024);
      window.addChild(bg);

      var line = new Sprite();
          var gfx = line.graphics;
          gfx.lineStyle(20,0xffffff);
          gfx.moveTo(20,20);
          gfx.lineTo(250,250);
          window.addChild(line);
          var glow = new GlowFilter(0x00ff00,1.0, 3,3, 1,1, false,false);
      var f = new Array<BitmapFilter>();
      f.push(glow);
      line.filters = f;

      var line = new Sprite();
          var gfx = line.graphics;
          gfx.lineStyle(5,0x000000);
          gfx.moveTo(5,5);
          gfx.lineTo(250,250);
          window.addChild(line);

      var tf:TextField = new TextField();
      tf.text = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, "
                  + "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ";
      tf.selectable = false;
      tf.wordWrap = true;
      tf.width = 150;
      tf.name = "text1";
      window.addChild(tf);
     
      mask_obj = new Sprite();
      mask_obj.graphics.beginFill(0xFF0000);
      mask_obj.graphics.drawCircle(0,0,40);
      mask_obj.graphics.endFill();
      mask_obj.name = "mask_obj";
      window.addChild(mask_obj);


      var mask_child = new Shape();
      var gfx = mask_child.graphics;
      gfx.beginFill(0x00ff00);
      gfx.drawRect(-60,-10,120,20);
      mask_obj.addChild(mask_child);

      window.mask = mask_obj;

      window.addEventListener(MouseEvent.MOUSE_DOWN, drag);
      window.addEventListener(MouseEvent.MOUSE_UP, noDrag);
      tf.x = 100;
      tf.y = 100;
      mask_obj.x = 100;
      mask_obj.y = 100;
   }

     function drag(event:MouseEvent):Void{
       mask_obj.startDrag();
   }
   function noDrag(event:MouseEvent):Void {
       mask_obj.stopDrag();
   }

     public static function main()
     {
          new Main();
     }


}
