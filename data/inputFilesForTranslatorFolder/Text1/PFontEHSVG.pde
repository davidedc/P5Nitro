          class PFontEHSVG {
            
            PGraphics whichPGraphicsToDrawOn;
            int parsingPosition;
            int numberOfGlyphs;
            //int textColor;
            public int ascent;
            public int descent;
            public int ascentPlusDescentCorrected;
            float drawingSize;
            //EhsvgGlyph[] allTheGlyphs;
            ArrayList allTheGlyphs;
            ArrayList allTheGlyphsBitmaps;
            String theFileName;
            String fontFileContents;
            float fontScale;
            
            PFontEHSVG() {
              parsingPosition = 0;
              numberOfGlyphs = 0;
              allTheGlyphs = new ArrayList(); // if you know the type of this array put it here > EhsvgGlyph
              allTheGlyphsBitmaps = new ArrayList(); // if you know the type of this array put it here > PGraphics
            }

            void setFontScale(float theFontScale) {
              fontScale = theFontScale;
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

            void putTextGraphics(PGraphics pg, int posx, int posy) {
                image(pg, 10, 10);
            }
            
            void putTextGraphics(PGraphics pg, int posx, int posy, color theTextColor) {
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
              image(pg, 10, 10);
               
              // put back the tint to what it was,
              // if there was a tint, that is
              if (tintWasOriginallyOn) {
                 tint(red(originalTint), green(originalTint), blue(originalTint), alpha(originalTint));                
              }
              else noTint();
             
            }
            
            int cacheSpecificCharacter(float theDrawingSize, String glyphID) {
              int k = parseSpecificCharacter(glyphID);
              
              drawingSize = theDrawingSize;
              whichPGraphicsToDrawOn = createGraphics(int(((EhsvgGlyph)allTheGlyphs.get(k)).horizAdv * drawingSize), int((ascentPlusDescentCorrected)*drawingSize) , P2D );
              whichPGraphicsToDrawOn.beginDraw();
              whichPGraphicsToDrawOn.background(0);
              whichPGraphicsToDrawOn.fill(255);
              drawGlyphNumber(k, 0 , int((ascent)*drawingSize) , drawingSize);
              whichPGraphicsToDrawOn.endDraw();
              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();
              allTheGlyphsBitmaps.add(whichPGraphicsToDrawOn);
              return allTheGlyphsBitmaps.size() - 1;
            }
            
            void cacheAllBitmaps(float theDrawingSize) {
              // you might have cahed some other bitmaps before,
              // so we clean up everything here
              
              if(allTheGlyphs.size() != 0) {
                allTheGlyphs = new ArrayList(); // if you know the type of this array put it here > EhsvgGlyph
                allTheGlyphsBitmaps = new ArrayList(); // if you know the type of this array put it here > PGraphics
              }

              // we could be smarter and parse only the body because
              // the header is parsed when you call "loadFont"
              // but it's not worth it
              parseEntireFile();
                            
              drawingSize = theDrawingSize;
              System.out.println("numberOfGlyphs: "+numberOfGlyphs);
              for (int k = 0; k < numberOfGlyphs;k++){
                //whichPGraphicsToDrawOn = createGraphics(int(((EhsvgGlyph)allTheGlyphs.get(k)).horizAdv * drawingSize)*10,100, P2D );
                whichPGraphicsToDrawOn = createGraphics(int(((EhsvgGlyph)allTheGlyphs.get(k)).horizAdv * drawingSize), int((ascentPlusDescentCorrected)*drawingSize) , P2D );
                whichPGraphicsToDrawOn.beginDraw();
                // [todo]: the default initialisation of the background and fill of a pGraphics
                // object is not correct
                whichPGraphicsToDrawOn.background(0);
                //whichPGraphicsToDrawOn.stroke(255);
                whichPGraphicsToDrawOn.fill(255);
                //whichPGraphicsToDrawOn.line(0,0,50,50);

                drawGlyphNumber(k, 0 , int((ascent)*drawingSize) , drawingSize);
                //image(whichPGraphicsToDrawOn,50,50);
                whichPGraphicsToDrawOn.endDraw();


              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();

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

                allTheGlyphsBitmaps.add(whichPGraphicsToDrawOn);
                }
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

            PGraphics createPGraphicsWithBitmapText(String theText, float theDrawingSize) {
              drawingSize = theDrawingSize;
              java.awt.Rectangle sizeOfWrite = sizeOfString(theText);
              PGraphics pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
              
              drawTextOnPGraphicsFromCachedBitmaps(pg,  theText, 0, 0);
              return pg;
            }


            float drawTextOnPGraphicsFromCachedBitmaps(PGraphics thePGraphics, String theText, float posX, float posY) {
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
                

                float lastLetterAdv = drawGlyphOnPGraphicsFromCachedBitmaps(theGlyphId, posX + advancement , posY); 
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
              scale(scaleFactor);
              float valueToBeReturned = drawTextFromCachedBitmaps( theText ,  posX / scaleFactor,  posY /scaleFactor );
              scale(1/scaleFactor);
               
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
                //System.out.println("advancement of " + theGlyphId + " is  " + lastLetterAdv + " so advancement is now " + advancement);
              }

              return advancement;
            }


            PGraphics createPGraphicsWithVectorText(String theText, float theDrawingSize) {
              drawingSize = theDrawingSize;
              java.awt.Rectangle sizeOfWrite = sizeOfString(theText);
              PGraphics pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
              
              drawTextOnPGraphicsFromVectors(pg, theText, 0, int(ascent*drawingSize) , drawingSize);
              return pg;
            }

            

            float drawTextOnPGraphicsFromVectors(PGraphics thePGraphics, String theText, float posX, float posY, float theDrawingSize) {
              drawingSize = theDrawingSize;
              float advancement = 0;
              whichPGraphicsToDrawOn = thePGraphics;
              
              //whichPGraphicsToDrawOn.smooth();
              whichPGraphicsToDrawOn.beginDraw();
              //whichPGraphicsToDrawOn.smooth();
              whichPGraphicsToDrawOn.background(0);
              //whichPGraphicsToDrawOn.noStroke();
              whichPGraphicsToDrawOn.stroke(255);
              for (int i = 0; i < theText.length();i++){
                String theGlyphId = ""+theText.charAt(i);
                
                if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                else if (theGlyphId.equals("&")) theGlyphId = "&amp;";
                else if (theGlyphId.equals("'")) theGlyphId = "&amp;";
                else if (theGlyphId.equals(">")) theGlyphId = "&gt;";
                else if (theGlyphId.equals("<")) theGlyphId = "&lt;";

                advancement += drawGlyph(theGlyphId, posX + advancement , posY, drawingSize);
              }
              whichPGraphicsToDrawOn.endDraw();
              
              /*
              whichPGraphicsToDrawOn.loadPixels();
              int pgWidth = int(whichPGraphicsToDrawOn.width);
              int pgHeight = int(whichPGraphicsToDrawOn.height);
              for (int x = 0; x < pgWidth; x++) {
                // Loop through every pixel row
                for (int y = 0; y < pgHeight; y++) {
                  // Use the formula to find the 1D location
                  int loc = x + y * pgWidth;
                    int r = int(red(whichPGraphicsToDrawOn.pixels[loc]));
                    //int g = int(green(pg.pixels[loc]));
                    //int b = int(blue(pg.pixels[loc]));
                    //int a = int(alpha(pg.pixels[loc]));
                    whichPGraphicsToDrawOn.pixels[loc] =  color(255,r); 
                }
              }
              
              // [ddc] note, the opengl implementation doesn't work if this is off
              // one possible way to solve this is by having updatePixels to check whether
              // a loadpixels was done in this draw loop. If not, then
              // it should do nothing.
              whichPGraphicsToDrawOn.updatePixels();
              */
              
              whichPGraphicsToDrawOn.loadPixels();
              int allThePixels =  int(whichPGraphicsToDrawOn.width * whichPGraphicsToDrawOn.height);
              for (int x = 0; x < allThePixels; x++)
                    whichPGraphicsToDrawOn.pixels[x] =  color(255,int(red(whichPGraphicsToDrawOn.pixels[x]))); 
              whichPGraphicsToDrawOn.updatePixels();


              return advancement;
            }

            void drawGlyphNumberOnPGraphicsFromCachedBitmaps(int theGlyphNumber, float posX, float posY) {
              float curPosX = posX;
              float curPosY = posY;
              
              whichPGraphicsToDrawOn.translate(posX, posY);
              //System.out.println("drawing glyph number " + theGlyphNumber);
              //whichPGraphicsToDrawOn.tint(red(textColor), green(textColor), blue(textColor), alpha(textColor));
              whichPGraphicsToDrawOn.image((PGraphics)allTheGlyphsBitmaps.get(theGlyphNumber),0,0);
              whichPGraphicsToDrawOn.translate(-posX, -posY);
            }

            void drawGlyphNumberOnMainScreenFromCachedBitmaps(int theGlyphNumber, float posX, float posY) {
              float curPosX = posX;
              float curPosY = posY;
              
              translate(posX, posY);
                // svg works in cartesian coordinates, while in
                // processing the origin is in the top left corner
                
                //whichPGraphicsToDrawOn.scale(1,-1);
                //whichPGraphicsToDrawOn.scale(drawingSize,drawingSize);

                //((EhsvgGlyph)allTheGlyphs.get(theGlyphNumber)).commandParserAndDrawer.executeCommand(whichPGraphicsToDrawOn, posX,posY);
                //System.out.println("drawing glyph number " + theGlyphNumber);
                
                //tint(red(textColor), green(textColor), blue(textColor), alpha(textColor));
                image((PGraphics)allTheGlyphsBitmaps.get(theGlyphNumber),0,0);
                //whichPGraphicsToDrawOn.scale(1/drawingSize,1/drawingSize);
                //whichPGraphicsToDrawOn.scale(1,-1);
                translate(-posX, -posY);
            }

            void drawGlyphNumber(int theGlyphNumber, float posX, float posY, float drawingSize) {
              float curPosX = posX;
              float curPosY = posY;
              
              whichPGraphicsToDrawOn.translate(posX, posY);
                // svg works in cartesian coordinates, while in
                // processing the origin is in the top left corner
                
                
                whichPGraphicsToDrawOn.scale(1,-1);
                whichPGraphicsToDrawOn.scale(drawingSize,drawingSize);

                ((EhsvgGlyph)allTheGlyphs.get(theGlyphNumber)).commandParserAndDrawer.executeCommand(whichPGraphicsToDrawOn, posX,posY);
                whichPGraphicsToDrawOn.scale(1/drawingSize,1/drawingSize);
                whichPGraphicsToDrawOn.scale(1,-1);
                whichPGraphicsToDrawOn.translate(-posX, -posY);
            }

            java.awt.Rectangle sizeOfString(String theText, float  theDrawingSize) {
              drawingSize = theDrawingSize;
              return sizeOfString(theText);
            }


            java.awt.Rectangle sizeOfString(String theText) {
              float advancement = 0;
              for (int i = 0; i < theText.length();i++){
                String theGlyphId = ""+theText.charAt(i);
                
                if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                else if (theGlyphId.equals("&")) theGlyphId = "&amp;";
                else if (theGlyphId.equals("'")) theGlyphId = "&amp;";
                else if (theGlyphId.equals(">")) theGlyphId = "&gt;";
                else if (theGlyphId.equals("<")) theGlyphId = "&lt;";
                
                for (int j = 0; j < allTheGlyphs.size(); j++) {
                  //println("comparing " + ((EhsvgGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                  if (((EhsvgGlyph)allTheGlyphs.get(j)).glyphID.equals(theGlyphId)) {
                    advancement += ((EhsvgGlyph)allTheGlyphs.get(j)).horizAdv * drawingSize;
                    //System.out.println("advancement up to " + theGlyphId + " :  " + advancement);
                  }
                }

              }
              
              int intWidth = int (advancement);
              int intHeight = int((ascentPlusDescentCorrected)*drawingSize);
              java.awt.Rectangle toBeReturned = new java.awt.Rectangle(intWidth , intHeight);

              return toBeReturned;
            }

            float drawGlyphOnMainScreenFromCachedBitmaps(String theChar, float posX, float posY) {

              if (allTheGlyphs == null) {
                 allTheGlyphs = new ArrayList(); // if you know the type of this array put it here > EhsvgGlyph
              }
              if (allTheGlyphsBitmaps == null) {
                allTheGlyphsBitmaps = new ArrayList(); // if you know the type of this array put it here > PGraphics
              }

              for (int i = 0; i < allTheGlyphs.size(); i++) {
                //println("comparing " + ((EhsvgGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                if (((EhsvgGlyph)allTheGlyphs.get(i)).glyphID.equals(theChar)) {
                  drawGlyphNumberOnMainScreenFromCachedBitmaps(i,  posX,  posY);
                  return ((EhsvgGlyph)allTheGlyphs.get(i)).horizAdv * drawingSize;
                }
              }
              // if we are here it means that the character was not found in the cahce
              int positionInVector = cacheSpecificCharacter(fontScale,  theChar);
              if (positionInVector == -1) return -1;              
              // ok now the glyph is loaded from file and cached, the function
              // calls itself and this time it will draw the character
              drawGlyphNumberOnMainScreenFromCachedBitmaps(positionInVector,  posX,  posY);
              return ((EhsvgGlyph)allTheGlyphs.get(positionInVector)).horizAdv * drawingSize;
            }

            float drawGlyphOnPGraphicsFromCachedBitmaps(String theChar, float posX, float posY) {
              for (int i = 0; i < allTheGlyphs.size(); i++) {
                //println("comparing " + ((EhsvgGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                if (((EhsvgGlyph)allTheGlyphs.get(i)).glyphID.equals(theChar)) {
                  drawGlyphNumberOnPGraphicsFromCachedBitmaps(i,  posX,  posY);
                  return ((EhsvgGlyph)allTheGlyphs.get(i)).horizAdv * drawingSize;
                }
              }
              return -1;              
            }

            float drawGlyph(String theChar, float posX, float posY, float drawingSize) {
              for (int i = 0; i < allTheGlyphs.size(); i++) {
                //println("comparing " + ((EhsvgGlyph)allTheGlyphs.get(i)).glyphID + " with " + theChar);
                if (((EhsvgGlyph)allTheGlyphs.get(i)).glyphID.equals(theChar)) {
                  drawGlyphNumber(i,  posX,  posY,  drawingSize);
                  return ((EhsvgGlyph)allTheGlyphs.get(i)).horizAdv * drawingSize;
                }
              }
              return -1;              
            }

            void loadFont(String thePassedFileName) {
              theFileName = thePassedFileName;
              String lines3[];
              lines3 = loadStrings(thePassedFileName);
              //println("there are " + lines3.length + " lines");
              for (int i=0; i < lines3.length; i++) {
                //println(lines[i]);
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
              
              System.out.println("ascent string : " + fontFileContents.substring(positionOfAscent, positionOfEndOfAscent));              
              System.out.println("descent string : " + fontFileContents.substring(positionOfDescent, positionOfEndOfDescent));

              ascent =  parseInt(fontFileContents.substring(positionOfAscent, positionOfEndOfAscent));
              descent =  parseInt(fontFileContents.substring(positionOfDescent, positionOfEndOfDescent));
              
              // unfortunately the descent seems to be too narrow in some cases, so we have to increase the
              // total size by 6%
              ascentPlusDescentCorrected = int((ascent + descent)*1.06);
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
                EhsvgGlyph newEhsvgGlyph = new EhsvgGlyph();
                newEhsvgGlyph.loadCommandsPointsAndAdv(ehsvgPathParserAndDrawer, parseFloat(glyphAdvSpacing) , glyphID);
                allTheGlyphs.add(newEhsvgGlyph);
                
               return allTheGlyphs.size()-1;

            }

            void parseEntireFile() {
              
              int positionOfNextGlyph = 0;
              
              parseHeader();
              
              while(true){
                positionOfNextGlyph = fontFileContents.indexOf("<glyph unicode=\"", positionOfNextGlyph);
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
                EhsvgGlyph newEhsvgGlyph = new EhsvgGlyph();
                newEhsvgGlyph.loadCommandsPointsAndAdv(ehsvgPathParserAndDrawer, parseFloat(glyphAdvSpacing) , glyphID);
                allTheGlyphs.add(newEhsvgGlyph);
                
                
                
              }
              
            }
            
            
          }

