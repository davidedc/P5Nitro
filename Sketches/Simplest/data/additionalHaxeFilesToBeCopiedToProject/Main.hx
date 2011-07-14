import flash.display.Sprite;


class Main extends Sprite
{
   public function new()
   {
      super();
      flash.Lib.current.addChild(this);

      var gfx = graphics;
      gfx.lineStyle(0x000000,2);
      gfx.beginFill(0xff0000);
      gfx.drawCircle(100,100,50);
      gfx.drawCircle(150,150,50);
   }

   public static function main()
   {
      new Main();
   }
}
