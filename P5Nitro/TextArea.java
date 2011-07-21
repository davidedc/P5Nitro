/*
Copyright (C) 2011 by all P5Nitro contributors
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

// Bugs:
//  - it seems that when you click on the mouse past the end of
//    the line on the non-wrapping view, sometimes you can confus
//    the system and the cursor ends up past the end point of the line
//    the tab should be painted as some kind of four-spaces but it's not

// Questions:
//  - does the cursor move right when in wrapped mode?
//  - can you select a cursor position with the mouse in the wrapped box?

// Limitations:
//  - no selection
//  - no cut-copy-paste
//  - the caret y position doesn't maintain accross lines if you go accross lines
//    that are shorter. E.g. if you are on char 3, move up to an empty line, then
//    move up in a long line, in normal editors your cursor is on char 3 but in this
//    one is on char 0 because the cursor came accross an empty line.

// planned changes:
//   * there should be a checkbox or some kind of switch that lets you edit
//     in wrapped mode or in non-wrapped mode.
//   * detect when the line is pushed over the margin, rather than the cursor being over
//     the margin
//   * add some place for the "wrapping" data structures

import java.util.ArrayList;
import java.lang.StringBuffer;
import processing.core.*;
import java.awt.datatransfer.Clipboard;
//import java.awt.datatransfer.ClipboardOwner;
import java.awt.datatransfer.Transferable;
//import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.Toolkit;
import java.io.IOException;

class TextArea {
  P5Nitro p;
  int xPos, yPos, lineHeight = 24, firstVisibleLineNumber = 0, width = 0, fontSize = 10, height = 0;
  PFont font;
  float visibleLines = 0;
  float scalingFactor = 1;
  boolean P5NitroMode;
  String allText = "";
  float oldScaleFactor = 0;

  ArrayList nonWrappingLinesArrayList = new ArrayList(1);
  ArrayList wrappingLinesArrayList = new ArrayList();
  ArrayList wrappedLinesConsumedCharactersArrayList = new ArrayList();

  Cursor theNonWrappingCursor;
  Cursor theWrappingCursor;
  int bgColor = 0;
  int textColor = 255;
  boolean controllingTheWrappingCursor = false;

  public TextArea(P5Nitro parent, int x, int y, int w, int h, int bgColor, int textColor, int fontSize, boolean controllingTheWrappingCursor, boolean P5NitroMode) {
    this( parent, x, y, w, h);
    this.fontSize = fontSize;
    this.bgColor = bgColor;
    this.textColor = textColor;
    this.P5NitroMode = P5NitroMode;
    font = p.createFont("DejaVu Sans Mono", fontSize);
    lineHeight = fontSize + 2;
    this.controllingTheWrappingCursor = controllingTheWrappingCursor;
  }

  public TextArea(P5Nitro parent, int x, int y, int w, int h) {
    controllingTheWrappingCursor = true;
    p = parent;
    xPos = x;
    yPos = y;
    width = w;
    height = h;
    font = p.createFont("DejaVu Sans Mono", fontSize);
    lineHeight = fontSize + 2;
    // add the first empty line
    nonWrappingLinesArrayList.add(new StringBuffer());
    visibleLines = (int)(((float)height / (float)lineHeight) - 1);
    System.out.println(visibleLines);

    theNonWrappingCursor = new Cursor(this);
    theWrappingCursor = new Cursor(this);
  }

  public StringBuffer currentLine() {
    if (controllingTheWrappingCursor) {
      System.out.println("the wrapped contents of where the cursor is: " + wrappingLinesArrayList.get(theNonWrappingCursor.cursorLine));
      StringBuffer tmp = (StringBuffer)wrappingLinesArrayList.get(theNonWrappingCursor.cursorLine);
      return tmp; 
      //return (StringBuffer)wrappingLinesArrayList.get(theNonWrappingCursor.cursorLine);
    }
    else {
      return (StringBuffer)nonWrappingLinesArrayList.get(theNonWrappingCursor.cursorLine);
    }
  }

  public void keyPressed(char key, int keyCode, boolean controlKeyPressed) {

    Cursor affectedCursor;  
    if (!controllingTheWrappingCursor) {
      affectedCursor = theNonWrappingCursor;
    }
    else {
      affectedCursor = theWrappingCursor;
    }


    if (key == PConstants.ENTER || key == PConstants.RETURN) {
      newLine();
    } 
    else if (key == PConstants.TAB) {
      currentLine().insert(theNonWrappingCursor.cursorChar, "\t");
      affectedCursor.advanceCursorByChar();
    } 
    else if (key == PConstants.CODED) {
      if (keyCode == PConstants.LEFT && controlKeyPressed == false) {
        affectedCursor.retreatCursorByChar();
      }
      else if (keyCode == PConstants.LEFT && controlKeyPressed == true) {
        affectedCursor.retreatCursorByWord();
      } 
      else if (keyCode == PConstants.RIGHT && controlKeyPressed == false) {
        affectedCursor.advanceCursorByChar();
      } 
      else if (keyCode == PConstants.RIGHT && controlKeyPressed == true) {
        affectedCursor.advanceCursorByWord();
      } 
      else if (keyCode == PConstants.UP) {
        affectedCursor.changeLine(-1);
      } 
      else if (keyCode == PConstants.DOWN) {
        affectedCursor.changeLine(1);
      } 
      else if (keyCode == java.awt.event.KeyEvent.VK_HOME) {
        affectedCursor.cursorChar = 0;
      } 
      else if (keyCode == java.awt.event.KeyEvent.VK_END) {
        affectedCursor.cursorChar = currentLine().length();
      }
    } 
    else if (key == PConstants.BACKSPACE) {
      backwardDeleteChar();
    } 
    else if (key != PConstants.CODED && controlKeyPressed) {
      if (keyCode == 85) {
        P5Nitro.theTextArea.clearCurrentLine();
      } 
      else if (keyCode == 45) {
        P5Nitro.theTextArea.zoomOut();
      } 
      else if (keyCode == 61) {
        P5Nitro.theTextArea.zoomIn();
      }
      if (keyCode == 86 ) {
        //clear();
        System.out.println("pasting: " + getClipboardContents());
        String lines[] = getClipboardContents().split("\\r?\\n");
        System.out.println("how many lines: " + lines.length);
        for (int linNum = 0; linNum < lines.length; linNum++) {
          nonWrappingLinesArrayList.add(new StringBuffer(lines[linNum] ));
        }
        System.out.println("end pasting");
      }
    } 
    else {

      // ok here we are adding a character that
      // the user has just typed
      System.out.println("adding a char");
      System.out.println("to the line: >"+ currentLine() +"<");
      System.out.println("in position "+ theNonWrappingCursor.cursorChar);
      currentLine().insert(theNonWrappingCursor.cursorChar, key);
      System.out.println("ok after the update the line is : >"+ currentLine() +"<");
      affectedCursor.cursorChar++;
    }

    if (theNonWrappingCursor.cursorLine > firstVisibleLineNumber + (int)visibleLines) {
      firstVisibleLineNumber++;
    } 
    else if (theNonWrappingCursor.cursorLine < firstVisibleLineNumber) {
      firstVisibleLineNumber--;
    }

    checkVerticalPosition();
    theNonWrappingCursor.updateCursorPosition();

    if (controllingTheWrappingCursor && theNonWrappingCursor.cursorX > width && key == ' ') {
      newLine();
    }
  }

  public void mousePressed(int mX, int mY) {
    System.out.println(mY - yPos);
    if (mY - yPos > 0) {
      int targetLine = (int)(((mY - yPos) / lineHeight));
      if (targetLine < nonWrappingLinesArrayList.size()) {
        theNonWrappingCursor.cursorLine = (int)(((mY - yPos) / lineHeight));
      }
    }
    StringBuffer l = (StringBuffer)nonWrappingLinesArrayList.get(theNonWrappingCursor.cursorLine);
    System.out.println(l.length());
    for (int i = 0; i < l.length(); i++) {
      String stringBeforeCaret = l.substring(0, i);
      float charPos = (float)p.textWidth(stringBeforeCaret) * scalingFactor;
      System.out.println((float)mX - (float)xPos);
      System.out.println(charPos);
      if (charPos > (float)mX - (float)xPos) {

        theNonWrappingCursor.cursorChar = i;
        theNonWrappingCursor.updateCursorPosition();
        break;
      }
    }
  }


  private void checkVerticalPosition() {
    if ((((theNonWrappingCursor.cursorLine - firstVisibleLineNumber) * lineHeight) + lineHeight + yPos) > height + yPos) {
      firstVisibleLineNumber++;
    }
  }

  private void newLine() {
    String restOfLine = "";

    if (theNonWrappingCursor.cursorChar == 0) {
      nonWrappingLinesArrayList.add(theNonWrappingCursor.cursorLine, new StringBuffer());
    } 
    else {
      nonWrappingLinesArrayList.add(theNonWrappingCursor.cursorLine + 1, new StringBuffer());
      restOfLine = currentLine().substring(theNonWrappingCursor.cursorChar);
      currentLine().setLength(theNonWrappingCursor.cursorChar);
    }
    if (!controllingTheWrappingCursor) {

      theNonWrappingCursor.cursorLine++;
    }
    else {
      theWrappingCursor.advanceCursorByChar();
    }
    currentLine().append(restOfLine);
    theNonWrappingCursor.cursorChar = 0;
    theNonWrappingCursor.cursorX = 0;
    checkVerticalPosition();
  }


  private void backwardDeleteChar() {

    if (currentLine().length() > 0 && theNonWrappingCursor.cursorChar > 0) {
      currentLine().deleteCharAt(theNonWrappingCursor.cursorChar - 1);
      theNonWrappingCursor.cursorChar--;
    } 
    else if (theNonWrappingCursor.cursorChar == 0 && theNonWrappingCursor.cursorLine != 0) {
      String restOfLine = currentLine().toString();
      theNonWrappingCursor.cursorLine--;
      nonWrappingLinesArrayList.remove(theNonWrappingCursor.cursorLine + 1);
      theNonWrappingCursor.cursorChar = currentLine().length();
      currentLine().append(restOfLine);
    }
    if (controllingTheWrappingCursor) {

      theWrappingCursor.retreatCursorByChar();
    }
  }

  public void clearCurrentLine() {
    currentLine().delete(0, currentLine().length() - 1);
  }

  public void zoomIn() {
    scalingFactor += 0.1;
    visibleLines = (float)p.height / ((float)lineHeight * scalingFactor);
  }

  public void zoomOut() {
    if (scalingFactor > 0.1) {
      scalingFactor -= 0.1;
      visibleLines = (float)p.height / ((float)lineHeight * scalingFactor);
    }
  }

  public void setContents(ArrayList text) {
    nonWrappingLinesArrayList = text;
    theNonWrappingCursor.cursorLine = 0;
    theNonWrappingCursor.cursorX = 0;
  }

  public String getContents() {
    String contents = "";
    for (int i=0; i<nonWrappingLinesArrayList.size(); i++) {
      contents += nonWrappingLinesArrayList.get(i).toString();
      contents += '\n';
    }
    return contents;
  }

  public String[] getContentsArray() {
    String[] contents = new String[nonWrappingLinesArrayList.size()];
    for (int i=0; i<nonWrappingLinesArrayList.size(); i++) {
      contents[i] = nonWrappingLinesArrayList.get(i).toString();
    }
    return contents;
  }

  public void clear() {
    nonWrappingLinesArrayList.clear();
    currentLine().setLength(0);
    theNonWrappingCursor.cursorX = 0;
  }

  public void draw(P5Nitro p5nitroPApplet) {

    if (P5NitroMode) {
      p5nitroPApplet.stroke(0);
      p5nitroPApplet.fill (41, 40, 41);
      p5nitroPApplet.rect(0, 0, 500, 70);

      // draw the play button
      p5nitroPApplet.fill(255);
      p5nitroPApplet.stroke(255);
      p5nitroPApplet.smooth();
      p5nitroPApplet.ellipse(40, 35, 45, 45);
      p5nitroPApplet.fill(41, 40, 41);
      p5nitroPApplet.stroke(41, 40, 41);
      p5nitroPApplet.triangle(35, 25, 50, 35, 35, 45);

      // draw the stop button
      p5nitroPApplet.fill(255);
      p5nitroPApplet.stroke(255);
      p5nitroPApplet.smooth();
      p5nitroPApplet.ellipse(110, 35, 45, 45);
      p5nitroPApplet.fill(41, 40, 41);
      p5nitroPApplet.stroke(41, 40, 41);
      p5nitroPApplet.rect(103, 28, 15, 15);
    }


    p5nitroPApplet.fill(bgColor);

    if (!P5NitroMode) {
      p5nitroPApplet.rect(xPos, yPos, width, height);
    }

    int linesOnScreen = 0;

    if (!P5NitroMode) {
      p.text("Unwrapped text", 2, 15);
      p.text("Wrapped text", 400, 15);
      p.text("Chars in each wrapped line", 700, 15);
    }

    //////////////////////////////////////////////////////////////////////
    // find out where the non-wrapping cursor is in terms of
    //   number of characters
    //////////////////////////////////////////////////////////////////////    

    if (nonWrappingLinesArrayList.size() < visibleLines) {
      linesOnScreen = nonWrappingLinesArrayList.size();
    } 
    else {
      linesOnScreen = (int)visibleLines + 1;
    }

    int numberOfCaharctersToLeftOfNonWrappingCursor = 0;
    for (int i = 0; i< theNonWrappingCursor.cursorLine; i++) {
      numberOfCaharctersToLeftOfNonWrappingCursor += nonWrappingLinesArrayList.get(i).toString().length() + 1;
    }
    numberOfCaharctersToLeftOfNonWrappingCursor +=  theNonWrappingCursor.cursorChar;

    if (!P5NitroMode) {
      p.text("Position of non-wrapping cursor : Line " + theNonWrappingCursor.cursorLine + " Column "+ theNonWrappingCursor.cursorChar + " Text position: " + numberOfCaharctersToLeftOfNonWrappingCursor, 2, 370);
    }

    //////////////////////////////////////////////////////////////////////
    // draw the non-wrapping text
    //////////////////////////////////////////////////////////////////////        

    float maximumTextWidth = 0;
    for (int i = firstVisibleLineNumber; i<linesOnScreen + firstVisibleLineNumber && i < nonWrappingLinesArrayList.size(); i++) {
      float theTextWidth = p.textWidth(nonWrappingLinesArrayList.get(i).toString());
      if (theTextWidth > maximumTextWidth) maximumTextWidth = theTextWidth;
    }
    float newScalingFactor = 500/(maximumTextWidth+10);
    scalingFactor = (float)(0.9*oldScaleFactor + 0.1*newScalingFactor);
    oldScaleFactor = scalingFactor;

    p.fill(textColor);
    p.stroke(0xffffffff);
    p.translate(0, 535/2 - lineHeight);
    p.scale(scalingFactor);
    p.translate(0, (int)(((-nonWrappingLinesArrayList.size()))*(lineHeight/2)));
    //p.translate(-xPos,-yPos - lineHeight);
    p.textFont(font);

    for (int i = firstVisibleLineNumber; i<linesOnScreen + firstVisibleLineNumber && i < nonWrappingLinesArrayList.size(); i++) {
      p.text(nonWrappingLinesArrayList.get(i).toString(), 0, lineHeight + ((i - firstVisibleLineNumber) * lineHeight));
    }

    //////////////////////////////////////////////////////////////////////
    // draw the non-wrapping cursor
    //////////////////////////////////////////////////////////////////////        

    p.stroke(255, 0, 0, (int)(p.sin((float)(p.frameCount/10.0))*255.0));
    // p.stroke(textColor);
    p.line(  theNonWrappingCursor.cursorX, ((theNonWrappingCursor.cursorLine - firstVisibleLineNumber) * lineHeight) + 5, theNonWrappingCursor.cursorX, ((theNonWrappingCursor.cursorLine - firstVisibleLineNumber) * lineHeight) + lineHeight );
    //p.line( theNonWrappingCursor.cursorX, ((theNonWrappingCursor.cursorLine - firstVisibleLineNumber) * lineHeight) + 5 + yPos,   theNonWrappingCursor.cursorX, ((theNonWrappingCursor.cursorLine - firstVisibleLineNumber) * lineHeight) + lineHeight + yPos);

    allText = "";
    for (int i = 0; i < nonWrappingLinesArrayList.size(); i++) {
      allText += nonWrappingLinesArrayList.get(i).toString()+"\n";
    }

    // ***********************************************
    // from here on, this part takes care of
    // the wrapping text
    // ***********************************************

    if (P5NitroMode) return;

    //////////////////////////////////////////////////////////////////////
    // wrap the text
    //////////////////////////////////////////////////////////////////////        

    String word = "";
    float columnSize = 200;
    int columnPixelPos = 0;
    int lineNumber = 0;
    int textScanner = 0;

    wrappingLinesArrayList = new ArrayList();
    wrappedLinesConsumedCharactersArrayList = new ArrayList();

    wrappingLinesArrayList.add(new StringBuffer());
    wrappedLinesConsumedCharactersArrayList.add(new Integer(0));

    // this thing tokenizes out words
    // I know that there is a ready-made Java class
    // that does that, but I want to try to make
    // this as self-contained as possible

    while (true) {
      word = "";      
      for (int i = textScanner; i < allText.length(); i++) {
        if (word == "" && allText.charAt(i)==' ') {
          word = " ";
          textScanner = i+1;
          break;
        }
        if (word == "" && allText.charAt(i)=='\n') {
          word = "\n";
          textScanner = i+1;
          break;
        }
        if (allText.charAt(i)=='\n') {
          textScanner = i;
          break;
        }
        else if (allText.charAt(i)==' ') {
          textScanner = i;
          break;
        }
        else {
          word += allText.charAt(i);
          textScanner = i;
        }
      } // this brace closes the for, not the while(true)

      // we got a token. A token can be something like this:
      //   - a space
      //   - a new line
      //   - a word without any trailing space or new line

      //println("word is >" + word +"<");
      if (word == "") break;

      // add this word to the line
      String newLine = "";


      // here we check whether the word by itself is too big
      // to fit the allocated space
      // this is the only case where we are forced to break
      // a word into multiple lines.
      float potentialWordLength = (float)p.textWidth(word) * scalingFactor;

      if (potentialWordLength > columnSize) {
        for (int k = 0; k < word.length();k++) {
          //if (wrappingLinesArrayList.size()!=0)
          newLine  = (wrappingLinesArrayList.get(lineNumber)).toString()+ word.charAt(k);
          //else
          //  newLine  = ""+ word.charAt(k);
          float newLineLength = (float)p.textWidth(newLine) * scalingFactor;

          if (newLineLength > columnSize) {
            wrappedLinesConsumedCharactersArrayList.set(lineNumber, new Integer(newLine.length()));
            lineNumber++;
            if (wrappingLinesArrayList.size() < lineNumber+1)
              wrappingLinesArrayList.add(new StringBuffer());
            wrappedLinesConsumedCharactersArrayList.add(new Integer(0));

            wrappingLinesArrayList.set(lineNumber, new StringBuffer(""+word.charAt(k)));
            wrappedLinesConsumedCharactersArrayList.set(lineNumber, new Integer(1));
          }
          else {
            wrappingLinesArrayList.set(lineNumber, new StringBuffer(newLine));
            wrappedLinesConsumedCharactersArrayList.set(lineNumber, new Integer(newLine.length()));
          }
        }
      }
      else {

        if (word != "\n") {
          newLine  = (String)(wrappingLinesArrayList.get(lineNumber).toString())+word;
        }
        //     wrappingLinesArrayList.set(i,(String)(wrappingLinesArrayList.get(i))+word);
        float potentialLineLength = (float)p.textWidth(newLine) * scalingFactor;

        if (word == "\n") {
          wrappedLinesConsumedCharactersArrayList.set(lineNumber, wrappingLinesArrayList.get(lineNumber).toString().length()+2);

          lineNumber++;
          if (wrappingLinesArrayList.size() < lineNumber+1) {
            wrappingLinesArrayList.add(new StringBuffer());
            wrappedLinesConsumedCharactersArrayList.add(new Integer(0));
          }
        }
        else if (potentialLineLength > columnSize) {
          wrappedLinesConsumedCharactersArrayList.set(lineNumber, wrappingLinesArrayList.get(lineNumber).toString().length() + 1);
          lineNumber++;
          if (wrappingLinesArrayList.size() < lineNumber+1) {
            wrappingLinesArrayList.add(lineNumber, new StringBuffer(word));
            wrappedLinesConsumedCharactersArrayList.add(new Integer(0));
          }
        }
        else {
          wrappingLinesArrayList.set(lineNumber, new StringBuffer(newLine));
          wrappedLinesConsumedCharactersArrayList.set(lineNumber, newLine.length());
        }
      }
    }

    //////////////////////////////////////////////////////////////////////
    // draw the wrapped cursor
    //////////////////////////////////////////////////////////////////////        

    //println("the cursor is at char "+theWrappingCursor.cursorChar);
    //println("how many lines: "+wrappingLinesArrayList.size());

    int whereToPlaceTheCursorChar = 0;
    int rememberWhichLineTheCursorIs = 0;
    int rememberWhereThecursorShouldBe = 0;
    boolean breakAllNow = false;

    int firstCharAdj = 0;
    int cursorAdj = 0;

    //if (!breakAllNow && wrappingLinesArrayList.get(0).toString() != "") firstCharAdj++;
    //println(whereToPlaceTheCursorChar+"/"+allText.length());
    if (allText.length()>0) System.out.println(allText.charAt(whereToPlaceTheCursorChar));
    System.out.println("line"+rememberWhichLineTheCursorIs);
    System.out.println("line length "+((String)wrappingLinesArrayList.get(rememberWhichLineTheCursorIs).toString()).length());

    int finalCursorPos;
    String textBeforeCursor;

    //println("the cursor should be at " + rememberWhereThecursorShouldBe);
    //println("the cursor is at line " + rememberWhichLineTheCursorIs + " after " + textBeforeCursor);
    int cursorXPos;
    int cursorYPos;

    int keepingTabOfCursor = 0;
    int cursorRow = -1;
    int cursorColumn = 0;


    cursorRow = theWrappingCursor.cursorLine-1;
    cursorColumn =  theWrappingCursor.cursorChar;
    if (cursorColumn == -1) cursorColumn = 0;
    if (cursorRow == -1) cursorRow = 0;

    System.out.println("the cursor column " + cursorColumn);
    System.out.println("the cursor row " + cursorRow);
    System.out.println("numberOfLines " + wrappingLinesArrayList.size());
    System.out.println("wrapped text line at cursor position: >"+wrappingLinesArrayList.get(cursorRow).toString()+"< of length: " + wrappingLinesArrayList.get(cursorRow).toString().length());

    p5nitroPApplet.translate(400, 0);
    p5nitroPApplet.stroke(0, 255, 0);

    if (cursorColumn <= wrappingLinesArrayList.get(cursorRow).toString().length()) {
      //int finalCursorPos = cursorAdj + min(rememberWhereThecursorShouldBe+1, wrappingLinesArrayList.get(rememberWhichLineTheCursorIs).toString().length());
      textBeforeCursor = wrappingLinesArrayList.get(cursorRow).toString().substring(0, cursorColumn);

      cursorXPos = (int)((xPos  + (float)p.textWidth(textBeforeCursor) * scalingFactor));
      //cursorXPos = (int)((xPos  + (float)p.textWidth(textBeforeCursor)));
      cursorYPos = yPos + 10 + ((cursorRow) * lineHeight);

      p5nitroPApplet.line(cursorXPos-1, cursorYPos+10, cursorXPos+2, cursorYPos-3);
    }

    //////////////////////////////////////////////////////////////////////
    // draw the wrapped the text
    //////////////////////////////////////////////////////////////////////        

    for (int i = 0; i<wrappingLinesArrayList.size(); i++) {
      p.text(wrappingLinesArrayList.get(i).toString(), xPos, yPos + lineHeight + (i * lineHeight));
    }

    //////////////////////////////////////////////////////////////////////
    // draw the number of characters of each wrapped line
    //////////////////////////////////////////////////////////////////////        
    p5nitroPApplet.translate(300, 0);

    int copyOfNumberOfCaharctersToLeftOfNonWrappingCursor = numberOfCaharctersToLeftOfNonWrappingCursor;
    int lineOfWrappingCursorBasedOnNonWrappingCursor = 0;
    int columnOfWrappingCursorBasedOnNonWrappingCursor = 0;
    boolean rightCursorCalculated = false;

    for (int i = 0; i < wrappedLinesConsumedCharactersArrayList.size() - 1; i++) {
      int numberOfChars = ((Integer)(wrappedLinesConsumedCharactersArrayList.get(i))).intValue();
      if ( i == wrappedLinesConsumedCharactersArrayList.size() -2) {
        numberOfChars--;
      }
      numberOfChars--;
      p.text(numberOfChars+"", xPos, yPos + lineHeight + (i * lineHeight));
      copyOfNumberOfCaharctersToLeftOfNonWrappingCursor -= numberOfChars;
      if (copyOfNumberOfCaharctersToLeftOfNonWrappingCursor <= 0 && !rightCursorCalculated) {
        lineOfWrappingCursorBasedOnNonWrappingCursor = i + 1;
        columnOfWrappingCursorBasedOnNonWrappingCursor = copyOfNumberOfCaharctersToLeftOfNonWrappingCursor +   numberOfChars;

        if (numberOfCaharctersToLeftOfNonWrappingCursor != 0) {
          if (allText.charAt(numberOfCaharctersToLeftOfNonWrappingCursor-1) == '\n') {
            lineOfWrappingCursorBasedOnNonWrappingCursor++;
            columnOfWrappingCursorBasedOnNonWrappingCursor = 0;
          }
        }
        else {
          lineOfWrappingCursorBasedOnNonWrappingCursor= 0;
          columnOfWrappingCursorBasedOnNonWrappingCursor = 0;
        }

        rightCursorCalculated = true;
      }
    }

    p.text("Position of wrappig cursor: Line " + lineOfWrappingCursorBasedOnNonWrappingCursor + " Column "+ columnOfWrappingCursorBasedOnNonWrappingCursor, 2, 370);
    theWrappingCursor.cursorChar = columnOfWrappingCursorBasedOnNonWrappingCursor;
    theWrappingCursor.cursorLine = lineOfWrappingCursorBasedOnNonWrappingCursor;

    p5nitroPApplet.resetMatrix();
  }

  /**
   * Get the String residing on the clipboard.
   *
   * @return any text found on the Clipboard; if none found, return an
   * empty String.
   */
  public String getClipboardContents() {
    System.out.println("about to get clipboard content");
    String result = "";
    Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
    //odd: the Object param of getContents is not currently used
    Transferable contents = clipboard.getContents(null);
    boolean hasTransferableText =
      (contents != null) &&
      contents.isDataFlavorSupported(DataFlavor.stringFlavor);
    if ( hasTransferableText ) {
      try {
        result = (String)contents.getTransferData(DataFlavor.stringFlavor);
      }
      catch (UnsupportedFlavorException ex) {
        //highly unlikely since we are using a standard DataFlavor
        System.out.println(ex);
        ex.printStackTrace();
      }
      catch (IOException ex) {
        System.out.println(ex);
        ex.printStackTrace();
      }
    }
    return result;
  }
}

