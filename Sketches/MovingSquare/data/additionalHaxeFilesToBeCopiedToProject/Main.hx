import flash.display.MovieClip;
import flash.display.Sprite;
import flash.events.MouseEvent;
import flash.events.Event;

class Main extends MovieClip {
        var r : Sprite;
        var x_ori:Int;
        var y_ori:Int;
        var theta:Float;
        var cos_theta:Float;
        var sin_theta:Float;
       
        public function new() {
                super();
                x_ori=50;
                y_ori=50;
                theta =0.01;
                cos_theta = Math.cos(theta);
                sin_theta = Math.sin(theta);
                var background:Sprite = new Sprite ();
                background.graphics.beginFill(0xffaaaa);
                background.graphics.drawRect(0,0,200,200);
                addChild(background);
               
                r = new Sprite();
                r.graphics.beginFill(0xaaaaff);
                r.graphics.drawRect(40,40,20,20);
                addChild(r);
                r.addEventListener("enterFrame",move);
        }
       
        function move(e:Event) {
                var new_x = cos_theta * (e.target.x-x_ori) - sin_theta *(e.target.y-y_ori);
                var new_y = sin_theta * (e.target.x-x_ori) + cos_theta *(e.target.y-y_ori);
                e.target.x = new_x+x_ori;
                e.target.y = new_y+y_ori;
        }
       
        public static function main() {
                var m:Main = new Main();
                flash.Lib.current.addChild(m);
        }
}
