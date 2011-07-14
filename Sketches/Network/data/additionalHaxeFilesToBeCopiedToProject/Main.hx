import flash.display.Sprite;
import flash.events.MouseEvent;
import flash.geom.Rectangle;
import flash.text.TextField;
import flash.text.TextFieldAutoSize;
import flash.events.Event;
import flash.Lib;
import flash.display.MovieClip;
import flash.net.URLRequest;

class Main {

     private var _stage: MovieClip;
     private var _carreRouge: Sprite;
    
     public function new( ){
          _stage = Lib.current;
          init();
     }
    
     private function init():Void {
          createView();
    
     }
    
     private function createView():Void {
          _carreRouge = new Sprite();
          _carreRouge.graphics.beginFill(0xFF0000);
          _carreRouge.graphics.drawRect(0, 0, 40, 40);
          _carreRouge.graphics.endFill();
          _stage.addChild(_carreRouge);
          _carreRouge.x = 100;
          _carreRouge.y = 100;
          _carreRouge.addEventListener(flash.events.MouseEvent.CLICK,goto);
     }
    
     private function goto(e:flash.events.MouseEvent): Void {
          trace("asynch connection start");
          var myURLLoader = new flash.net.URLLoader();
         
          myURLLoader.addEventListener("complete", function(_) {
               trace("Complete");
               trace("Data: "+ myURLLoader.data);
          } );
         
          // works with both ip address and dns lookup
          // but the one with the ip gives us a page
          // while the one with the site name gives back a redirect. Weird.
          //myURLLoader.load(new flash.net.URLRequest("http://66.102.7.104"));
          myURLLoader.load(new flash.net.URLRequest("http://www.google.com/"));          
     }
    
     public static function main(): Void {
       new Main( );
     }

}
