class ApplicationMain
{
   public static function main()
   {
      nme.Lib.create(
           function(){ Main.main(); },
           200, 200,
           60,
           0xffffff,
             ( true   ? nme.Lib.HARDWARE  : 0) |
             ( true ? nme.Lib.RESIZABLE : 0),
          "P5NitroSketch",
          "null"
          );
   }

   public static function getAsset(inName:String):Dynamic
   {
      
      return null;
   }
}

