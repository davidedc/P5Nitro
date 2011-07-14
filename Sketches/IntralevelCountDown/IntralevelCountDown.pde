PFontEHSVG menu_pfontEHSVG;
float menu_fontScale_menu = 0.038;
PGraphics intraLevelLevel;
PGraphics intraLevelStartingIn;

int cD = 3;
SimpleTimer timer;

void setup() {
  background(0);
  size (320,480);
  smooth();
  timer = new SimpleTimer(1000);
  timer.start();

  menu_pfontEHSVG = new PFontEHSVG();
  menu_pfontEHSVG.loadFont("MgOpenModernaBold.ehsvg");
  menu_pfontEHSVG.cacheAllBitmaps(menu_fontScale_menu);

  intraLevelLevel = menu_pfontEHSVG.createPGraphicsWithBitmapText("Level", 0.035);
  intraLevelStartingIn =  menu_pfontEHSVG.createPGraphicsWithBitmapText("starting in", 0.035);

}

void draw () {
  
if ( cD == -1){
  timer.isFinished();
  cD=3;
}
else {
  background(0);
  noStroke();
  fill(180,36,76,99);
  rect(15,215,300,60);  

  tint(180,36,76);
  image(intraLevelLevel,20,227);
  menu_pfontEHSVG.drawTextFromCachedBitmaps(1+"", 115, 227, color(180,36,76) );

  tint(180,36,76);
  image(intraLevelStartingIn,20,287);
  menu_pfontEHSVG.drawTextFromCachedBitmaps(cD+"", 195, 287, color(180,36,76) );
}

  if (timer.isFinished()) {
    cD = cD-1;
    timer.start();
  }

}


