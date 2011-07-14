// author: JLM at justinfront
import flash.display.MovieClip;
import flash.display.Sprite;
import haxe.Timer;
import flash.Lib;

class Main
{   
    public static inline var RED: Int = 0xFF0000;
    private var _stage: MovieClip;
    private var _view_mc: Sprite;
    private var _wide: Int;
    private var _step: Int;
    private var _amplitude: Int;
    private var _timeStep: Int;
    private var _timer: Timer;
    private var _x: Int;
    private var _y: Float;
    private var _dAngle: Int;
    private var _radians: Float;
    private var _angleChange: Float;
   
    public function new(
                        wide_: Int,
                        step_: Int,
                        amplitude_: Int,
                        timeStep_: Int,
                        dAngle_: Int
                        )
    {  
        _wide = wide_;
        _step = step_;
        _amplitude = amplitude_;
        _timeStep = timeStep_;
        _dAngle = dAngle_;
        _stage = Lib.current;
        _radians = 0;
        _angleChange = _dAngle * Math.PI/360;
        init();
    }
   
    private function init():Void
    {
        createView();
        _view_mc.graphics.lineStyle( 0, RED, 1);
        _timer = new Timer( _timeStep );
        _timer.run = drawSine;
    }
   
    private function createView():Void
    {
        _view_mc = new Sprite();
        _view_mc.x = 10;
        _view_mc.y = 250;
        _stage.addChild( _view_mc );
       
    }

    public function drawSine():Void
    {
        if( (_x+=_step) > _wide )
        {
            _timer.stop();
        }
        _radians += _angleChange;
        _y = _amplitude * Math.sin( _radians );
        _view_mc.graphics.lineTo( _x, _y );
    }
   
    public static function main(): Void
    {  
        var wide:Int = 760;
        var step:Int = 3;
        var amplitude: Int = 200;
        var timeStep: Int = 1000;
        var dAngle: Int = 5;
        new Main( wide, step, amplitude, timeStep, dAngle );
    }

}
