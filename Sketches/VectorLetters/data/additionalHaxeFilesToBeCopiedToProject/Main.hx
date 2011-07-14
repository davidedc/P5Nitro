// author: JLM at Justinfront
import flash.display.MovieClip;
import flash.display.Sprite;
import flash.Lib;
import flash.events.MouseEvent;

class Main
{
    // vector representations of the letters
    private var _h: List<List<Float>>;
    private var _a: List<List<Float>>;
    private var _x: List<List<Float>>;
    private var _e: List<List<Float>>;

    private var _stage: MovieClip;
    private var _view_mc: Sprite;
    private var _currMouseX: Float;
    private var _currMouseY: Float;
   
    public function new()
    {
        _stage = Lib.current;
       
    // create 'list' structures to hold vector data
    createHaXeData();
       
    createView();
       
    // draw coordinates to screen as defined in this array of letters
    drawLetters( [ _h, _a, _x, _e ] );

    // when mouse moves map vector data based on new mouse position.
        _view_mc.addEventListener( MouseEvent.MOUSE_MOVE, repos );
    }
   
    private function repos( e: MouseEvent ):Void
    {
       _currMouseX = _view_mc.mouseX;
       _currMouseY = _view_mc.mouseY;
       drawLetters( [
                        Lambda.map( _h, reactToMouse ),
                        Lambda.map( _a, reactToMouse ),
                        Lambda.map( _x, reactToMouse ),
                        Lambda.map( _e, reactToMouse )
                    ]);
                   
    }
   
    // create new positions based on old via a mapping using mouse position
    private function reactToMouse( origPos: List<Float> ):List<Float>
    {
        var pos: List<Float> = new List();
        var _x: Float = origPos.first();
        var _y: Float = origPos.last();
        if(  _currMouseX > _x )
        {
            pos.add( _x - 100*Math.sqrt( Math.abs( _currMouseX - _x )/500 ) );
        }
        else
        {
            pos.add( _x + 100*Math.sqrt( Math.abs( _currMouseX - _x )/500 ) );
        }
        if(  _currMouseY > _y )
        {
            pos.add( _y - 100*Math.sqrt( Math.abs( _currMouseY - _y )/500 ) );
        }
        else
        {
            pos.add( _y + 100*Math.sqrt( Math.abs( _currMouseY - _y )/500 ) );
        }
        return pos;
    }
   
    private function createView():Void
    {
        _view_mc = new Sprite();
        _view_mc.x = 100;
        _view_mc.y = 100;
        _stage.addChild( _view_mc );
       
    }
    private function drawLetters( letters: Array<List<List<Float>>> ):Void
    {
        _view_mc.graphics.clear();
    // draw a background
        _view_mc.graphics.beginFill(0xFFD541,1);
        _view_mc.graphics.moveTo(-70,-10);
        _view_mc.graphics.lineTo(350,-10);
        _view_mc.graphics.lineTo(350,170);
        _view_mc.graphics.lineTo(-70,170);

    // draw each letter
        for( aLetter in letters )
        {
            drawALetter( aLetter );
        }
    }
   
    private function drawALetter( letter: List<List<Float>> ):Void
    {
       
        _view_mc.graphics.beginFill(0xFD7D00,100);
        _view_mc.graphics.lineStyle(0,0xFD7D00, 0); 
        var pos:List<Float> = letter.first();
        _view_mc.graphics.moveTo( pos.first(), pos.last() );
       
        for( pos in letter )
        {
            _view_mc.graphics.lineTo( pos.first(), pos.last() );
        }
       
    }
   
    public static function main(): Void { new Main(); }
   
