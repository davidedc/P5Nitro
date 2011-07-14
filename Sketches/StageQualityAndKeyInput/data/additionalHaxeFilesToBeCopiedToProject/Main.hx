
// from the samples/01-Simple directory of NME (Google Code)
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


class Main extends Sprite
{


public function new()
{
   super();
  
   // these two are for the retina display, if you do this you
   // don't have to change all the numbers in the program and the
   // vector drawings look crisp.
   // Oddly, the FPS indicator remains of the same exact size.
   //this.scaleX=2.0;
   //this.scaleY=2.0;
  
   Lib.current.addChild(this);
   Lib.current.addChild(new nme.display.FPS() );
   var sp = new Sprite();
   sp.graphics.beginFill(0,1);
   sp.graphics.drawCircle(50,50,50);
   sp.graphics.endFill();


   stage.frameRate = 30;
     
   var bd = new BitmapData(100,100,true,nme.display.BitmapData.createColor(0xcc,0xcccccc));
   bd.draw(sp);
     
   var bm = new Bitmap(bd);
   this.addChild(bm);
   bm.x = 100;


   var shape = new Sprite();
   var gfx = shape.graphics;
   gfx.lineStyle(1,0xff0000);
   gfx.beginFill(0xffffff);
   gfx.drawRect(0,0,20,40);
   shape.x = 100;
   shape.y = 100;
   nme.Lib.extraVariableToVerifyBuild = 20;
   shape.rotation = 10;
   addChild(shape);




   stage.addEventListener(nme.events.KeyboardEvent.KEY_DOWN, OnKey );


   stage.addEventListener(Event.ENTER_FRAME, function(_) { shape.rotation+=360/60/60; } );
   stage.addEventListener(MouseEvent.MOUSE_MOVE, function(e:MouseEvent) {
      trace("Hit : " + e.stageX + "," + e.stageY + " : " +
          shape.hitTestPoint( e.stageX, e.stageY, false ) );
   });
  
   trace("Stage size using stage.width and stage.height: " + Lib.current.stage.width + "," + Lib.current.stage.height );
   //trace("Stage size using stage.fullScreenWidth and stage.fullScreenHeight: " + stage.fullScreenWidth + "," + stage.fullScreenHeight );
   trace("Stage size using stage.stageWidth and stage.stageHeight: " + Lib.current.stage.stageWidth + "," + Lib.current.stage.stageHeight );
       


}


function OnKey(event)
{
   switch(event.charCode)
   {
       case "1".charCodeAt(0):
          stage.quality = nme.display.StageQuality.LOW;
       case "2".charCodeAt(0):
          stage.quality = nme.display.StageQuality.MEDIUM;
       case "3".charCodeAt(0):
          stage.quality = nme.display.StageQuality.HIGH;
       case "4".charCodeAt(0):
          stage.quality = nme.display.StageQuality.BEST;
       case "5".charCodeAt(0):
               stage.frameRate = 10;


       case "q".charCodeAt(0): nme.Lib.close();
       case "f".charCodeAt(0):
          stage.displayState = (stage.displayState==StageDisplayState.NORMAL) ?
              StageDisplayState.FULL_SCREEN : StageDisplayState.NORMAL;
   }
}




public static function main()
{
   new Main();
}


}
