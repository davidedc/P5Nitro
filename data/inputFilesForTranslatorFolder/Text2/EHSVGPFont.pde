          class EHSVGPFont {
            
            PGraphics whichPGraphicsToDrawOn;
            int parsingPosition;
            int numberOfGlyphs;
            //int textColor;
            public int ascentFromFile;
            public int descentFromFile;
            public int ascentPlusDescentFromFile;

            public float ascent;
            public float descent;
            public float ascentPlusDescent;
            public int ascentAsInt;
            public int descentAsInt;
            public int ascentPlusDescentAsInt;
            //float drawingSize;
            //EHSVGGlyph[] allTheGlyphs;
            ArrayList allTheGlyphs;
            ArrayList allTheGlyphsBitmaps;
            String theFileName;
            String fontFileContents;
            float fontScale;
            
            EHSVGPFont() {
              parsingPosition = 0;
              numberOfGlyphs = 0;
              allTheGlyphs = new ArrayList(); // if you know the type of this array put it here > EHSVGGlyph
              allTheGlyphsBitmaps = new ArrayList(); // if you know the type of this array put it here > PGraphics
            }

            void setFontScale(float theFontScale) {
              fontScale = theFontScale;
              ascent = ascentFromFile * fontScale;
              descent = descentFromFile * fontScale;
              ascentPlusDescent = ascent + descent;
              ascentAsInt = int(ascent);
              descentAsInt = int(descent);
              ascentPlusDescentAsInt = int(ascentPlusDescent);
            }

            // ouch, when you paint an image over a transparent,
            // bitmap made with this, the transparent pixels
            // become opqaue. This is some bad processing
            // mojo...
            /*
            void makeBitmapTransparent(PGraphics theBitmap) {
              theBitmap.loadPixels();
              int pgWidth = int(theBitmap.width);
              int pgHeight = int(theBitmap.height);
              for (int x = 0; x < pgWidth; x++) {
                // Loop through every pixel row
                for (int y = 0; y < pgHeight; y++) {
                  // Use the formula to find the 1D location
                  int loc = x + y * pgWidth;
                    theBitmap.pixels[loc] =  color(255,0,255,0); 
                }
              }
              theBitmap.updatePixels();
            }
            */

            void putTextGraphics(EHSVGTextGraphics theEHSVGTextGraphics, int posx, int posy) {
              if (HighDpiScreenManager.dpiScaleFactor == 1){
                image(theEHSVGTextGraphics.theTextPGraphics, posx, posy + int(ascent * (-theEHSVGTextGraphics.writingScale + 1))  - ascentAsInt );
              }
              else if (HighDpiScreenManager.dpiScaleFactor == 2){
                scale(0.5);
                image(theEHSVGTextGraphics.theTextPGraphics, posx * 2, (posy + int(ascent * (-theEHSVGTextGraphics.writingScale + 1)) - ascentAsInt)* 2);
                scale(2);
              }
            }
            
            void putTextGraphics(EHSVGTextGraphics theEHSVGTextGraphics, int posx, int posy, color theTextColor) {
              // we could simply use tint(textColor) here
              // but it wouldn't work in haxe because in haxe
              // color is just an integer, so it would tint of a greyscale!
              int originalTint = 0;
              boolean tintWasOriginallyOn = g.tint;
              if (tintWasOriginallyOn) {
                originalTint = g.tintColor;
              }
              tint(red(theTextColor), green(theTextColor), blue(theTextColor), alpha(theTextColor));

              // draw the text
              putTextGraphics( theEHSVGTextGraphics ,  posx,  posy);
               
              // put back the tint to what it was,
              // if there was a tint, that is
              if (tintWasOriginallyOn) {
                 tint(red(originalTint), green(originalTint), blue(originalTint), alpha(originalTint));                
              }
              else noTint();             
            }
            
            void putpGraphicsTextGraphics(PGraphics pg, int posx, int posy) {
              if (HighDpiScreenManager.dpiScaleFactor == 1){
                image(pg, posx, posy - ascentAsInt);
              }
              else if (HighDpiScreenManager.dpiScaleFactor == 2){
                scale(0.5);
                image(pg, posx * 2, (posy - ascentAsInt)* 2);
                scale(2);
              }
            }            

            int cacheSpecificCharacter(String glyphID) {
              //println("cacheSpecificCharacter with glyphID: " + glyphID);
              int k = parseSpecificCharacter(glyphID);
              
              //drawingSize = theDrawingSize;
              if (HighDpiScreenManager.dpiScaleFactor == 1) {
              //println("font scale: " + fontScale);
              //println("k: " + k);
              //println("horizadv: " + ((EHSVGGlyph)allTheGlyphs.get(k)).horizAdv );
                whichPGraphicsToDrawOn = createGraphics(int(((EHSVGGlyph)allTheGlyphs.get(k)).horizAdv), ascentPlusDescentAsInt , P2D );
              }
              else if (HighDpiScreenManager.dpiScaleFactor == 2) {
                whichPGraphicsToDrawOn = createGraphics(2 * int(((EHSVGGlyph)allTheGlyphs.get(k)).horizAdv ), 2 * ascentPlusDescentAsInt , P2D );
              }
              whichPGraphicsToDrawOn.beginDraw();
              whichPGraphicsToDrawOn.background(0);
              whichPGraphicsToDrawOn.fill(255);
              if (HighDpiScreenManager.dpiScaleFactor == 1) {
                drawGlyphNumber(k, 0 , ascentAsInt , 1);
              }
              else if (HighDpiScreenManager.dpiScaleFactor == 2) {
                drawGlyphNumber(k, 0 , 2.0 * ascentAsInt , 2.0 );
              }
              whichPGraphicsToDrawOn.endDraw();
              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();
              allTheGlyphsBitmaps.add(whichPGraphicsToDrawOn);
              return allTheGlyphsBitmaps.size() - 1;
            }
            
            void cacheAllBitmaps() {
              // you might have cahed some other bitmaps before,
              // so we clean up everything here
              
              //println("caching all the bitmaps");
              
              if(allTheGlyphs.size() != 0) {
                //println("creating new arrylist");
                allTheGlyphs = new ArrayList(); // if you know the type of this array put it here > EHSVGGlyph
                allTheGlyphsBitmaps = new ArrayList(); // if you know the type of this array put it here > PGraphics
              }

              // we could be smarter and parse only the body because
              // the header is parsed when you call "loadFont"
              // but it's not worth it
              //println("parsing file");
              parseEntireFile();
                            
              //drawingSize = fontScale;
              //println("there are " + numberOfGlyphs + " glyphs in the file");
              for (int k = 0; k < numberOfGlyphs;k++){
                //whichPGraphicsToDrawOn = createGraphics(int(((EHSVGGlyph)allTheGlyphs.get(k)).horizAdv * drawingSize)*10,100, P2D );
                //println("caching glyph " + k);
                if (HighDpiScreenManager.dpiScaleFactor == 1) {
                  whichPGraphicsToDrawOn = createGraphics(int(((EHSVGGlyph)allTheGlyphs.get(k)).horizAdv ), ascentPlusDescentAsInt , P2D );
                }
                else if (HighDpiScreenManager.dpiScaleFactor == 2) {
                  whichPGraphicsToDrawOn = createGraphics(2 * int(((EHSVGGlyph)allTheGlyphs.get(k)).horizAdv ), 2 * ascentPlusDescentAsInt , P2D );
                }
                //println("drawing glyph " + k);
                whichPGraphicsToDrawOn.beginDraw();
                // [todo]: the default initialisation of the background and fill of a pGraphics
                // object is not correct
                whichPGraphicsToDrawOn.background(0);
                //whichPGraphicsToDrawOn.stroke(255);
                whichPGraphicsToDrawOn.fill(255);
                //whichPGraphicsToDrawOn.line(0,0,50,50);
                if (HighDpiScreenManager.dpiScaleFactor == 1){
                  drawGlyphNumber(k, 0 , ascentAsInt , 1);
                }
                else if (HighDpiScreenManager.dpiScaleFactor == 2){
                  drawGlyphNumber(k, 0 , 2 * ascentAsInt , 2.0 );
                }
                //image(whichPGraphicsToDrawOn,50,50);
                whichPGraphicsToDrawOn.endDraw();


              //println("start of background removal");
              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();
              //println("end of background removal");

              /*
              whichPGraphicsToDrawOn.loadPixels();
              for (int x = 0; x < pgWidth; x++) {
                // Loop through every pixel row
                for (int y = 0; y < pgHeight; y++) {
                  // Use the formula to find the 1D location
                  int loc = x + y * pgWidth;
                    int r = int(red(whichPGraphicsToDrawOn.pixels[loc]));
                    //int g = int(green(whichPGraphicsToDrawOn.pixels[loc]));
                    //int b = int(blue(whichPGraphicsToDrawOn.pixels[loc]));
                    //int a = int(alpha(whichPGraphicsToDrawOn.pixels[loc]));
                    whichPGraphicsToDrawOn.pixels[loc] =  color(255,r); 
                }
              }
              // [ddc] note, the opengl implementation doesn't work if this is off
              // one possible way to solve this is by having updatePixels to check whether
              // a loadpixels was done in this draw loop. If not, then
              // it should do nothing.
              whichPGraphicsToDrawOn.updatePixels();
              */

                //println("adding glyph to bitmap vector");
                allTheGlyphsBitmaps.add(whichPGraphicsToDrawOn);
                }
                //println("cached all the glyphs");
            }
            
            // this would be supposed to work
            // but unfortunately the tint makes it so the letters bitmaps paint a
            // black background on the graphics you created
            // for some mysterious reasons
            /*
            PGraphics createOpaqueGraphicsWithBitmapText(String theText, float theDrawingSize, color theBackgroundColor,  color theForegroundColor) {
              drawingSize = theDrawingSize;
              Rectangle sizeOfWrite = sizeOfString(theText);
              PGraphics pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
              pg.background(theBackgroundColor);
              // you can make the bitmap transparent, but unfortunately when
              // you paint the bitmaps of the letters over it the transparent
              // pixels become opaque, so there is no point...
              //makeBitmapTransparent(pg);
              tint(theForegroundColor);
              drawTextOnPGraphicsFromCachedBitmaps(pg, theText);
              return pg;
            }
            */

            EHSVGTextGraphics createEHSVGTextGraphicsFromCachedBitmaps(String theText) {
              return createEHSVGTextGraphicsFromCachedBitmaps(theText, 1.0);
            }

            EHSVGTextGraphics createEHSVGTextGraphicsFromCachedBitmaps(String theText, float theDrawingSize) {
              //drawingSize = theDrawingSize;
              java.awt.Rectangle sizeOfWrite = sizeOfString(theText, theDrawingSize);
              //println("size of >" + theText + "< = " + sizeOfWrite.width);
              PGraphics pg = null;
              if (HighDpiScreenManager.dpiScaleFactor == 1) {
                pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);            
              }
              else if (HighDpiScreenManager.dpiScaleFactor == 2) {
                pg = createGraphics(2 * sizeOfWrite.width, 2 * sizeOfWrite.height, P2D);            
              }
              drawTextOnPGraphicsFromCachedBitmaps(pg,  theText, 0, 0, theDrawingSize);
              EHSVGTextGraphics eHSVGTextGraphics = new EHSVGTextGraphics();
              eHSVGTextGraphics.theTextPGraphics = pg;
              eHSVGTextGraphics.writingScale = theDrawingSize;
              eHSVGTextGraphics.width = sizeOfWrite.width;
              eHSVGTextGraphics.height = sizeOfWrite.height;
              return eHSVGTextGraphics;
            }


            float drawTextOnPGraphicsFromCachedBitmaps(PGraphics thePGraphics, String theText, float posX, float posY, float theDrawingSize) {
              float advancement = 0;
              whichPGraphicsToDrawOn = thePGraphics;
                            
              
              //whichPGraphicsToDrawOn.smooth();
              whichPGraphicsToDrawOn.beginDraw();
              //whichPGraphicsToDrawOn.smooth();
              //whichPGraphicsToDrawOn.background(255,0,0,0);
              //whichPGraphicsToDrawOn.noStroke();
              //whichPGraphicsToDrawOn.stroke(255);

              for (int i = 0; i < theText.length();i++){
                String theGlyphId = ""+theText.charAt(i);
                
                if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                else if (theGlyphId.equals("&")) theGlyphId = "&amp;";
                else if (theGlyphId.equals("'")) theGlyphId = "&amp;";
                else if (theGlyphId.equals(">")) theGlyphId = "&gt;";
                else if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                
                // this function will handle the retina display scaling
                float lastLetterAdv = drawGlyphOnPGraphicsFromCachedBitmaps(theGlyphId, posX + advancement , posY, theDrawingSize); 
                advancement += lastLetterAdv;
                //System.out.println("advancement of " + theGlyphId + " is  " + lastLetterAdv + " so advancement is now " + advancement);
              }
              whichPGraphicsToDrawOn.endDraw();
              
              // Now as the last thing let's remove the black background
              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();

              return advancement;
            }

            // this is the best method for drawing changing text
            float drawTextFromCachedBitmaps(String theText, float posX, float posY , color theTextColor, float scaleFactor) {
              // we could simply use tint(textColor) here 
              // but it wouldn't work in haxe because in haxe
              // color is just an integer, so it would tint of a greyscale!
              int originalTint = 0;
              boolean tintWasOriginallyOn = g.tint;
              if (tintWasOriginallyOn) {
                originalTint = g.tintColor;
              }
              tint(red(theTextColor), green(theTextColor), blue(theTextColor), alpha(theTextColor));

              // draw the text and keep the float
              //if (scaleFactor != 1) {
              //  pushMatrix();
                scale(scaleFactor);
              //}
              float valueToBeReturned = drawTextFromCachedBitmaps( theText ,  posX / scaleFactor,  posY /scaleFactor );
                scale(1/scaleFactor);
              //if (scaleFactor != 1) popMatrix();
               
              // put back the tint to what it was,
              // if there was a tint, that is
              if (tintWasOriginallyOn) {
                 tint(red(originalTint), green(originalTint), blue(originalTint), alpha(originalTint));                
              }
              else noTint();
             
             return valueToBeReturned * scaleFactor;
            }


            // this is the best method for drawing changing text
            // note that we could just call 
            // drawTextFromCachedBitmaps( theText,  posX,  posY ,  theTextColor,  1);
            // but we don't because that one does a scale/unscale operation that we want to avoid
            

            float drawTextFromCachedBitmaps(String theText, float posX, float posY , color theTextColor) {
              // we could simply use tint(textColor) here 
              // but it wouldn't work in haxe because in haxe
              // color is just an integer, so it would tint of a greyscale!
              int originalTint = 0;
              boolean tintWasOriginallyOn = g.tint;
              if (tintWasOriginallyOn) {
                originalTint = g.tintColor;
              }
              tint(red(theTextColor), green(theTextColor), blue(theTextColor), alpha(theTextColor));

              // draw the text and keep the float
              float valueToBeReturned = drawTextFromCachedBitmaps( theText,  posX ,  posY  );
               
              // put back the tint to what it was,
              // if there was a tint, that is
              if (tintWasOriginallyOn) {
                 tint(red(originalTint), green(originalTint), blue(originalTint), alpha(originalTint));                
              }
              else noTint();
             
             return valueToBeReturned ;
            }

            float drawTextFromCachedBitmaps(String theText, float posX, float posY ) {
              float advancement = 0;
              
              //whichPGraphicsToDrawOn.smooth();
              //whichPGraphicsToDrawOn.smooth();
              //whichPGraphicsToDrawOn.background(255,0,0,0);
              //whichPGraphicsToDrawOn.noStroke();
              //whichPGraphicsToDrawOn.stroke(255);

              for (int i = 0; i < theText.length();i++){
                String theGlyphId = ""+theText.charAt(i);
                
                if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                else if (theGlyphId.equals("&")) theGlyphId = "&amp;";
                else if (theGlyphId.equals("'")) theGlyphId = "&amp;";
                else if (theGlyphId.equals(">")) theGlyphId = "&gt;";
                else if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                

                float lastLetterAdv = drawGlyphOnMainScreenFromCachedBitmaps(theGlyphId, posX + advancement , posY); 
                advancement += lastLetterAdv;
                //println("advancement of " + theGlyphId + " is  " + lastLetterAdv + " so advancement is now " + advancement);
              }

              return advancement;
            }


            EHSVGTextGraphics createEHSVGTextGraphicsWithVectorText(String theText, float theDrawingSize) {
              //drawingSize = theDrawingSize;
              java.awt.Rectangle sizeOfWrite = sizeOfString(theText, theDrawingSize);
              //println("size of >" + theText + "< = " + sizeOfWrite.width);
              PGraphics pg = null;
              if (HighDpiScreenManager.dpiScaleFactor == 1) {
                pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);            
                drawTextOnPGraphicsFromVectors(pg, theText, 0, int(ascent*theDrawingSize) , theDrawingSize);
              }
              else if (HighDpiScreenManager.dpiScaleFactor == 2) {
                pg = createGraphics(2 * sizeOfWrite.width, 2 * sizeOfWrite.height, P2D);            
                drawTextOnPGraphicsFromVectors(pg, theText, 0, 2 * int(ascent*theDrawingSize) , 2.0 * theDrawingSize);
              }
              
              EHSVGTextGraphics eHSVGTextGraphics = new EHSVGTextGraphics();
              eHSVGTextGraphics.theTextPGraphics = pg;
              eHSVGTextGraphics.writingScale = theDrawingSize;
              eHSVGTextGraphics.width = sizeOfWrite.width;
              eHSVGTextGraphics.height = sizeOfWrite.height;
              return eHSVGTextGraphics;
            }

            

            float drawTextOnPGraphicsFromVectors(PGraphics thePGraphics, String theText, float posX, float posY, float theDrawingSize) {
              //drawingSize = theDrawingSize;
              float advancement = 0;
              whichPGraphicsToDrawOn = thePGraphics;
              
              //whichPGraphicsToDrawOn.smooth();
              whichPGraphicsToDrawOn.beginDraw();
              //whichPGraphicsToDrawOn.smooth();
              whichPGraphicsToDrawOn.background(0);
              //whichPGraphicsToDrawOn.noStroke();
              whichPGraphicsToDrawOn.stroke(0);
              for (int i = 0; i < theText.length();i++){
                String theGlyphId = ""+theText.charAt(i);
                
                if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                else if (theGlyphId.equals("&")) theGlyphId = "&amp;";
                else if (theGlyphId.equals("'")) theGlyphId = "&amp;";
                else if (theGlyphId.equals(">")) theGlyphId = "&gt;";
                else if (theGlyphId.equals("<")) theGlyphId = "&lt;";

                advancement += drawGlyph(theGlyphId, posX + advancement , posY, theDrawingSize);
              }
              whichPGraphicsToDrawOn.endDraw();
              
              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();


              return advancement;
            }

            void drawGlyphNumberOnPGraphicsFromCachedBitmaps(int theGlyphNumber, float posX, float posY, float theDrawingSize) {
              
              whichPGraphicsToDrawOn.translate(posX, posY);
              

              //if (theDrawingSize != 1) {
                //whichPGraphicsToDrawOn.pushMatrix();
                whichPGraphicsToDrawOn.scale(theDrawingSize);
              //}

              //System.out.println("drawing glyph number " + theGlyphNumber);
              //whichPGraphicsToDrawOn.tint(red(textColor), green(textColor), blue(textColor), alpha(textColor));
              whichPGraphicsToDrawOn.image((PGraphics)allTheGlyphsBitmaps.get(theGlyphNumber),0,0);

                whichPGraphicsToDrawOn.scale(1/theDrawingSize);
              //if (theDrawingSize != 1) whichPGraphicsToDrawOn.popMatrix();

              whichPGraphicsToDrawOn.translate(-posX, -posY);
            }

            void drawGlyphNumberOnMainScreenFromCachedBitmaps(int theGlyphNumber, float posX, float posY) {
              
              translate(posX, posY);
                // svg works in cartesian coordinates, while in
                // processing the origin is in the top left corner
                
                //whichPGraphicsToDrawOn.scale(1,-1);
                //whichPGraphicsToDrawOn.scale(drawingSize,drawingSize);

                //((EHSVGGlyph)allTheGlyphs.get(theGlyphNumber)).commandParserAndDrawer.executeCommand(whichPGraphicsToDrawOn, posX,posY);
                //System.out.println("drawing glyph number " + theGlyphNumber);
                
                //tint(red(textColor), green(textColor), blue(textColor), alpha(textColor));
                //image((PGraphics)allTheGlyphsBitmaps.get(theGlyphNumber),0,0);
                putpGraphicsTextGraphics((PGraphics)allTheGlyphsBitmaps.get(theGlyphNumber),0,0);
                //whichPGraphicsToDrawOn.scale(1/drawingSize,1/drawingSize);
                //whichPGraphicsToDrawOn.scale(1,-1);
                translate(-posX, -posY);
            }

            void drawGlyphNumber(int theGlyphNumber, float posX, float posY, float drawingSize) {
              drawingSize *= fontScale;
              
                whichPGraphicsToDrawOn.translate(posX, posY);
                // svg works in cartesian coordinates, while in
                // processing the origin is in the top left corner
                
                // [todo] these two lines can be made into one
                whichPGraphicsToDrawOn.scale(1,-1);
                whichPGraphicsToDrawOn.scale(drawingSize,drawingSize);

                ((EHSVGGlyph)allTheGlyphs.get(theGlyphNumber)).commandParserAndDrawer.executeCommand(whichPGraphicsToDrawOn, posX,posY);
                whichPGraphicsToDrawOn.scale(1/drawingSize,1/drawingSize);
                whichPGraphicsToDrawOn.scale(1,-1);
                whichPGraphicsToDrawOn.translate(-posX, -posY);
            }

            java.awt.Rectangle sizeOfString(String theText, float  theDrawingSize) {
              // todo note that this function is also called from the
              // vector-drawing methods, and in that case you might
              // not want to load the bitmap of the letter in cache
              // so we should make some check of some king and avoid that
              // it unnecessary
              
              float advancement = 0;
              boolean foundIt = false;
              for (int i = 0; i < theText.length();i++){
                foundIt = false;
                String theGlyphId = ""+theText.charAt(i);
                
                if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                else if (theGlyphId.equals("&")) theGlyphId = "&amp;";
                else if (theGlyphId.equals("'")) theGlyphId = "&amp;";
                else if (theGlyphId.equals(">")) theGlyphId = "&gt;";
                else if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                
                for (int j = 0; j < allTheGlyphs.size(); j++) {
                  //println("comparing " + ((EHSVGGlyph)allTheGlyphs.get(j)).glyphID + " with " + theGlyphId);
                  if (((EHSVGGlyph)allTheGlyphs.get(j)).glyphID.equals(theGlyphId)) {
                    //println("found " + theGlyphId + " in cache");
                    advancement += ((EHSVGGlyph)allTheGlyphs.get(j)).horizAdv;
                    foundIt = true;
                    break;
                    //System.out.println("advancement up to " + theGlyphId + " :  " + advancement);
                  }
                }
                if (!foundIt) {
                  //println("not found " + theGlyphId + " in cache");
                  // if we are here it means that the character was not parsed
                  // nor its bitmap can be found in the cache
                  int positionInVector = cacheSpecificCharacter(theGlyphId);
                  if (positionInVector == -1) continue;              
                  // ok now the glyph is loaded from file and cached, get
                  // the advancement
                  advancement += ((EHSVGGlyph)allTheGlyphs.get(positionInVector)).horizAdv;
                }

              }
              
              // todo you need this two 1-pixel margins because otherwise
              // for rounding errors you probably end up drawing on non-allocated data
              // and this crashes the App. Worth investigating and reporting.
              int intWidth = int (advancement *  theDrawingSize ) + 1;
              int intHeight = int(ascentPlusDescent * theDrawingSize ) + 1;
              java.awt.Rectangle toBeReturned = new java.awt.Rectangle(intWidth , intHeight);

              return toBeReturned;
            }



            float drawGlyphOnMainScreenFromCachedBitmaps(String theChar, float posX, float posY) {

              if (allTheGlyphs == null) {
                 allTheGlyphs = new ArrayList(); // if you know the type of this array put it here > EHSVGGlyph
              }
              if (allTheGlyphsBitmaps == null) {
                allTheGlyphsBitmaps = new ArrayList(); // if you know the type of this array put it here > PGraphics
              }

              for (int i = 0; i < allTheGlyphs.size(); i++) {
                //println("comparing " + ((EHSVGGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                if (((EHSVGGlyph)allTheGlyphs.get(i)).glyphID.equals(theChar)) {
                  drawGlyphNumberOnMainScreenFromCachedBitmaps(i,  posX,  posY);
                  return ((EHSVGGlyph)allTheGlyphs.get(i)).horizAdv;
                }
              }
              // if we are here it means that the character was not found in the cache
              //println("cache miss on char " + theChar);
              int positionInVector = cacheSpecificCharacter(theChar);
              if (positionInVector == -1) return -1;              
              // ok now the glyph is loaded from file and cached, the function
              // calls itself and this time it will draw the character
              //println("ok loaded the glyph in position " + positionInVector + " now drawing");
              drawGlyphNumberOnMainScreenFromCachedBitmaps(positionInVector,  posX,  posY);
              return ((EHSVGGlyph)allTheGlyphs.get(positionInVector)).horizAdv;
            }

            float drawGlyphOnPGraphicsFromCachedBitmaps(String theChar, float posX, float posY, float theDrawingSize) {
              for (int i = 0; i < allTheGlyphs.size(); i++) {
                //println("comparing " + ((EHSVGGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                if (((EHSVGGlyph)allTheGlyphs.get(i)).glyphID.equals(theChar)) {
                  if (HighDpiScreenManager.dpiScaleFactor == 1) {
                    drawGlyphNumberOnPGraphicsFromCachedBitmaps(i,  posX,  posY, theDrawingSize);
                  }
                  else if (HighDpiScreenManager.dpiScaleFactor == 2) {
                    // note that the bitmap is drawn at its original size because
                    // with retina display the cached bitmaps have twice the scale already.
                    drawGlyphNumberOnPGraphicsFromCachedBitmaps(i,  2.0 * posX,  2.0 * posY, theDrawingSize);
                  }
                  return ((EHSVGGlyph)allTheGlyphs.get(i)).horizAdv * theDrawingSize;
                }
              }
              return -1;              
            }

            float drawGlyph(String theChar, float posX, float posY, float drawingSize) {
              for (int i = 0; i < allTheGlyphs.size(); i++) {
                //println("comparing " + ((EHSVGGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                if (((EHSVGGlyph)allTheGlyphs.get(i)).glyphID.equals(theChar)) {
                  drawGlyphNumber(i,  posX,  posY,  drawingSize);
                  return ((EHSVGGlyph)allTheGlyphs.get(i)).horizAdv * drawingSize;
                }
              }
              return -1;              
            }

            void loadFont(String thePassedFileName) {
              theFileName = thePassedFileName;
              String lines3[];
              //println("doing loadStrings on " + thePassedFileName);
              lines3 = loadStrings(thePassedFileName);
              //println("there are " + lines3.length + " lines");
              for (int i=0; i < lines3.length; i++) {
                //println(lines3[i]);
                fontFileContents = fontFileContents + "\n" + lines3[i];
              }
              // only the header will be parsed, we'll parse each glyph only when needed
              parseHeader();
              //parseEntireFile();
            }

            void parseHeader() {
              int positionOfAscent = fontFileContents.indexOf("ascent=\"") + 8;
              int positionOfEndOfAscent = fontFileContents.indexOf("\"",positionOfAscent);

              int positionOfDescent = fontFileContents.indexOf("descent=\"-") + 10;
              int positionOfEndOfDescent = fontFileContents.indexOf("\"", positionOfDescent);
              
              //System.out.println("ascent string : " + fontFileContents.substring(positionOfAscent, positionOfEndOfAscent));              
              //System.out.println("descent string : " + fontFileContents.substring(positionOfDescent, positionOfEndOfDescent));

              ascentFromFile =  parseInt(fontFileContents.substring(positionOfAscent, positionOfEndOfAscent));
              descentFromFile =  parseInt(fontFileContents.substring(positionOfDescent, positionOfEndOfDescent));
              
              ascentPlusDescentFromFile = ascentFromFile + descentFromFile;
            }
            
            int parseSpecificCharacter(String glyphID) {
              
                int positionOfGlyph = fontFileContents.indexOf("<glyph unicode=\"" + glyphID);
                if (positionOfGlyph == -1) return -1;                
                
                positionOfGlyph = fontFileContents.indexOf("horiz-adv-x=\"", positionOfGlyph);
                String glyphAdvSpacing = "";
                int searchingFlorAdvancedSpacing = positionOfGlyph + 13;
                while (!((fontFileContents.charAt(searchingFlorAdvancedSpacing)+"").equals("\""))) {
                  glyphAdvSpacing = glyphAdvSpacing + fontFileContents.charAt(searchingFlorAdvancedSpacing);
                  searchingFlorAdvancedSpacing++;
                }
                //println("the glyph spacing is: >" + glyphAdvSpacing + "<");
                positionOfGlyph = searchingFlorAdvancedSpacing;

                //////////
                
                positionOfGlyph = fontFileContents.indexOf("d=\"", positionOfGlyph);
                String commandsString = "";
                int searchingForCommandString = positionOfGlyph + 3;
                // TODO you can search for "" />" instead, would be quicker than scanning
                // char by char to find the closed quotes.
                while (!((fontFileContents.charAt(searchingForCommandString)+"").equals("\""))) {
                  commandsString = commandsString + fontFileContents.charAt(searchingForCommandString);
                  searchingForCommandString++;
                }
                //println("the glyph command is: >" + commandsString + "<");
                positionOfGlyph = searchingForCommandString;
                
                ///////////////////////
                // now parse each command
                
                EHSVGPathParserAndDrawer ehsvgPathParserAndDrawer = new EHSVGPathParserAndDrawer();
                ehsvgPathParserAndDrawer.loadFromString(commandsString);
                EHSVGGlyph newEHSVGGlyph = new EHSVGGlyph();
                newEHSVGGlyph.loadCommandsPointsAndAdv(ehsvgPathParserAndDrawer, parseFloat(glyphAdvSpacing) * fontScale , glyphID);
                allTheGlyphs.add(newEHSVGGlyph);
                
               return allTheGlyphs.size()-1;

            }

            void parseEntireFile() {
              
              int positionOfNextGlyph = 0;
              
              //println("parseEntireFile");
              //println("file contents: " + fontFileContents);
              //println("parsing header");
              parseHeader();
              //println("parsed header");
              
              while(true){
                positionOfNextGlyph = fontFileContents.indexOf("<glyph unicode=\"", positionOfNextGlyph);
                //println("found a glyph at " + positionOfNextGlyph);
                if (positionOfNextGlyph == -1) return;
                
                numberOfGlyphs++;
                
                String glyphID = "";
                int searchingFlorClosedQuotes = positionOfNextGlyph + 16;
                while (!((fontFileContents.charAt(searchingFlorClosedQuotes)+"").equals("\""))) {
                  glyphID = glyphID + fontFileContents.charAt(searchingFlorClosedQuotes);
                  searchingFlorClosedQuotes++;
                }
                //println("the glyph id is: >" + glyphID + "<");
                positionOfNextGlyph = searchingFlorClosedQuotes;
                
                //////////
                
                positionOfNextGlyph = fontFileContents.indexOf("horiz-adv-x=\"", positionOfNextGlyph);
                String glyphAdvSpacing = "";
                int searchingFlorAdvancedSpacing = positionOfNextGlyph + 13;
                while (!((fontFileContents.charAt(searchingFlorAdvancedSpacing)+"").equals("\""))) {
                  glyphAdvSpacing = glyphAdvSpacing + fontFileContents.charAt(searchingFlorAdvancedSpacing);
                  searchingFlorAdvancedSpacing++;
                }
                //println("the glyph spacing is: >" + glyphAdvSpacing + "<");
                positionOfNextGlyph = searchingFlorAdvancedSpacing;

                //////////
                
                positionOfNextGlyph = fontFileContents.indexOf("d=\"", positionOfNextGlyph);
                String commandsString = "";
                int searchingForCommandString = positionOfNextGlyph + 3;
                // TODO you can search for "" />" instead, would be quicker than scanning
                // char by char to find the closed quotes.
                while (!((fontFileContents.charAt(searchingForCommandString)+"").equals("\""))) {
                  commandsString = commandsString + fontFileContents.charAt(searchingForCommandString);
                  searchingForCommandString++;
                }
                //println("the glyph command is: >" + commandsString + "<");
                positionOfNextGlyph = searchingForCommandString;
                
                ///////////////////////
                // now parse each command
                
                EHSVGPathParserAndDrawer ehsvgPathParserAndDrawer = new EHSVGPathParserAndDrawer();
                ehsvgPathParserAndDrawer.loadFromString(commandsString);
                EHSVGGlyph newEHSVGGlyph = new EHSVGGlyph();
                newEHSVGGlyph.loadCommandsPointsAndAdv(ehsvgPathParserAndDrawer, parseFloat(glyphAdvSpacing) * fontScale  , glyphID);
                allTheGlyphs.add(newEHSVGGlyph);
                
                
                
              }
              
            }
            
            
          }

