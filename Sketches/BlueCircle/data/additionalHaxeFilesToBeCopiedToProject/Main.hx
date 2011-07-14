import flash.display.MovieClip;
import flash.display.Sprite;
import flash.events.MouseEvent;
import flash.events.Event;

class BlueCircle extends MovieClip {
       
        public function new() {
                super();                              
                var circle1:Sprite = new Sprite();
                circle1.graphics.beginFill(0x0000FF);
                circle1.graphics.drawCircle(10, 10, 10);
                addChild(circle1);
        }
}


class Main extends MovieClip {
       
        public function new() {
                super();
                var r:Sprite = new Sprite();
                r.graphics.beginFill(0xaaaaff);
                r.graphics.drawRect(0,0,200,200);
                addChild(r);
        }
       
        function AddCircle(e:MouseEvent) {
                var newCircle:BlueCircle = new BlueCircle();
                addChild(newCircle);
                newCircle.x = mouseX;
                newCircle.y = mouseY;
        }
       
        public static function main() {
                var m:Main = new Main();
                m.addEventListener(MouseEvent.MOUSE_MOVE,m.AddCircle);
                flash.Lib.current.addChild(m);
        }
}
