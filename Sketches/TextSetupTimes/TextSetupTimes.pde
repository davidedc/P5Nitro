/////////////////////////////////////////////////////////////////////////
//   testing fonts setup times only (no rendering)
/////////////////////////////////////////////////////////////////////////

EHSVGPathParserAndDrawer ehsvgPathParserAndDrawer;
PFontEHSVG pfontEHSVG;
float fontScale = 0.05;

void setup() {
  size(320,480);
  smooth();
      pfontEHSVG = new PFontEHSVG();
      pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
      //pfontEHSVG.cacheAllBitmaps(fontScale);
     //pfontEHSVG.cacheSpecificCharacter(fontScale,  "M");
}
 

void draw() {
      //background(255,0,0);
      //noLoop();
      background(255,0,0);
      String wantToWriteThis = "AgMI& " + frameCount;
      pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis, 30, 40, color(255,255,0) );
      //noLoop();
}

 

