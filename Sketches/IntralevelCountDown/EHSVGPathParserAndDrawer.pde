          int SVG_COMMAND_MOVE = 0;
          int SVG_COMMAND_MOVE_RELATIVE = 1;
          int SVG_COMMAND_CLOSEPATH = 2;
          int SVG_COMMAND_LINETO = 3;
          int SVG_COMMAND_LINETO_RELATIVE = 4;
          int SVG_COMMAND_HORIZONTAL = 5;
          int SVG_COMMAND_HORIZONTAL_RELATIVE = 6;
          int SVG_COMMAND_VERTICAL = 7;
          int SVG_COMMAND_VERTICAL_RELATIVE = 8;
          int SVG_COMMAND_CURVE = 9;
          int SVG_COMMAND_CURVE_RELATIVE = 10;
          int SVG_COMMAND_SMOOTHCURVE = 11;
          int SVG_COMMAND_SMOOTHCURVE_RELATIVE = 12;
          int SVG_COMMAND_QUADRATIC = 13;
          int SVG_COMMAND_QUADRATIC_RELATIVE = 14;
          int SVG_COMMAND_QUADRATIC_SMOOTH = 15;
          int SVG_COMMAND_QUADRATIC_SMOOTH_RELATIVE = 16;
          int SVG_COMMAND_DRAWHOLE_START = 17;
          int SVG_COMMAND_DRAWHOLE_END = 18;

          String comma = ",";
          
          class EHSVGPathParserAndDrawer {
            
            int[] commands; // = new int[100];
            float[] points;
            int commandIndex;
            int pointsIndex;
            String stringToParse;
            int parsingIndex;
            int lastCommand;
            float curPosX;
            float curPosY;
            float lastControlPointX;
            float lastControlPointY;
            int numberOfParsedCommands;
            float lastSecondControlPointX;
            float lastSecondControlPointY;
            
            
            EHSVGPathParserAndDrawer() {
              commandIndex = 0;
              pointsIndex = 0;
              lastCommand = 0;
              parsingIndex = 0;
              commands = new int[600];
              points = new float[1700];
              curPosX = 0;
              curPosY = 0;
              lastControlPointX = 0;
              lastControlPointY = 0;
              lastSecondControlPointX = 0;
              lastSecondControlPointY = 0;
            }
            
            void loadFromString(String theSVGString) {
              stringToParse = theSVGString;
              parseCommands();         
            }

              void executeCommand(PGraphics whichPGraphicsToDrawOn, float startingPositionX, float startingPositionY) {

                commandIndex = 0;
                pointsIndex = 0;
                int command = 0;
                boolean shapeBegan = false;
                boolean drawAsShape = true;
                boolean drawOutline = false;
                
                                
                while (commandIndex < numberOfParsedCommands) {
                  command =  commands[commandIndex];
                  //println("commandIndex: " + commandIndex);
                  //println("command: " + command);

                  if (command == SVG_COMMAND_MOVE) {
                    //String toPrint = "moving pen to " + points[pointsIndex] + " , " + points[pointsIndex+1];
                    //println(toPrint);
                    curPosX = points[pointsIndex];
                    curPosY = points[pointsIndex+1];
                    
                    if (drawAsShape) {
                      if (shapeBegan){
                        whichPGraphicsToDrawOn.endShape();
                      }
                      whichPGraphicsToDrawOn.beginShape(POLYGON);
                      //println("shape just began");
                      whichPGraphicsToDrawOn.vertex(curPosX,curPosY);
                      shapeBegan = true;
                    }

                    pointsIndex += 2;
                  }
                  else if (command ==  SVG_COMMAND_CURVE) {
                    //String toPrint = "drawing a curve: bezier " + curPosX + " , " + curPosY + " , " + points[pointsIndex] + " , " + points[pointsIndex+1] + " , " + points[pointsIndex + 2] + " , " + points[pointsIndex + 3] + " , " + points[pointsIndex + 4] + " , " + points[pointsIndex + 5];
                    //println(toPrint);

                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX,curPosY,
                    points[pointsIndex],points[pointsIndex+1],
                    points[pointsIndex+2],points[pointsIndex+3],
                    points[pointsIndex+4],points[pointsIndex+5]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(
                    points[pointsIndex],points[pointsIndex+1],
                    points[pointsIndex+2],points[pointsIndex+3],
                    points[pointsIndex+4],points[pointsIndex+5]);

                    curPosX = points[pointsIndex+4];
                    curPosY = points[pointsIndex+5];
                    
                    lastSecondControlPointX = points[pointsIndex+2];
                    lastSecondControlPointY = points[pointsIndex+3];

                    pointsIndex += 6;
                  }
                  else if (command ==  SVG_COMMAND_CURVE_RELATIVE) {
                    //String toPrint = "drawing a curve bezier relative " + curPosX + " , " + curPosY + " , " + (curPosX + points[pointsIndex]) + " , " + (curPosY + points[pointsIndex+1]) + " , " + (curPosX + points[pointsIndex + 2]) + " , " + (curPosY + points[pointsIndex + 3]) + " , " + (curPosX + points[pointsIndex + 4]) + " , " + (curPosY + points[pointsIndex + 5]);
                    //println(toPrint);

                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX,curPosY,
                    curPosX+points[pointsIndex],curPosY+points[pointsIndex+1],
                    curPosX+points[pointsIndex+2],curPosY+points[pointsIndex+3],
                    curPosX+points[pointsIndex+4],curPosY+points[pointsIndex+5]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(
                    curPosX+points[pointsIndex],curPosY+points[pointsIndex+1],
                    curPosX+points[pointsIndex+2],curPosY+points[pointsIndex+3],
                    curPosX+points[pointsIndex+4],curPosY+points[pointsIndex+5]);

                    curPosX += points[pointsIndex+4];
                    curPosY += points[pointsIndex+5];
                    
                    lastSecondControlPointX = curPosX + points[pointsIndex+2];
                    lastSecondControlPointY = curPosY + points[pointsIndex+3];

                    pointsIndex += 6;
                  }
                  else if (command ==  SVG_COMMAND_SMOOTHCURVE) {
                    float newFirstControlPointX = 2 * curPosX - lastSecondControlPointX;
                    float newFirstControlPointY = 2 * curPosY - lastSecondControlPointY;

                    //String toPrint = "drawing a smooth curve: bezier " + curPosX + " , " + curPosY + " , " + points[pointsIndex] + " , " + points[pointsIndex+1] + " , " + points[pointsIndex + 2] + " , " + points[pointsIndex + 3] + " , " + points[pointsIndex + 4] + " , " + points[pointsIndex + 5];
                    //println(toPrint);
                    
                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX,curPosY,
                    newFirstControlPointX,newFirstControlPointY,
                    points[pointsIndex],points[pointsIndex+1],
                    points[pointsIndex+2],points[pointsIndex+3]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(
                    newFirstControlPointX,newFirstControlPointY,
                    points[pointsIndex],points[pointsIndex+1],
                    points[pointsIndex+2],points[pointsIndex+3]);

                    curPosX = points[pointsIndex+2];
                    curPosY = points[pointsIndex+3];

                    pointsIndex += 4;
                  }
                  else if (command ==  SVG_COMMAND_SMOOTHCURVE_RELATIVE) {
                    float newFirstControlPointX = 2 * curPosX - lastSecondControlPointX;
                    float newFirstControlPointY = 2 * curPosY - lastSecondControlPointY;

                    //String toPrint = "drawing a smooth curve: bezier " + curPosX + " , " + curPosY + " , " + points[pointsIndex] + " , " + points[pointsIndex+1] + " , " + points[pointsIndex + 2] + " , " + points[pointsIndex + 3] + " , " + points[pointsIndex + 4] + " , " + points[pointsIndex + 5];
                    //println(toPrint);
                    
                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX,curPosY,
                    newFirstControlPointX,newFirstControlPointY,
                    curPosX + points[pointsIndex], curPosY + points[pointsIndex+1],
                    curPosX + points[pointsIndex+2], curPosX + points[pointsIndex+3]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(
                    newFirstControlPointX,newFirstControlPointY,
                    curPosX + points[pointsIndex], curPosY + points[pointsIndex+1],
                    curPosX + points[pointsIndex+2], curPosX + points[pointsIndex+3]);

                    curPosX += points[pointsIndex+2];
                    curPosY += points[pointsIndex+3];

                    pointsIndex += 4;
                  }
                  else if (command ==  SVG_COMMAND_QUADRATIC) {
                    //String toPrint = "drawing a quadratic " + curPosX + " , " + curPosY + " , " + points[pointsIndex] + " , " + points[pointsIndex+1] + " , " + points[pointsIndex + 2] + " , " + points[pointsIndex + 3];
                    //println(toPrint);
                    // code below taken from
                    // http://quasipartikel.at/2010/01/07/quadratic-bezier-curves-for-processingjs/
                    float cp1x = curPosX + 2.0/3.0*(points[pointsIndex] - curPosX);
                    float cp1y = curPosY + 2.0/3.0*(points[pointsIndex+1] - curPosY);
                    float cp2x = cp1x + (points[pointsIndex+2] - curPosX)/3.0;
                    float cp2y = cp1y + (points[pointsIndex+3] - curPosY)/3.0;
                  
                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX, curPosY, cp1x, cp1y, cp2x, cp2y, points[pointsIndex+2], points[pointsIndex+3]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(cp1x, cp1y, cp2x, cp2y, points[pointsIndex+2], points[pointsIndex+3]);
                    
                    lastControlPointX = points[pointsIndex]; 
                    lastControlPointY = points[pointsIndex+1];
                    curPosX = points[pointsIndex+2];
                    curPosY = points[pointsIndex+3];
                    pointsIndex += 4;
                  }
                  else if (command ==  SVG_COMMAND_QUADRATIC_RELATIVE) {
                    //String toPrint = "drawing a quaratic relative " + curPosX + " , " + curPosY + " , " + (curPosX + points[pointsIndex]) + " , " + (curPosY + points[pointsIndex+1]) + " , " + (curPosX + points[pointsIndex + 2]) + " , " + (curPosY + points[pointsIndex + 3])  ;
                    //println(toPrint);
                    // code below taken from
                    // http://quasipartikel.at/2010/01/07/quadratic-bezier-curves-for-processingjs/
                    float cp1x = curPosX + 2.0/3.0*(curPosX+points[pointsIndex] - curPosX);
                    float cp1y = curPosY + 2.0/3.0*(curPosY+points[pointsIndex+1] - curPosY);
                    float cp2x = cp1x + (curPosX+points[pointsIndex+2] - curPosX)/3.0;
                    float cp2y = cp1y + (curPosY+points[pointsIndex+3] - curPosY)/3.0;
                  
                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX, curPosY, cp1x, cp1y, cp2x, cp2y, curPosX + points[pointsIndex+2], curPosY + points[pointsIndex+3]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(cp1x, cp1y, cp2x, cp2y, curPosX + points[pointsIndex+2], curPosY + points[pointsIndex+3]);

                    lastControlPointX += points[pointsIndex]; 
                    lastControlPointY += points[pointsIndex+1];
                    curPosX += points[pointsIndex+2];
                    curPosY += points[pointsIndex+3];
                    pointsIndex += 4;
                  }
                  else if (command ==  SVG_COMMAND_QUADRATIC_SMOOTH) {
                    float newControlPointX = 2 * curPosX - lastControlPointX;
                    float newControlPointY = 2 * curPosY - lastControlPointY;

                    //String toPrint = "drawing a smooth quadratic " + curPosX + " , " + curPosY + " , " + newControlPointX + " , " + newControlPointY + " , " + points[pointsIndex] + " , " + points[pointsIndex + 1]  ;
                    //println(toPrint);

                    // code below taken from
                    // http://quasipartikel.at/2010/01/07/quadratic-bezier-curves-for-processingjs/
                    float cp1x = curPosX + 2.0/3.0*(newControlPointX - curPosX);
                    float cp1y = curPosY + 2.0/3.0*(newControlPointY - curPosY);
                    float cp2x = cp1x + (points[pointsIndex] - curPosX)/3.0;
                    float cp2y = cp1y + (points[pointsIndex+1] - curPosY)/3.0;
                  
                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX, curPosY, cp1x, cp1y, cp2x, cp2y, points[pointsIndex], points[pointsIndex+1]);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(cp1x, cp1y, cp2x, cp2y, points[pointsIndex], points[pointsIndex+1]);

                    lastControlPointX = newControlPointX; 
                    lastControlPointY = newControlPointY;
                    curPosX = points[pointsIndex];
                    curPosY = points[pointsIndex+1];
                    pointsIndex += 2;
                  }
                  else if (command ==  SVG_COMMAND_QUADRATIC_SMOOTH_RELATIVE) {
                    // TODO this one is fucked up
                    float newControlPointX = 2 * curPosX - lastControlPointX;
                    float newControlPointY = 2 * curPosY - lastControlPointY;
                    // code below taken from
                    // http://quasipartikel.at/2010/01/07/quadratic-bezier-curves-for-processingjs/
                    float cp1x = curPosX + 2.0/3.0*(newControlPointX - curPosX);
                    float cp1y = curPosY + 2.0/3.0*(newControlPointY - curPosY);
                    float cp2x = cp1x + (points[pointsIndex] )/3.0;
                    float cp2y = cp1y + (points[pointsIndex+1])/3.0;
                  
                    if (drawOutline) whichPGraphicsToDrawOn.bezier(curPosX, curPosY, cp1x, cp1y, cp2x, cp2y, points[pointsIndex] + curPosX, points[pointsIndex+1] + curPosY);

                    if (drawAsShape) whichPGraphicsToDrawOn.bezierVertex(cp1x, cp1y, cp2x, cp2y, points[pointsIndex] + curPosX, points[pointsIndex+1] + curPosY);

                    lastControlPointX = newControlPointX; 
                    lastControlPointY = newControlPointY;
                    curPosX = points[pointsIndex];
                    curPosY = points[pointsIndex+1];
                    pointsIndex += 2;
                  }
                  else if (command ==  SVG_COMMAND_HORIZONTAL) {
                    if (drawOutline) whichPGraphicsToDrawOn.line(curPosX,curPosY, points[pointsIndex], curPosY);
                    
                    if (drawAsShape) whichPGraphicsToDrawOn.vertex (points[pointsIndex], curPosY);
                    
                    curPosX = points[pointsIndex];
                    pointsIndex += 1;
                  }
                  else if (command ==  SVG_COMMAND_HORIZONTAL_RELATIVE) {
                    if (drawOutline) whichPGraphicsToDrawOn.line(curPosX,curPosY, curPosX + points[pointsIndex], curPosY);
                    
                    if (drawAsShape) whichPGraphicsToDrawOn.vertex (curPosX + points[pointsIndex], curPosY);
                    
                    curPosX += points[pointsIndex];
                    pointsIndex += 1;
                  }
                  else if (command ==  SVG_COMMAND_VERTICAL) {
                    if (drawOutline) whichPGraphicsToDrawOn.line(curPosX,curPosY, curPosX, points[pointsIndex]);
                    if (drawAsShape) whichPGraphicsToDrawOn.vertex(curPosX, points[pointsIndex]);
                    curPosY = points[pointsIndex];
                    pointsIndex += 1;
                  }
                  else if (command ==  SVG_COMMAND_VERTICAL) {
                    if (drawOutline) whichPGraphicsToDrawOn.line(curPosX,curPosY, curPosX, curPosY + points[pointsIndex]);
                    if (drawAsShape) whichPGraphicsToDrawOn.vertex( curPosX, curPosY + points[pointsIndex]);
                    curPosY += points[pointsIndex];
                    pointsIndex += 1;
                  }
                  else if (command ==  SVG_COMMAND_LINETO) {
                    if (drawOutline) whichPGraphicsToDrawOn.line(curPosX,curPosY, points[pointsIndex], points[pointsIndex + 1]);
                    if (drawAsShape) whichPGraphicsToDrawOn.vertex( points[pointsIndex], points[pointsIndex + 1]);
                    curPosX = points[pointsIndex];
                    curPosY = points[pointsIndex + 1];
                    pointsIndex += 2;
                  }
                  else if (command ==  SVG_COMMAND_LINETO_RELATIVE) {
                    if (drawOutline) whichPGraphicsToDrawOn.line(curPosX,curPosY, curPosX + points[pointsIndex], curPosY + points[pointsIndex + 1]);
                    if (drawAsShape) whichPGraphicsToDrawOn.vertex( curPosX + points[pointsIndex], curPosY + points[pointsIndex + 1]);
                    curPosX += points[pointsIndex];
                    curPosY += points[pointsIndex + 1];
                    pointsIndex += 2;
                  }
                  else if (command ==  SVG_COMMAND_CLOSEPATH) {
                    //println("found a closepath command");
                    if (drawAsShape) whichPGraphicsToDrawOn.endShape(CLOSE);
                    shapeBegan = false;
                  }
                  else if (command ==  SVG_COMMAND_DRAWHOLE_START) {
                    //println("start of a hole");
                    whichPGraphicsToDrawOn.fill(0);
                    pointsIndex ++;
                  }
                  else if (command ==  SVG_COMMAND_DRAWHOLE_END) {
                    //println("end of a hole");
                    whichPGraphicsToDrawOn.fill(255);
                    pointsIndex ++;
                  }
                  

                  commandIndex++;

                }
                
                // let's end the shape if the patch commands forgot to
                if (shapeBegan && drawAsShape) whichPGraphicsToDrawOn.endShape(CLOSE);


              }
            
            void parseOneFloat() {
                 // println("parsing 1 float");
                   skipSpacesOrCommas();
                  while (!isCommand()) {
                    commands[commandIndex] = lastCommand; commandIndex++;
                    skipSpacesOrCommas();
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                    skipSpacesOrCommas();
                    if (parsingIndex == stringToParse.length()-1) {
                      return;
                    }
                  }
            }

            void parseTwoFloats() {
                  //println("called parseFourFloats");
                   skipSpacesOrCommas();
                  while (!isCommand()) {
                    commands[commandIndex] = lastCommand; commandIndex++;
                    skipSpacesOrCommas();
                  //println("parsing 1/2");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 2/2");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                    skipSpacesOrCommas();
                    if (parsingIndex == stringToParse.length()-1) {
                      return;
                    }
                  }
            }

            void parseFourFloats() {
                  //println("called parseFourFloats");
                   skipSpacesOrCommas();
                  while (!isCommand()) {
                    commands[commandIndex] = lastCommand; commandIndex++;
                    skipSpacesOrCommas();
                  //println("parsing 1/4");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 2/4");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 3/4");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 4/4");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                    skipSpacesOrCommas();
                    if (parsingIndex == stringToParse.length()-1) {
                      return;
                    }

                  }
            }

            void parseSixFloats() {
                  //println("called parseSixFloats function");
                   skipSpacesOrCommas();
                  while (!isCommand()) {
                  //println("parsing 6 floats");
                    commands[commandIndex] = lastCommand; commandIndex++;
                    skipSpacesOrCommas();
                  //println("parsing 6 floats 1/6");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 6 floats 2/6");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 6 floats 3/6");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 6 floats 4/6");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 6 floats 5/6");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                  //println("parsing 6 floats 6/6");
                    points[pointsIndex] = parseNumber(); pointsIndex ++ ;
                    skipSpacesOrCommas();
                    if (parsingIndex == stringToParse.length()-1) {
                      return;
                    }

                  }
            }

              void parseCommands() {
                while (parseCommand()) {
                  //println("parsing a command");
                }
              }
              
              boolean parseCommand() {
              String char1;
              
                if(parsingIndex == stringToParse.length())
                  return false;

                char1 = stringToParse.charAt(parsingIndex) + "";
                if (char1.equals("M")) {
                  lastCommand = SVG_COMMAND_MOVE;
                  //println("found M");
                  parsingIndex++;
                  parseTwoFloats();
                  //println("finished with M");
                }
                else if (char1.equals("m")) {
                  lastCommand = SVG_COMMAND_MOVE_RELATIVE;
                  //println("found m");
                  parsingIndex++;
                  parseTwoFloats();
                }
                else if (char1.equals("Z")) {
                  //println("found Z");
                  lastCommand = SVG_COMMAND_CLOSEPATH;
                  commands[commandIndex] = lastCommand; commandIndex++;
                  parsingIndex++;
                }
                else if (char1.equals("z")) {
                  //println("found z");
                  lastCommand = SVG_COMMAND_CLOSEPATH;
                  commands[commandIndex] = lastCommand; commandIndex++;
                  parsingIndex++;
                }
                else if (char1.equals("L")) {
                  lastCommand = SVG_COMMAND_LINETO;
                  //println("found L");
                  parsingIndex++;
                  parseTwoFloats();
                }
                else if (char1.equals("l")) {
                  lastCommand = SVG_COMMAND_LINETO_RELATIVE;
                  //println("found l");
                  parsingIndex++;
                  parseTwoFloats();
                }
                else if (char1.equals("H")) {
                  lastCommand = SVG_COMMAND_HORIZONTAL;
                  //println("found H");
                  parsingIndex++;
                  parseOneFloat();
                }
                else if (char1.equals("h")) {
                  lastCommand = SVG_COMMAND_HORIZONTAL_RELATIVE;
                  //println("found h");
                  parsingIndex++;
                  parseOneFloat();
                }
                else if (char1.equals("V")) {
                  lastCommand = SVG_COMMAND_VERTICAL;
                  //println("found V");
                  parsingIndex++;
                  parseOneFloat();
                }
                else if (char1.equals("v")) {
                  lastCommand = SVG_COMMAND_VERTICAL_RELATIVE;
                  //println("found v");
                  parsingIndex++;
                  parseOneFloat();
                }
                else if (char1.equals("C")) {
                  lastCommand = SVG_COMMAND_CURVE;
                  //println("found C");
                  parsingIndex++;
                  parseSixFloats();
                }
                else if (char1.equals("c")) {
                  lastCommand = SVG_COMMAND_CURVE_RELATIVE;
                  //println("found c");
                  parsingIndex++;
                  parseSixFloats();
                }
                else if (char1.equals("S")) {
                  lastCommand = SVG_COMMAND_SMOOTHCURVE;
                  //println("found S");
                  parsingIndex++;
                  parseFourFloats();
                }
                else if (char1.equals("s")) {
                  lastCommand = SVG_COMMAND_SMOOTHCURVE_RELATIVE;
                  //println("found s");
                  parsingIndex++;
                  parseFourFloats();
                }
                else if (char1.equals("Q")) {
                  lastCommand = SVG_COMMAND_QUADRATIC;
                  //println("found Q");
                  parsingIndex++;
                  parseFourFloats();
                }
                else if (char1.equals("q")) {
                  lastCommand = SVG_COMMAND_QUADRATIC_RELATIVE;
                  //println("found q");
                  parsingIndex++;
                  parseFourFloats();
                }
                else if (char1.equals("T")) {
                  lastCommand = SVG_COMMAND_QUADRATIC_SMOOTH;
                  //println("found T");
                  parsingIndex++;
                  parseTwoFloats();
                }
                else if (char1.equals("t")) {
                  lastCommand = SVG_COMMAND_QUADRATIC_SMOOTH_RELATIVE;
                  //println("found t");
                  parsingIndex++;
                  parseTwoFloats();
                }
                else if (char1.equals("K")) {
                  lastCommand = SVG_COMMAND_DRAWHOLE_START;
                  //println("found K");
                  parsingIndex++;
                  parseOneFloat();
                }
                else if (char1.equals("W")) {
                  lastCommand = SVG_COMMAND_DRAWHOLE_END;
                  //println("found W");
                  parsingIndex++;
                  parseOneFloat();
                }


                print(" have parsed  "+ commandIndex +" commands and " + pointsIndex + " floats");
                numberOfParsedCommands = commandIndex;

                return true;

                //println("character "+ parsingIndex +" is: " + char1);
                //println(parseFloat("10")+0.1+"");

              }
            
            
