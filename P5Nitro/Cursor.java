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

public class Cursor {
  
  int cursorChar = 0, cursorLine = 0;
  public TextArea textArea;
  float cursorX = 0;

  public Cursor(TextArea textArea){
    this.textArea = textArea;
  }

  public void advanceCursorByWord() {
    
    int currentLineLength = textArea.currentLine().length();

    int c = cursorChar;
    if(cursorChar == currentLineLength) {
      if(changeLine(1)) {
        cursorChar = 0;
      }
      return;
    }
    if(textArea.currentLine().charAt(c) == ' ') {
      c++;
    }
    while(c < currentLineLength) {
      if(textArea.currentLine().charAt(c) == ' ') {
        break;
      }
      c++;
    }
    cursorChar = c;
  }

  void resetCursorPosition() {
     cursorChar = 0;
     cursorLine = 0;
  }

  public void retreatCursorByChar() {
    
    if(cursorChar > 0) {
      cursorChar--;
    } 
    else if(cursorChar == 0) {
      if(changeLine(-1)) {
        cursorChar = textArea.currentLine().length();
      }
    }
  }

  public void retreatCursorByWord() {
    
    int c = cursorChar - 1;
    if(cursorChar == 0) {
      if(changeLine(-1)) {
        cursorChar = textArea.currentLine().length();
      }
      return;
    }
    if(textArea.currentLine().charAt(c - 1) == ' ') {
      c--;
    }
    while(c > 0) {
      if(textArea.currentLine().charAt(c - 1)  == ' ') {
        break;
      }
      c--;
    }
    cursorChar = c;
  }


  public boolean changeLine(int byLines) {
    
    if(byLines > 0 && cursorLine + byLines > textArea.nonWrappingLinesArrayList.size() - 1) {
      return false;
    } 
    else if(byLines < 0 && cursorLine + byLines < 0) {
      return false;
    }
    cursorLine += byLines;
    
    int currentLineLength = textArea.currentLine().length();
    
    if(cursorChar > currentLineLength) {
      cursorChar = currentLineLength;
    }
    return true;
  }

  public void advanceCursorByChar() {
    
    int currentLineLength = textArea.currentLine().length();

    if(cursorChar < currentLineLength) {
      cursorChar++;
    } 
    else if(cursorChar == currentLineLength) {
      if(changeLine(1)) {
        cursorChar = 0;
      }
    }
  }


  public void updateCursorPosition() {
    String stringBeforeCaret = (new String((StringBuffer)textArea.nonWrappingLinesArrayList.get(cursorLine))).substring(0,cursorChar);
    //cursorX = (float)textArea.p.textWidth(stringBeforeCaret) * textArea.scalingFactor;
    cursorX = (float)textArea.p.textWidth(stringBeforeCaret);

    // this is faster with monospaced fonts:
    // cursorX = (float)p.textWidth("a") * (float)theCursor.cursorChar * scalingFactor;
  }

}
