	// [ddc] based on
	// http://help.adobe.com/en_US/as3/mobile/WS948100b6829bd5a6-19cd3c2412513c24bce-8000.html
    import nme.display.Bitmap; 
    import nme.geom.ColorTransform;
     
    class ProcessingHaxeBitmapPool 
    { 
        private var MAX_VALUE:Int; 
        private var GROWTH_VALUE:Int; 
        private var counter:Int; 
        private var pool:Array<Bitmap>; 
        private var currentBitmap:Bitmap; 
  
		public function new() {
        }

        public function initialize( maxPoolSize:Int, growthValue:Int ):Void 
        { 
            MAX_VALUE = maxPoolSize; 
            GROWTH_VALUE = growthValue; 
            counter = maxPoolSize; 
             
            var i:Int = maxPoolSize; 
             
            pool = new Array<Bitmap>();
            while( --i > -1 ) 
                pool[i] = new Bitmap(null,nme.display.PixelSnapping.AUTO,true); 
        } 
         
        public function getBitmap():Bitmap 
        { 
            //trace("giving bitmap from pool - there are " + counter + " available");
            if ( counter > 0 ) {
				currentBitmap = pool[--counter]; 
				// a colorTransform "sticks" to a display list object,
				// so we need to clear it before we give the bitmap back
				// [todo] in theory you'd want to pool the colortransform objects
				// for another use instead of simply discarding them
				currentBitmap.transform.colorTransform = null;
				return currentBitmap; 
            }
                 
            var i:Int = GROWTH_VALUE; 
            while( --i > -1 ) 
                    pool.unshift ( new Bitmap(null,nme.display.PixelSnapping.AUTO,true) ); 
            counter = GROWTH_VALUE; 
            //trace("adding a new bitmap to the pool");
            return getBitmap();              
        } 
        
        public function disposeBitmap(disposedBitmap:Bitmap):Void { 
            pool[counter++] = disposedBitmap;
        } 

        public function disposeAllBitmaps():Void { 			
            counter = pool.length;              
        } 

    } 
