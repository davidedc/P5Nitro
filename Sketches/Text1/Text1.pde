/////////////////////////////////////////////////////////////////////////
//   testing fonts
/////////////////////////////////////////////////////////////////////////

EHSVGPathParserAndDrawer ehsvgPathParserAndDrawer;
PFontEHSVG pfontEHSVG;
float fontScale = 0.05;
String wantToWriteThis1 = "DirectB Pink";
String wantToWriteThis15 = "IndirectB Pink";
String wantToWriteThis2 = "IndirectBT Pink";
String wantToWriteThis3 = "Vec Red";
String wantToWriteThis4 = "VecT Turquois";
PGraphics cachedBitmapsPGraphics0;
PGraphics cachedBitmapsPGraphics;
PGraphics vectorTestPGraphics;
PGraphics vectorTechnicalTestPGraphics;

void setup() {
  size(320,480);
  smooth();
      pfontEHSVG = new PFontEHSVG();
      pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
      pfontEHSVG.cacheAllBitmaps(fontScale);

      // this one creates a graphics for you with a transparent background and
      // white text obtained by painting cached bitmaps on it
      cachedBitmapsPGraphics0 = pfontEHSVG.createPGraphicsWithBitmapText(wantToWriteThis15, fontScale);

      // this one is a technical test, it shouldn't be exposed
      // because it's too tempting to pass the main pGraphics
      // to it and it wouldn't work
      // Plus, if you pass a pre-painted graphics
      // that wouldn't work too well either because
      // the text is only painted white (an tinted later)
      java.awt.Rectangle sizeOfWrite = pfontEHSVG.sizeOfString(wantToWriteThis2);
      cachedBitmapsPGraphics = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
      pfontEHSVG.drawTextOnPGraphicsFromCachedBitmaps(cachedBitmapsPGraphics, wantToWriteThis2, 0,0 );

      // this one creates a graphics for you with a transparent background and
      // white text obtained by painting by vector on it
      vectorTestPGraphics = pfontEHSVG.createPGraphicsWithVectorText(wantToWriteThis3, fontScale);

      // I don't think you should expose this
      // because it's too tempting to put this in the pGraphics and it wouldn't work
      // in Haxe. Also if you pass a bitmap you have you'd get back
      // the white text with the holes painted black so what's the point
      // but anyways this is a technical test so it's OK
      sizeOfWrite = pfontEHSVG.sizeOfString(wantToWriteThis4, fontScale);
      vectorTechnicalTestPGraphics = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
      pfontEHSVG.drawTextOnPGraphicsFromVectors(vectorTechnicalTestPGraphics, wantToWriteThis4, 0, int(pfontEHSVG.ascent*fontScale) , fontScale);

}
 
void draw() {
  background(255,255,0);
  
  if (frameCount < 300) {
      // This one paints cached bitmaps directly to the main pGraphics
      // It's fast and caters for text that changes a lot.
      pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis1 + frameCount, 10, 10, color(255,0,255) );
  }
  else if (frameCount < 600) {
      // This one paints an image obtained by painting cached bitmaps on it
      pfontEHSVG.putTextGraphics(cachedBitmapsPGraphics0, 10, 10, color(255,0,255));
  }
  else if (frameCount < 900) {
      // This one is a variation of the test above and it's only
      // a technical test, it's not the way one is supposed to create
      // text
      pfontEHSVG.putTextGraphics(cachedBitmapsPGraphics, 10, 10, color(255,0,255));
  }
  else if (frameCount < 1200) {
      // This one paints an image obtained by painting vectors on it
      pfontEHSVG.putTextGraphics(vectorTestPGraphics, 10, 10, color(255,0,0));
  }
  else if (frameCount < 1500) {
      // Same as above, but a more manual way to set
      // up the image - you create it manually
      // instead of being given one by the font system.
      // As mentioned above, this method shouldn't really
      // be used, it's just a technical test
      pfontEHSVG.putTextGraphics(vectorTechnicalTestPGraphics, 10, 10, color(0,255,255));
  }
 
}
 