/*
           void skipSpaces() {
                if (parsingIndex == stringToParse.length()) return;
              while( (stringToParse.charAt(parsingIndex)+"").equals(" ")) {
                if (parsingIndex == stringToParse.length()) return;
                parsingIndex++;
              }
            } // end of method
*/
           boolean isSpacesOrCommaOrLineReturn() {
              return ((stringToParse.charAt(parsingIndex)+"").equals(" ") || (stringToParse.charAt(parsingIndex)+"").equals(comma) || (stringToParse.charAt(parsingIndex)+"").equals("\n"));
            } // end of method

           void skipSpacesOrCommas() {
                if (parsingIndex == stringToParse.length()) return;
              while(isSpacesOrCommaOrLineReturn()){
                if (parsingIndex == stringToParse.length()) return;
                parsingIndex++;
              }
            } // end of method

           float parseNumber() {
             String accumulatedString = "";
             skipSpacesOrCommas();
             while(  !isSpacesOrCommaOrLineReturn() && !isCommand()) {
               accumulatedString = accumulatedString + stringToParse.charAt(parsingIndex);
               parsingIndex++;
               if (parsingIndex == stringToParse.length()) {
                 print(" just parsed a float: " + parseFloat(accumulatedString));
                 return parseFloat(accumulatedString);
               }               
               if ((stringToParse.charAt(parsingIndex)+"").equals("-")) break;
             }
             print(" just parsed a float: " + parseFloat(accumulatedString));
             return parseFloat(accumulatedString);
            } // end of method

           boolean isCommand() {
             
             if (parsingIndex == stringToParse.length()) return true;
             
             // check if we are at the end of the svg
             //if (parsingIndex == stringToParse.length()-1) return false;
             
              //println("checking if "+ stringToParse.charAt(parsingIndex)+" is a command");

              if(
              (stringToParse.charAt(parsingIndex)+"").equals("M") ||
              (stringToParse.charAt(parsingIndex)+"").equals("m") ||
              (stringToParse.charAt(parsingIndex)+"").equals("Z") ||
              (stringToParse.charAt(parsingIndex)+"").equals("z") ||
              (stringToParse.charAt(parsingIndex)+"").equals("L") ||
              (stringToParse.charAt(parsingIndex)+"").equals("l") ||
              (stringToParse.charAt(parsingIndex)+"").equals("H") ||
              (stringToParse.charAt(parsingIndex)+"").equals("h") ||
              (stringToParse.charAt(parsingIndex)+"").equals("V") ||
              (stringToParse.charAt(parsingIndex)+"").equals("v") ||
              (stringToParse.charAt(parsingIndex)+"").equals("C") ||
              (stringToParse.charAt(parsingIndex)+"").equals("c") ||
              (stringToParse.charAt(parsingIndex)+"").equals("S") ||
              (stringToParse.charAt(parsingIndex)+"").equals("s") ||
              (stringToParse.charAt(parsingIndex)+"").equals("Q") ||
              (stringToParse.charAt(parsingIndex)+"").equals("q") ||
              (stringToParse.charAt(parsingIndex)+"").equals("T") ||
              (stringToParse.charAt(parsingIndex)+"").equals("t") ||
              (stringToParse.charAt(parsingIndex)+"").equals("W") ||
              (stringToParse.charAt(parsingIndex)+"").equals("K")
              ) {
              //println(" yes it is");
              return true;
            }
            else {
              //println(" no it isn't ");
              return false;
            }
           }


          } // end of class

