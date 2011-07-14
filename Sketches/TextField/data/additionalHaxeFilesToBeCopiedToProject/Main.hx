import flash.display.MovieClip;
import flash.display.Sprite;

import flash.display.Bitmap;
import flash.display.BitmapData;

class Main extends MovieClip {
        public function new () {
                super();
               
                // retina display
                this.scaleX = 2.0;
                this.scaleY = 2.0;
               
                var r:Sprite = new Sprite();
                r.graphics.beginFill(0xaaaaff);
                r.graphics.drawRect(0,0,300,200);
                addChild(r);
               
                var i=0;
                var imax=10;
                for (i in 0...imax) {
                        var m=new MovieClip();
                       
                       
                        var p : flash.text.TextField = new flash.text.TextField();
                        p.text="Hello1234567 world!";
                       
                        // autosize doesn't seem to work quite right on the iPhone, so
                        // we put the whole screen size here for the time being
                        p.width = 320;

                        //p.autoSize = flash.text.TextFieldAutoSize.LEFT;
                              //       _text.defaultTextFormat = tf;
                              p.selectable = false;

p.border = true;
p.borderColor = 0xFF0000;

                        var ts = new flash.text.TextFormat();
                        //ts.color=0xFFFF00;
                        ts.size=40;
                        //ts.font = "Verdana";
                        ts.font = "AmericanTypewriter";
                        // here is a complete list of fonts
                        // supported in both iPhone 4.2 and iPad 4.2
                        // http://iosfonts.com/
                        p.setTextFormat(ts);
                        p.scaleX=2;
                        p.alpha=1-i/imax;
                       
                        /////////// CASE 1 - DRAW BY ADDING TEXTEDIT LAYER
                        //p.textColor=0x00FF0000; // if draw on TextField layer, this is red
                        //p.textColor=0x0000FF00; // if draw on TextField layer, this is green
                        //p.textColor=0x000000FF; // if draw on TextField layer, this is blue
                        //m.addChild(p);
                        /////////// END OF CASE 1 - DRAW BY ADDING TEXTEDIT LAYER
                       
                       
                        /////////// CASE 2- DRAW ON BITMAP AND THEN ADD BITMAP LAYER
                              //p.textColor=0x000000FF; // if you draw on a bitmap, then this is red
                              //p.textColor=0x0000FF00; // if you draw on a bitmap, then this is green
                              p.textColor=0x00FF0000; // if you draw on a bitmap, then this is blue
                              // You should try to make this bitmap as tighter to the text as possible,
                              // if you make it as large as the whole screen it's a waste of memory!
                             
                              // in this case we have to multiply the X by two
                              // cause the textField has a scalex of 2.
                              var bitmapData:BitmapData = new BitmapData(Std.int(p.textWidth*2), Std.int(p.height), true, 0x00000000);
                              //var bitmapData:BitmapData = new BitmapData(2000, 400, true, 0x00000000);
                              //var bitmapData:BitmapData = new BitmapData(271, Std.int(p.height), true, 0x00000000);
                             
                              trace("textfield width, height:" + p.width + ", "+p.height); // gives 100,100
                              trace("2 textfield width, height:" + p.textWidth + ", "+p.textHeight); // gives 270.5,4
                             
                              bitmapData.draw(p);
                              var bitmap:Bitmap = new Bitmap();
                              bitmap.bitmapData = bitmapData;                             
                              bitmap.smoothing = true;
                              m.addChild(bitmap);
                        /////////// END OF CASE 2- DRAW ON BITMAP AND THEN ADD BITMAP LAYER


                        var circle2:Sprite = new Sprite();
                        circle2.graphics.beginFill(0xFFCC00);
                        circle2.graphics.drawCircle(120, 40, 40);
                        m.addChild(circle2);
                        m.x=10*i;
                        m.y=10*i;
                        m.alpha=1-(i+1)/imax;
                        m.scaleX=(i+1)/imax;
                        m.scaleY=(i+1)/imax;
                       
                        //
                        addChild(m);
                       
                        // use my embedded font
                       
                }
               
               
        }
        public static function main() {
                var m:Main = new Main();
                flash.Lib.current.addChild(m);
        }
}
