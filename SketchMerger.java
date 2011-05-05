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

import java.util.regex.*;
import java.util.Vector;
import java.io.*;
import processing.core.*;


class SketchMerger {
  
  public static String mergeSketchInDirectory(File theDirectory, PApplet pApplet) {
    Vector listOfFiles = null;
    try{
          listOfFiles = new FileTraversal().nonRecursivelyListFilesInside(
           theDirectory
          );
    }
    catch(java.io.IOException e){
      pApplet.println(e);
    }

    pApplet.println("////// files inside (non-recursive):");
    if (listOfFiles != null) {
      for (int i = 0; i < listOfFiles.size(); i++) {
          pApplet.println(listOfFiles.get(i) + "");
       }
    }

    String mergedProgram = "";
    boolean foundTheMainProcessingFile = false;
    pApplet.println("////// files that are valid main Processing files:");
    if (listOfFiles != null) {
       for (int i = 0; i < listOfFiles.size(); i++) {
          if ((listOfFiles.get(i) + "").indexOf(".pde") == -1) continue;
          try{
            File fileToTest = new File(listOfFiles.get(i) + "");
            Translator.transformedProgram = FileLoaderAndSaver.loadFile(fileToTest, pApplet);
            if (Translator.isMainFile()) {
              pApplet.println(listOfFiles.get(i) + " is a valid Main Processing file");
              foundTheMainProcessingFile = true;
              mergedProgram =Translator.transformedProgram +"";
              listOfFiles.set(i, null);
            }
            else {
              pApplet.println(listOfFiles.get(i) + " is not a valid Main Processing file");
              pApplet.println("stripping pre-class code");
              //println(Translator.transformedProgram);
            }
          }
          catch (Exception e) {
          }
       }
       if (!foundTheMainProcessingFile) {
        pApplet.println("there are no valid processing files");
        return null;
       }

    }
    
    String variableDeclarationsAtTopOfFile = "";
    String additionalFunctionDeclarations = "";
       // each .pde files can contain a number of class definitions or function definitions or variable
       // definitions.
       // The variables we'll put at the top of the merged sketch.
       // For simplicity, we accept four different formats of .pde files:
       //    only class definition
       //    variables definition followed by class definition
       //    only function definition
       //    variables definition followed by class definition
       // In theory you could have other combinations where you mix classes and functions and
       // variables in all sorts of ways, but we are just capturing the most common cases here.
       // stripping all the non-main pde files of their pre-class or pre-function code
       // and adding them to the end of the merged file
       // note that the stripped code are variable definitions and are put at the top
       // of the main file, i.e. they'll stay global to all classes
       for (int i = 0; i < listOfFiles.size(); i++) {
         if (listOfFiles.get(i) == null) continue;
         if ((listOfFiles.get(i) + "").indexOf(".pde") == -1) continue;
         // the HighResScreenManager class is going to be replaced by a
         // dedicated HighResScreenManager.hx file.
         if ( (listOfFiles.get(i) + "").indexOf("HighDpiScreenManager.pde") != -1 ) continue;
         File fileToTest = new File(listOfFiles.get(i) + "");
         Translator.transformedProgram = FileLoaderAndSaver.loadFile(fileToTest, pApplet);
         
         if (Translator.containsClassDefinition()) {
           // handle case where there is either a class definition alone
           // or variables definitions followed by a class definition
            variableDeclarationsAtTopOfFile = variableDeclarationsAtTopOfFile +
              "\n// start of variables declared in "+
              listOfFiles.get(i)+"\n"+
              Translator.stripPreClassCode() +
              "\n// end of variables declared in "+ listOfFiles.get(i) + "\n";
         }
         else {
           // handle case where there is either a function definition alone
           // or variables definitions followed by a function definition
            variableDeclarationsAtTopOfFile = variableDeclarationsAtTopOfFile + "\n" + Translator.stripPreFunctionCode();
            additionalFunctionDeclarations = additionalFunctionDeclarations + "\n// functions from "+
              listOfFiles.get(i)+"\n"+Translator.transformedProgram  +
              "\n// end of functions declared in "+ listOfFiles.get(i) + "\n";
            Translator.transformedProgram = "";
         }
         
         mergedProgram = mergedProgram  + "\n /* end of class ~ */\n" +  "\n///////// merged file: "+listOfFiles.get(i) +"\n\n" +  Translator.transformedProgram ;
       }
       
       // the functions we racked up from all the .pde files
       // need to be added inside the Main class, so we find the setup function
       // and put the extra functions before it, so we know they are inside the
       // Main class
        mergedProgram = mergedProgram.replaceAll("void\\s*setup\\s*\\(\\s*\\)\\s*\\{", additionalFunctionDeclarations + "\nvoid setup() {");
        // finally we add the variable declarations that we racked up from all the
        // ,pde files and we put them at the top
        return variableDeclarationsAtTopOfFile + "\n"+ mergedProgram  + "\n /* end of class ~ */\n";
  }
}
