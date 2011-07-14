          /* simulating touch interface, don't remove this line */ int realMouseX = 0;
          /* simulating touch interface, don't remove this line */ int realMouseY = 0;

          /* simulating touch interface, don't remove this line */ int authenticMouseX = 0;
          /* simulating touch interface, don't remove this line */ int authenticMouseY = 0;

          
          PGraphics pg;
          int a = 1;
          //int k = 1;
          //HLine dndnd = new HLine();
          HLine dndnd;
          
          ArrayList anArray; // if you know the type of this array put it here>
          ArrayList anArray2; // if you know the type of this array put it here> int <
          ArrayList anArray3;
          EHSVGPathParserAndDrawer ehsvgPathParserAndDrawer;
          PFontEHSVG pfontEHSVG;

          // the instruction below wouldn't work
          //println("a:" + a);
         
          void setup() {
            size(320,480);
          dndnd = new HLine();
          println("setup");
          
          
          
          // Testing ArryList
          anArray = new ArrayList();
          anArray2 = new ArrayList();
          
          anArray2.add(8);
          println(anArray2.get(0));
          
          anArray.add(4);
          anArray.add(7);
          anArray.add("four");
          anArray.add("seven");
          anArray.add(new HLine());
          anArray.add(new HLine());
          
          println(anArray.get(0));
          println(anArray.get(1));
          println(anArray.get(2));
          println(anArray.get(3));
          //System.out.println(anArray.get(4).printSomething()); // this one doesn't work
          //HLine dkdkdk = anArray.get(4); // doesn't work, can't convert from object to something else
          HLine dkdkdk = (HLine)anArray.get(4); // doesn't work, can't convert from object to something else
          dkdkdk.printSomething();
          ((HLine)anArray.get(5)).printSomething();
          
/*
            String lines2[] = loadStrings("LICENSE.txt");

            String lines[];
            String completeText = "";
            lines = loadStrings("LICENSE.txt");
            println("there are " + lines.length + " lines");
            for (int i=0; i < lines.length; i++) {
              //println(lines[i]);
              completeText = completeText + "\n" + lines[i];
            }
            //println("complete text: " + completeText);

            println("1");
         svgCommandParser = new SVGCommandParser();
            println("2");
  */          
          //String SVGCommand = "M45.16,39.31c1-6.03,2.36-11.99,3.89-17.91c0.55,3.33-0.69,6.48-1.43,9.66C46.92,33.83,47.61,37.27,45.16,39.31z";

          // to see how the path below should render, see https://developer.mozilla.org/en/SVG/Tutorial/Paths
          //String SVGCommand = "M10 80 C 40 10, 65 10, 95 80 S 150 150, 180 80";
          //String SVGCommand = "M10 80 Q 52.5 10, 95 80 T 180 80";
          //String SVGCommand = "M10 80 Q 95 10 180 80";
          //String SVGCommand = "M10 10 C 20 20, 40 20, 50 10";
          //String SVGCommand = "M70 10 C 70 20, 120 20, 120 10";
          //String SVGCommand = "M130 10 C 120 20, 180 20, 170 10";
          //String SVGCommand = "M10 60 C 20 80, 40 80, 50 60";
          //String SVGCommand = "M70 60 C 70 80, 110 80, 110 60";
          //String SVGCommand = "M130 60 C 120 80, 180 80, 170 60";
          //String SVGCommand = "M10 110 C 20 140, 40 140, 50 110";
          //String SVGCommand = "M70 110 C 70 140, 110 140, 110 110";
          //String SVGCommand = "M130 110 C 120 140, 180 140, 170 110";
          
          // moderna exclamation mark
          //String SVGCommand = "M100 493Q100 453 84 295Q76 216 76 176H24Q24 226 12 335T0 493V729H100V493ZM100 0H0V109H100V0Z";
          // moderna quot
          //String SVGCommand = "M215 436H146V711H215V436ZM69 436H0V711H69V436Z";
          //String SVGCommand = "M694 497L668 425H518L472 295H631L605 223H445L366 -2H284L364 223H237L155 -2H74L153 223H0L26 295H179L225 425H62L87 497H251L331 724H413L334 497H462L541 724H623L544 497H694ZK2M437 425H306L261 295H391L437 425ZW2";
          //String SVGCommand = "M478 517H390Q382 566 353 594T274 628V397Q389 376 446 322T504 174Q504 84 445 33T274 -18V-109H221V-18Q117 -18 59 44T0 214H89Q89 147 122 106T221 58V318Q107 338 58 386T9 522Q9 604 69 655T221 707V775H274V707Q356 707 413 661Q478 609 478 517ZK2M221 407V628Q168 628 135 599T102 522Q102 473 129 446T221 407ZM274 55Q405 70 405 171Q405 226 373 260T274 305V55ZW2";
          //String SVGCommand = "M609 0Q527 0 478 55Q434 105 434 176Q434 248 477 297Q525 352 609 352Q691 352 740 297Q784 247 784 176Q784 104 741 55Q693 0 609 0ZK2M608 74Q655 74 680 103T706 175Q706 217 682 245Q655 277 608 277Q563 277 537 247T510 175Q510 134 534 106Q562 74 608 74ZW2M640 710L205 -19H144L579 710H640ZM174 337Q91 337 42 393Q-2 443 -2 515Q-2 586 41 635Q90 690 172 690Q255 690 304 635Q348 586 348 513Q348 441 305 392Q257 337 174 337ZK2M174 616Q126 616 99 585T72 512Q72 471 98 442T173 412Q221 412 248 442T275 514Q275 556 250 584Q222 616 174 616ZW2";
          //String SVGCommand = "M644 0H522L450 89Q399 29 340 0T221 -30Q167 -30 122 -6T45 66Q23 100 11 134T-2 199Q-2 258 40 312T179 419Q142 461 123 496Q99 541 99 588Q99 664 155 709Q205 749 277 749Q348 749 395 711Q448 668 448 593Q448 532 406 480Q372 438 311 401L448 235Q461 260 468 293Q471 307 478 355H563Q563 254 507 165L644 0ZK2M363 589Q363 631 338 653T277 676Q239 676 212 653T184 589Q184 552 209 514Q226 488 262 452Q322 491 344 525Q363 555 363 589ZM401 151L227 360Q161 324 129 285T97 204Q97 182 105 160T132 114Q174 57 240 57Q323 57 401 151ZW2";
          //String SVGCommand = "M100 613Q100 565 74 532T0 483V529Q31 534 43 567Q52 591 52 628H0V729H100V613Z";
          //String SVGCommand = "M284 -21Q175 -21 111 93Q53 196 53 345Q53 495 110 597Q174 712 284 712Q393 712 457 597Q515 493 515 345Q515 195 458 93Q394 -21 284 -21ZK2M284 64Q353 64 394 152Q431 232 431 345Q431 461 395 539Q354 627 284 627Q215 627 174 539Q137 459 137 345Q137 230 173 152Q214 64 284 64ZW2";
          //String SVGCommand = "M535 175H434V0H343V175H35V265L342 690H434V255H535V175ZK2M343 255V572L118 255H343ZW2";
          //String SVGCommand = "M532 225Q532 117 456 45Q385 -22 288 -22Q185 -22 117 57Q38 149 38 317Q38 513 128 619Q205 710 318 710Q403 710 463 657Q527 600 527 514H433Q428 566 392 598T307 630Q239 630 193 571Q139 502 139 372Q173 410 217 429T308 449Q398 449 463 389Q532 325 532 225ZK2M434 215Q434 288 389 332Q349 371 291 371Q233 371 193 332Q149 289 149 216Q149 143 194 99Q234 60 292 60Q350 60 390 99Q434 142 434 215ZW2";
         //svgCommandParser.loadFromString(SVGCommand);
         //translate (50,1000);
         //svgCommandParser.executeCommand();
         smooth();
         
            

         
          //noLoop();
          //scale(10);
          //rect(0,0,5,5);
          //strokeWeight(10);
          //rect(0,0,50,50);
          }
         
          void draw() {
            /* simulating touch interface, don't remove this line */ authenticMouseX = mouseX;
            /* simulating touch interface, don't remove this line */ authenticMouseY = mouseY;
            
            /* simulating touch interface, don't remove this line */ mouseX = realMouseX;
            /* simulating touch interface, don't remove this line */ mouseY = realMouseY;
            
            /*
            fill(0,255,0);
            rect (0,0,50,50);
            background(255,0,0);
            rect(50,50,100,100);
            */
            
            /*
            println(frameCount);
            background( int( random(0,255) ) , int( random(0,255) ) , int( random(0,255) ) );

            // draw a grid below the text
            for (int i = 0; i < 32 ; i++) {
               rotate(frameCount/10000.0);
              translate(3,1);
              line(0,0,i*10,480);
            }
            */
            
            /*
            // this test shows how get and set
            // work on the frameBuffer directly
            // and they are not subject to
            // any transformation
            for (int i = 30; i < 100-15; i++) {
              for(int j = 20; j < 100-25; j++) {
                rotate(0.01);
                translate(1,1);
                scale(1.001);
                color c = color(204-j, 153-i, 0);
                //color c = color(255, 0, 0);
                //color c = color(0, 255, 0);
                //color c = color(0, 0, 255);
                //println("color: " + c);
                set(i, j, c);
                //point(204-j, 153-i);
                rect(204-j, 153-i, 1, 1);
              }
            }
            noLoop();
            */
            
            
            /////////////////////////////////////////////////////////////////////////
            //   testing fonts
            /////////////////////////////////////////////////////////////////////////
            //background(0,255,0);
            float fontScale = 0.05;
            //line(0,0,20,200);
            //pfontEHSVG.drawTextOnPGraphicsFromVectors(g, "I love Sophie!gj", 0, 0, fontScale);
            
            if (pg==null) {

            
              // note that createGraphics creates an opaque bitmap. If you want to
              // make it transparent then you have to pixel-process it!
              
              // P.S. note that you can't pass "g" instead of "pg" in haxe, cause they are
              // different types, although you can in Processing - there is effectively
              // no way in haxe now to draw the vector glyphs directly to the main pGraphics object :-(
              
              // 1
              /*
                  pfontEHSVG = new PFontEHSVG();
                  pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
                  String wantToWriteThis = "AgMI love Sophie!gj";
                  Rectangle sizeOfWrite = pfontEHSVG.sizeOfString(wantToWriteThis, fontScale);
                  println("size of write: " + sizeOfWrite.width + " " + sizeOfWrite.height );
                  pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
                  pfontEHSVG.drawTextOnPGraphicsFromVectors(pg, wantToWriteThis, 0, int(pfontEHSVG.ascent*fontScale) , fontScale);
                  pfontEHSVG.putTextGraphics(pg, 10, 10, color(255,0,0));
                  //pfontEHSVG.putTextGraphics(pg, 10, 10); // you can omit the color if you want
                */
                
              // 2
                 /*
                  pfontEHSVG = new PFontEHSVG();
                  pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
                  String wantToWriteThis = "AgMI love Sophie!gj";
                  pg = pfontEHSVG.createPGraphicsWithVectorText(wantToWriteThis, fontScale);
                  pfontEHSVG.putTextGraphics(pg, 10, 10, color(255,0,0));
                  //pfontEHSVG.putTextGraphics(pg, 10, 10); // you can omit the color if you want
                */
              
              // in the first case you are drawing to a pGraphics object you create
              // while in the second case you draw directly on the main pGraphics object
              // note that when you create a pGraphics object it comes with a solid opaque
              // background - if you want to draw text on transparent background
              // then you either have to pixel-process the created pGraphics or you
              // draw the bitmap letters directly onto the main pGraphics object
              // P.S. note that you can't pass "g" instead of "pg" in haxe, cause they are
              // different types, although you can in Processing

              // 1 This should appear as red text on a black background
                /*
                pfontEHSVG = new PFontEHSVG();
                pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
                // note that this function caches all the bitmaps
                // of the letters - transparent background and white
                // fill. You can tint them using tint before
                // calling drawTextOnPGraphicsFromCachedBitmaps
                pfontEHSVG.cacheAllBitmaps(fontScale);
                String wantToWriteThis = "AgMI love Sophie!gj";
                Rectangle sizeOfWrite = pfontEHSVG.sizeOfString(wantToWriteThis);
                println("size of write: " + sizeOfWrite.width + " " + sizeOfWrite.height );
                pg = createGraphics(sizeOfWrite.width, sizeOfWrite.height, P2D);
                pfontEHSVG.drawTextOnPGraphicsFromCachedBitmaps(pg, wantToWriteThis );
                pfontEHSVG.putTextGraphics(pg, 10, 10, color(255,0,0));
                //pfontEHSVG.putTextGraphics(pg, 10, 10); // you can omit the color if you want
                */
                
                
              // 1.5 This should appear a red write on a black background
              // unfortunately this doesn't work in processing
              // because
              // a) painting the letters bitmaps over a transparent background makes
              //    the background lose transparency and
              // b) when you tint the letters bitmaps their black background gets
              //    painted on whatever color was on the background graphics
              /* DOES NOT WORK
                pfontEHSVG = new PFontEHSVG();
                pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
                // note that this function caches all the bitmaps
                // of the letters - transparent background and white
                // fill. You can tint them using tint before
                // calling drawTextOnPGraphicsFromCachedBitmaps
                pfontEHSVG.cacheAllBitmaps(fontScale);
                String wantToWriteThis = "AgMI love Sophie!gj";
                pg = pfontEHSVG.createOpaqueGraphicsWithBitmapText(wantToWriteThis, fontScale, color(255,0,0), color(0,255,0));
                //tint(255,0,0); // yes you can use tint to tint the letters cause they come from bitmaps
                image(pg, 10, 10);
                */
                
              // 2
                
                
                pfontEHSVG = new PFontEHSVG();
                pfontEHSVG.loadFont("MgOpenModernaRegular.ehsvg");
                pfontEHSVG.cacheAllBitmaps(fontScale);
                String wantToWriteThis = "AgMI love Sophie!gj";
                pfontEHSVG.drawTextFromCachedBitmaps(wantToWriteThis, 30, 40, color(255,255,0) );
                noLoop();
                

              
            }
              
              /*
              rotate(-0.0002*frameCount);
              //translate(20.0 - 0.2 * frameCount,300);
              scale(0.5+frameCount/100.0);
              image(pg, 10, 10);
              scale(2,2);
              line(0,0,50,50);
              noLoop();
              */
               
              /*
              Rectangle rectangle2;  
              Rectangle rectangle1 =  new Rectangle(25,25,50,50);  
              rectangle2 =  new Rectangle(55,55,60,60);  
              */
              
              /*
              translate(320/2, 480/2);
              translate(frameCount/100.0, frameCount/100.0);
              rotate(PI/3.0 + frameCount/100.0);
              scale(1-frameCount/10000.0);
              rect(-26, -26, 52, 52);
              */
              
              /*
              rotate(-0.0002*frameCount);
              //translate(20.0 - 0.2 * frameCount,300);
              scale(0.5+frameCount/100.0);
              //tint(255,0,200);
              rect(0, 0, 52, 52);
              scale(2,2);
              line(0,0,50,50);
              if (frameCount == 100 || frameCount == 200  || frameCount == 300 || frameCount == 1000 || frameCount == 2000 )
              println("rotating of " + (-0.0002*frameCount) + " scaling of " + (0.5+frameCount/100.0) );
              */

            /////////////////////////////////////////////////////////////////////////
            


            

          //println("a:" + a);
          //println("draw k:" + k);
               //stroke(255,0.4,0);// just type here
// and click "save" when your done
         //svgCommandParser.executeCommand();

               //stroke(0,255,0);
               //stroke(0,0,255);
               //stroke(255,255,0);
               //translate(10,10);
               //translate(-1,-1);// works
               //translate(-2,-2);// doesn't work
               //translate(-1,-2);// doesn't work only horizontal lines work and no fill
               //translate(-2,-1);// doesn't work only vertical lines work and no fill
               
               //translate(2,1);// doesn't work only vertical lines work and no fill

               //rect(-2,-2,100,100);
               //scale(2);
               //rotate(0.04);
               //fill(255,255,0,100);
               //strokeWeight(int(random(1,5)));
               //fill(mouseX,mouseX,mouseX);
               //line(50,50,random(0,100),random(0,100));
/*
               //line(0,0,100,100);
               //rect(10,10,30,20);
               //rect(1,20,10,40);
               //rect(24,40,22,19);
               //rect(random(0,100),random(0,100),random(0,100),random(0,100));
               for (int i = 0; i< 20; i++){
               rect(int(random(0,100)),int(random(0,100)),int(random(0,100)),int(random(0,100)));
               }
               //ellipse(random(0,100),random(0,100),random(0,100),random(0,100));
               point(30, 20);
                point(85, 20);
                point(85, 75);
                point(30, 75);
*/

/*
// testing endShape(close) and endShape()
beginShape();
vertex(20, 20);
vertex(45, 20);
vertex(45, 80);
endShape(CLOSE);

beginShape();
vertex(50, 20);
vertex(75, 20);
vertex(75, 80);
endShape();
*/

/*
beginShape();
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape(CLOSE);
*/

/*
// testing curveVertex
//noFill();
beginShape();
curveVertex(84,  91);
curveVertex(84,  91);
curveVertex(68,  19);
curveVertex(21,  17);
curveVertex(32, 100);
curveVertex(32, 100);
endShape(CLOSE);
*/

//bezier(85, 20, 10, 10, 90, 90, 15, 80.2);

/*
// testing beziervertex
beginShape();
vertex(30, 20);
bezierVertex(80, 0, 80, 75, 30, 75);
bezierVertex(50, 80, 60, 25, 30, 20);
endShape(CLOSE);
*/

/*
beginShape(LINES);
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape();
*/

/*
beginShape(TRIANGLES);
vertex(30, 75);
vertex(40, 20);
vertex(50, 75);
vertex(60, 20);
vertex(70, 75);
vertex(80, 20);
endShape();
*/

/*
beginShape(TRIANGLE_STRIP);
vertex(30, 75);
vertex(40, 20);
vertex(50, 75);
vertex(60, 20);
vertex(70, 75);
vertex(80, 20);
vertex(90, 75);
endShape();
*/

/*
beginShape(TRIANGLE_FAN);
vertex(57.5, 50);
vertex(57.5, 15); 
vertex(92, 50); 
vertex(57.5, 85); 
vertex(22, 50); 
vertex(57.5, 15); 
endShape();
*/

/*
beginShape(QUADS);
vertex(30, 20);
vertex(30, 75);
vertex(50, 75);
vertex(50, 20);
vertex(65, 20);
vertex(65, 75);
vertex(85, 75);
vertex(85, 20);
endShape();
*/

/*
beginShape(QUAD_STRIP); 
vertex(30, 20); 
vertex(30, 75); 
vertex(50, 20);
vertex(50, 75);
vertex(65, 20); 
vertex(65, 75); 
vertex(85, 20);
vertex(85, 75); 
endShape();
*/

/*
beginShape();
vertex(20, 20);
vertex(40, 20);
vertex(40, 40);
vertex(60, 40);
vertex(60, 60);
vertex(20, 60);
endShape(CLOSE);
*/

//noFill();
/*
beginShape();
vertex(30, 20);
bezierVertex(80, 0, 80, 75, 30, 75);
endShape();
*/
            /* simulating touch interface, don't remove this line */ mouseX = authenticMouseX;
            /* simulating touch interface, don't remove this line */ mouseY = authenticMouseX;


          }
         
void mouseClicked() {
  println("                      mouseClicked from processing!");
  
  /* simulating touch interface, don't remove this line */ realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */ realMouseY = mouseY;

  println("mouseX mouseY " + mouseX + " " + mouseY);

}

void mouseMoved() {
  //this should be empty - only mousedragged should be implemented
}

void mouseDragged() {
  println("                      mouseDragged from processing!");

  /* simulating touch interface, don't remove this line */ realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */ realMouseY = mouseY;
  println("mouseX mouseY " + mouseX + " " + mouseY);

}

void mousePressed() {
  println("                          mousePressed from processing!");
 
  /* simulating touch interface, don't remove this line */ realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */ realMouseY = mouseY;
  println("mouseX mouseY " + mouseX + " " + mouseY);

}

void mouseReleased() {
  println("                            mouseReleased from processing!");

  /* simulating touch interface, don't remove this line */ realMouseX = mouseX;
  /* simulating touch interface, don't remove this line */ realMouseY = mouseY;
  println("mouseX mouseY " + mouseX + " " + mouseY);

}
