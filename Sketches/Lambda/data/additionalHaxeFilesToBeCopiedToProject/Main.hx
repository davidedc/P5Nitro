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


          // create a new IntHash
          // you can also omit the Type Parameter <String>, because
          // it's inferred through the first set operation
          var hash = new IntHash<String>();
                 
          hash.set(1, "One");
          hash.set(2, "Two");
          hash.set(3, "Three");
          hash.set(4, "Four");
          hash.set(5, "Five");
                 
          trace( hash.get(2) ); // Two
                 
          trace( hash.get(6) ); // null
                 
          trace( hash.exists(6) ); // false
                 
          trace( hash.exists(1) ); // true
         
          // iterate over the keys
          for ( key in hash.keys() ) {
                trace( key ); // unsorted order of 1,2,3,4,5
          }
                 
          // iterate over the elements
          for ( elem in hash) {
                trace( elem ); // unsorted order of One, Two, Three, Four, Five
          }
                 
                  // iterate by index
          for ( i in 1...Lambda.count ( hash ) + 1) {
                trace( hash.get( i )); // sorted order - One, Two, Three, Four, Five
          }
                
          // get element count
          trace( Lambda.count( hash ) ); // 5
                 
          // remove an element
          hash.remove(1);
                   
          // get element count again
          trace( Lambda.count( hash ) ); // 4

   }

   public static function main()
   {
      new Main();
   }
}
