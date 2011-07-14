

class IPhoneMain
{
   function new()
   {
      // This will be found in the class path - "src" by default, but you can change the class
      //  name here, and the class path in the common.hxml
      Main.main();
   }


   public static function main ()
   {
      var w = 320;
      var h = 480;
      var fps = 60;
      var bgColor = 0xffffff;
      var flags = 
           nme.Lib.FULLSCREEN |
           nme.Lib.BORDERLESS |
           nme.Lib.RESIZABLE  |
           nme.Lib.HARDWARE   |
           nme.Lib.VSYNC      |
           0;
      var name = "iPhone Application";


      nme.Lib.create(function(){new IPhoneMain();},w,h,fps,bgColor,flags, name);
   }

}
   