    // Raw data ( created from MovieClip instance positions using traces in flash details not shown )
    // The example data is not important and in reality may come from XML rather than hard coded.
    private function createHaXeData():Void
    {
        _h = new List();
        _a = new List();
        _x = new List();
        _e = new List();
       
    // temp store of x and y coordinates as a list added to a list of points defining a letter
        var pos: List<Float>;
        pos = new List();
        pos.add(32.2);//x
        pos.add(46.35);//y
        _h.add( pos );
        pos = new List();
        pos.add(44.3);
        pos.add(46.6);
        _h.add( pos );
        pos = new List();
        pos.add(44.5);
        pos.add(73.35);
        _h.add( pos );
        pos = new List();
        pos.add(71.5);
        pos.add(73.35);
        _h.add( pos );
        pos = new List();
        pos.add(71.95);
        pos.add(46.6);
        _h.add( pos );
        pos = new List();
        pos.add(84.05);
        pos.add(46.6);
        _h.add( pos );
        pos = new List();
        pos.add(83.6);
        pos.add(114.9);
        _h.add( pos );
        pos = new List();
        pos.add(71.7);
        pos.add(115.15);
        _h.add( pos );
        pos = new List();
        pos.add(71);
        pos.add(84.5);
        _h.add( pos );
        pos = new List();
        pos.add(44.75);
        pos.add(84.3);
        _h.add( pos );
        pos = new List();
        pos.add(44.3);
        pos.add(115.15);
        _h.add( pos );
        pos = new List();
        pos.add(32.4);
        pos.add(114.9);
        _h.add( pos );
        pos = new List();
        pos.add(98.9);
        pos.add(67.4);
        _a.add( pos );
        pos = new List();
        pos.add(107.35);
        pos.add(64.4);
        _a.add( pos );
        pos = new List();
        pos.add(119.7);
        pos.add(64.4);
        _a.add( pos );
        pos = new List();
        pos.add(127.45);
        pos.add(66.95);
        _a.add( pos );
        pos = new List();
        pos.add(132.95);
        pos.add(73.35);
        _a.add( pos );
        pos = new List();
        pos.add(134.75);
        pos.add(81.55);
        _a.add( pos );
        pos = new List();
        pos.add(135.2);
        pos.add(103.5);
        _a.add( pos );
        pos = new List();
        pos.add(136.8);
        pos.add(109.65);
        _a.add( pos );
        pos = new List();
        pos.add(138.85);
        pos.add(111.7);
        _a.add( pos );
        pos = new List();
        pos.add(134.55);
        pos.add(115.15);
        _a.add( pos );
        pos = new List();
        pos.add(129.05);
        pos.add(115.35);
        _a.add( pos );
        pos = new List();
        pos.add(126.55);
        pos.add(113.05);
        _a.add( pos );
        pos = new List();
        pos.add(124.95);
        pos.add(109.9);
        _a.add( pos );
        pos = new List();
        pos.add(120.15);
        pos.add(113.75);
        _a.add( pos );
        pos = new List();
        pos.add(113.3);
        pos.add(115.8);
        _a.add( pos );
        pos = new List();
        pos.add(105.75);
        pos.add(115.35);
        _a.add( pos );
        pos = new List();
        pos.add(98.2);
        pos.add(111.7);
        _a.add( pos );
        pos = new List();
        pos.add(93.85);
        pos.add(104.4);
        _a.add( pos );
        pos = new List();
        pos.add(94.1);
        pos.add(95.5);
        _a.add( pos );
        pos = new List();
        pos.add(98.45);
        pos.add(87.95);
        _a.add( pos );
        pos = new List();
        pos.add(105.3);
        pos.add(83.85);
        _a.add( pos );
        pos = new List();
        pos.add(112.15);
        pos.add(81.8);
        _a.add( pos );
        pos = new List();
        pos.add(118.55);
        pos.add(81.55);
        _a.add( pos );
        pos = new List();
        pos.add(123.8);
        pos.add(82.45);
        _a.add( pos );
        pos = new List();
        pos.add(121.3);
        pos.add(76.5);
        _a.add( pos );
        pos = new List();
        pos.add(112.85);
        pos.add(73.8);
        _a.add( pos );
        pos = new List();
        pos.add(104.4);
        pos.add(75.15);
        _a.add( pos );
        pos = new List();
        pos.add(102.8);
        pos.add(76.05);
        _a.add( pos );
        pos = new List();
        pos.add(99.1);
        pos.add(67.4);
        _a.add( pos );
        pos = new List();
        pos.add(123.35);
        pos.add(91.6);
        _a.add( pos );
        pos = new List();
        pos.add(114.45);
        pos.add(90.9);
        _a.add( pos );
        pos = new List();
        pos.add(106.65);
        pos.add(94.35);
        _a.add( pos );
        pos = new List();
        pos.add(106);
        pos.add(103);
        _a.add( pos );
        pos = new List();
        pos.add(112.85);
        pos.add(106);
        _a.add( pos );
        pos = new List();
        pos.add(118.75);
        pos.add(105.75);
        _a.add( pos );
        pos = new List();
        pos.add(122.4);
        pos.add(102.1);
        _a.add( pos );
        pos = new List();
        pos.add(123.55);
        pos.add(96.4);
        _a.add( pos );
        pos = new List();
        pos.add(123.3);
        pos.add(91.8);
        _a.add( pos );
        pos = new List();
        pos.add(143.65);
        pos.add(46.35);
        _x.add( pos );
        pos = new List();
        pos.add(156.25);
        pos.add(46.35);
        _x.add( pos );
        pos = new List();
        pos.add(170.65);
        pos.add(69.65);
        _x.add( pos );
        pos = new List();
        pos.add(185.25);
        pos.add(46.35);
        _x.add( pos );
        pos = new List();
        pos.add(197.6);
        pos.add(46.35);
        _x.add( pos );
        pos = new List();
        pos.add(177.05);
        pos.add(79.95);
        _x.add( pos );
        pos = new List();
        pos.add(198.75);
        pos.add(114.9);
        _x.add( pos );
        pos = new List();
        pos.add(185.7);
        pos.add(115.15);
        _x.add( pos );
        pos = new List();
        pos.add(170.4);
        pos.add(90.45);
        _x.add( pos );
        pos = new List();
        pos.add(154.9);
        pos.add(115.35);
        _x.add( pos );
        pos = new List();
        pos.add(142.1);
        pos.add(114.9);
        _x.add( pos );
        pos = new List();
        pos.add(164.25);
        pos.add(79.95);
        _x.add( pos );
        pos = new List();
        pos.add(143.7);
        pos.add(46.35);
        _x.add( pos );
        pos = new List();
        pos.add(212);
        pos.add(69.2);
        _e.add( pos );
        pos = new List();
        pos.add(222.75);
        pos.add(64.2);
        _e.add( pos );
        pos = new List();
        pos.add(233.95);
        pos.add(64.65);
        _e.add( pos );
        pos = new List();
        pos.add(243.75);
        pos.add(69.2);
        _e.add( pos );
        pos = new List();
        pos.add(249.95);
        pos.add(78.8);
        _e.add( pos );
        pos = new List();
        pos.add(250.6);
        pos.add(90.45);
        _e.add( pos );
        pos = new List();
        pos.add(250.6);
        pos.add(92.95);
        _e.add( pos );
        pos = new List();
        pos.add(214.55);
        pos.add(93.45);
        _e.add( pos );
        pos = new List();
        pos.add(218.2);
        pos.add(102.1);
        _e.add( pos );
        pos = new List();
        pos.add(228);
        pos.add(106.2);
        _e.add( pos );
        pos = new List();
        pos.add(235.55);
        pos.add(105.1);
        _e.add( pos );
        pos = new List();
        pos.add(241.05);
        pos.add(102.1);
        _e.add( pos );
        pos = new List();
        pos.add(245.6);
        pos.add(110.8);
        _e.add( pos );
        pos = new List();
        pos.add(234.4);
        pos.add(115.35);
        _e.add( pos );
        pos = new List();
        pos.add(222.05);
        pos.add(115.6);
        _e.add( pos );
        pos = new List();
        pos.add(212);
        pos.add(111.7);
        _e.add( pos );
        pos = new List();
        pos.add(204.7);
        pos.add(103);
        _e.add( pos );
        pos = new List();
        pos.add(202.2);
        pos.add(93.45);
        _e.add( pos );
        pos = new List();
        pos.add(203.1);
        pos.add(82.9);
        _e.add( pos );
        pos = new List();
        pos.add(206.55);
        pos.add(75.15);
        _e.add( pos );
        pos = new List();
        pos.add(212);
        pos.add(69);
        _e.add( pos );
        pos = new List();
        pos.add(239.2);
        pos.add(84.3);
        _e.add( pos );
        pos = new List();
        pos.add(236);
        pos.add(76.75);
        _e.add( pos );
        pos = new List();
        pos.add(227.8);
        pos.add(74);
        _e.add( pos );
        pos = new List();
        pos.add(219.3);
        pos.add(76.75);
        _e.add( pos );
        pos = new List();
        pos.add(215);
        pos.add(84.3);
        _e.add( pos );
        pos = new List();
        pos.add(223.2);
        pos.add(84.3);
        _e.add( pos );
        pos = new List();
        pos.add(239.2);
        pos.add(84.3);
        _e.add( pos );
       
    }

}
