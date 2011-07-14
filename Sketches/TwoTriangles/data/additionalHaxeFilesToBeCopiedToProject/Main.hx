import flash.display.Sprite;


class Main extends Sprite
{
   public function new()
   {
      super();
      flash.Lib.current.addChild(this);
      
      graphics.lineStyle( 1, 0xFF0000 );
      graphics.beginFill(0x0000FF, 1.0);
      graphics.moveTo( 70, 0 );
      graphics.lineTo( 20, 25 );
      graphics.lineTo( 70, 50 );
      graphics.lineTo( 20, 75 );
      graphics.lineTo( 70, 100 );
      graphics.endFill();
   }

   public static function main()
   {
      new Main();
   }
}
