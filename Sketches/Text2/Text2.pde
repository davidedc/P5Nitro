/////////////////////////////////////////////////////////////////////////
//   testing fonts
/////////////////////////////////////////////////////////////////////////

EHSVGPathParserAndDrawer ehsvgPathParserAndDrawer;
EHSVGPFont pfontEHSVG;
EHSVGPFont pfontEHSVGCachedOnDemand;
String wantToWriteThis1 = "DiregtB Pink";
String wantToWriteThis15 = "IndiregtB Pink";
String wantToWriteThis2 = "IndiregtBT Pink";
String wantToWriteThis3 = "Vecg Red";

EHSVGTextGraphics vectorTestPGraphics;
EHSVGTextGraphics vectorTechnicalTestPGraphics;
EHSVGTextGraphics cachedBitmapsPGraphics0;
EHSVGTextGraphics cachedBitmapsPGraphics0HalfSize;
EHSVGTextGraphics vectorTestPGraphicsHalfSize;
EHSVGTextGraphics vectorTechnicalTestPGraphicsHalfSize;

EHSVGTextGraphics cachedBitmapsPGraphicsCachedOnDemand;
EHSVGTextGraphics cachedBitmapsPGraphicsCachedOnDemandHalfSize;

void setup() {
  size(320,480);
  smooth();
      pfontEHSVG = new EHSVGPFont();
      pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
      pfontEHSVG.setFontScale(0.05);
      pfontEHSVG.cacheAllBitmaps();
      
      pfontEHSVGCachedOnDemand = new EHSVGPFont();
      pfontEHSVGCachedOnDemand.loadFont("MgOpenModernaRegular.ehsvg");
      pfontEHSVGCachedOnDemand.setFontScale(0.05);     
      
      // note that this font system doesn't yet support drawing
      // vectors on the main screen - only on pGraphics
      // for the time being. This is because
      // the pGraphics for the main screen is actually a different class
      // because it's openGL accelerated.

      // this one creates a graphics for you with a transparent background and
      // white text obtained by painting cached bitmaps on it
      cachedBitmapsPGraphics0 = pfontEHSVG.createEHSVGTextGraphicsFromCachedBitmaps(wantToWriteThis15, 1.0);
      cachedBitmapsPGraphics0HalfSize = pfontEHSVG.createEHSVGTextGraphicsFromCachedBitmaps(wantToWriteThis15, 0.8);

      //cachedBitmapsPGraphicsCachedOnDemand = pfontEHSVGCachedOnDemand.createEHSVGTextGraphicsFromCachedBitmaps(wantToWriteThis15, 1.0);
      //cachedBitmapsPGraphicsCachedOnDemandHalfSize = pfontEHSVGCachedOnDemand.createEHSVGTextGraphicsFromCachedBitmaps(wantToWriteThis15, 0.8);


      // this one creates a graphics for you with a transparent background and
      // white text obtained by painting by vector on it
      vectorTestPGraphics = pfontEHSVG.createEHSVGTextGraphicsWithVectorText(wantToWriteThis3, 1);
      vectorTestPGraphicsHalfSize = pfontEHSVG.createEHSVGTextGraphicsWithVectorText(wantToWriteThis3, 0.8);

}
 
void draw() {
  background(255,255,0);
  
  if (frameCount < 300) {
      // This one paints cached bitmaps directly to the main pGraphics
      // It's fast and caters for text that changes a lot.
      println("painting cached bitmaps directly to the main pGraphics");
      //pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis1 + frameCount, 10, 10, color(255,0,255) );
      pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis1 + frameCount, 10, 30 , color(255,0,255) );
  }
  else if (frameCount < 600) {
      // This one paints cached bitmaps directly to the main pGraphics
      // It's fast and caters for text that changes a lot.
      println("painting cached bitmaps directly to the main pGraphics - smaller");
      //pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis1 + frameCount, 10, 10, color(255,0,255) );
      pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis1 + frameCount, 10, 30 , color(255,0,255), 0.8 );
  }
  else if (frameCount < 900) {
      // This one paints an image obtained by painting cached bitmaps on it
      println("painting an image obtained by painting cached bitmaps on it");
      pfontEHSVG.putTextGraphics(cachedBitmapsPGraphics0, 10, 30  , color(255,0,255));
  }
  else if (frameCount < 1200) {
      // This one paints an image obtained by painting cached bitmaps on it
      println("painting an image obtained by painting cached bitmaps on it - smaller");
      pfontEHSVG.putTextGraphics(cachedBitmapsPGraphics0HalfSize, 10, 30 , color(255,0,255));
  }
  else if (frameCount < 1500) {
      // This one paints an image obtained by painting vectors on it
      println("painting an image obtained by painting vectors on it");
      pfontEHSVG.putTextGraphics(vectorTestPGraphics, 10, 30  , color(255,0,0));
  }
  else if (frameCount < 1800) {
      // This one paints an image obtained by painting vectors on it
      println("painting an image obtained by painting vectors on it - smaller");
      pfontEHSVG.putTextGraphics(vectorTestPGraphicsHalfSize, 10, 30 , color(255,0,0));
  }
  else if (frameCount < 2100) {
      // This one paints an image obtained by painting cached bitmaps on it
      println("painting an image obtained by painting cached bitmaps on it - cached on demand");
      //pfontEHSVGCachedOnDemand.putTextGraphics(cachedBitmapsPGraphicsCachedOnDemand, 10, 30  , color(255,0,255));
      //pfontEHSVGCachedOnDemand.drawTextFromCachedBitmaps("ccached on demand " + frameCount, 10, 30 , color(255,0,255) );
      pfontEHSVGCachedOnDemand.drawTextFromCachedBitmaps("caghed on demand: ", 10, 30 , color(255,0,255) );
  }
  else if (frameCount < 2400) {
      // This one paints an image obtained by painting cached bitmaps on it
      println("painting an image obtained by painting cached bitmaps on it - cached on demand - smaller");
      //pfontEHSVGCachedOnDemand.putTextGraphics(cachedBitmapsPGraphicsCachedOnDemand, 10, 30  , color(255,0,255));
      //pfontEHSVGCachedOnDemand.drawTextFromCachedBitmaps("ccached on demand " + frameCount, 10, 30 , color(255,0,255) );
      pfontEHSVGCachedOnDemand.drawTextFromCachedBitmaps("caghed on demand: ", 10, 30 , color(255,0,255), 0.8 );
  }
  else {
    println("test over");
    noLoop();
    exit();
  }
 
      // draw an x where the ascent is
      stroke(0);
      line(10 -5, 30  - 5, 10 + 5, 30 + 5);
      line(10 -5, 30  + 5, 10 + 5, 30  - 5);
}
 

