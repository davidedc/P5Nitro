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

import processing.core.*;
import javax.swing.JFileChooser;

import java.applet.*;
import java.awt.*;
import java.awt.image.*;
import java.awt.event.*;
import java.util.*;

public class P5Nitro extends PApplet {
  String theCompleteProgram = "";
  static boolean openGL = true;
  static boolean flash = false;


  public void setup() {

    Vector allTheDirectories = null;
    try {
      allTheDirectories = new FileTraversal().nonRecursivelyListDirectoriesInside( new File(dataPath("")+"inputFilesForTranslatorFolder/"));
    }
    catch (Exception e) {
    }

    for (int i = 0; i < allTheDirectories.size(); i++) {
      String[] allDirectoriesInPath = allTheDirectories.get(i).toString().split("\\/");
      String sketchName = allDirectoriesInPath[allDirectoriesInPath.length-1];

      //if (!sketchName.equals("BubblesGAMEv26") && !sketchName.equals("Chain") && !sketchName.equals("CountDownAprilFoolsV1")) continue;


      //if (!sketchName.equals("Network")) continue;
      if (!sketchName.equals("KarmaTwitterV1")) continue;
      //if (!sketchName.equals("SimpleNetwork")) continue;
      //if (!sketchName.equals("TwoTriangles")) continue;
      //if (!sketchName.equals("shapeDebugging")) continue;
      //if (!sketchName.equals("MoonCyclesCDv2")) continue;
      //if (!sketchName.equals("Astro_MeteorsV8")) continue;
      //if (!sketchName.equals("Astro_MeteorsV7")) continue;
      //if (!sketchName.equals("ALineInProcessing")) continue;
      //if (!sketchName.equals("BubblesGAMEv27")) continue;
      //if (!sketchName.equals("BubblesGAMEv26")) continue;
      //if (!sketchName.equals("ReadWriteFile")) continue;
      //if (!sketchName.equals("Chain")) continue;
      //if (!sketchName.equals("CountDownAprilFoolsV1")) continue;
      //if (!sketchName.equals("Text2")) continue;
      //if (!sketchName.equals("BridgingToTouchInterface")) continue;
      //if (!sketchName.equals("Sound")) continue;
      //if (!sketchName.equals("PIDayV3")) continue;
      //if (!sketchName.equals("Particles")) continue;
      //if (!sketchName.equals("BubblesGAMEv25")) continue;
      //if (!sketchName.equals("Simplest")) continue;
      //if (!sketchName.equals("IntralevelCountDown")) continue;
      //if (!sketchName.equals("Text1")) continue;
      //if (!sketchName.equals("BubbleGameMenu")) continue;
      println("Treating directory: " + sketchName );

      Translator.transformedProgram = SketchMerger.mergeSketchInDirectory(new File (allTheDirectories.get(i)+""), this);
      if (Translator.transformedProgram != null) {
        Translator.sketchName = sketchName;

        Translator.transformJavaAwtRectangleIntoRectangle();

        Translator.checkIfMinimSoundLibraryIsReferenced();
        Translator.eliminateMinimPackageInclusionIfThereIsOne();
        Translator.simplifyMinimConstructor();
        Translator.simplifyMinimPanGainVolumeCalls();
        Translator.removeSuperDotStop();

        Translator.checkIfProcessingNetLibraryIsReferenced();          
        Translator.simplifyClientConstructor();
        Translator.eliminateProcessingNetPackageInclusionIfThereIsOne();

        Translator.replaceSlasQuotesAndSlashCharsWithToken();
        Translator.findNamesOfUserDefinedClasses();
        Translator.fixSpacesAroundSquareBrackets();
        Translator.fixContructors();
        Translator.trnsfrmForLoopWithExplicitIncrement();
        Translator.trnsfrmForLoopWithPlusPlusIncrement();
        Translator.trnsfrmMultipleDeclarationsInOneLine();
        Translator.trnsfrmArrayDeclBringBracketsOnTypeSide();
        Translator.trnsfrmArrayDeclNoInitBrcktsOnTypeSide();

        Translator.trnsfrmArrayDecWithCreationOfObj();
        Translator.trnsfrmTopLevelArrayDecWithCreationOfObj();
        Translator.checkIfThereAreArrayInitialisations();
        Translator.checkUnsupportedTypes();
        Translator.removeVarInsideMethodDeclarations();
        Translator.adjustMethodDeclaration();
        Translator.trnsfrmBasicTypeDeclarationsWithSimpleInits();
        Translator.makeAllInstanceVariablePublic();
        Translator.checkThereAreNoInitialisationsInInstanceVariables();      
        Translator.addParametersCountToFunctionNames();

        Translator.transformRemainingArrayInitsWithoutVariableDeclaration();

        Translator.wrapTopLevelDeclarationsInStaticClass();
        //Translator.terminateClassesWithSpecialCharacters();
        Translator.addIntFunction();
        Translator.addFrameCountVariable();
        //Translator.addMouseVariables();  

        String PAppletMethodsTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PAppletMethods.template"), this);
        Translator.transformedProgram = Translator.transformedProgram.replaceAll(
        "public static function setupArgCount0\\(",
        PAppletMethodsTemplate + "\npublic function setupArgCount0 ("
          );
        Translator.adjustReferencesToMainClassVariablesAndFunctions();
        //if(sketchName.equals("QuickTrialSketch")) { noLoop(); return; }
        Translator.cleanupArgCountForConstructors();
        //Translator.addMainAndNewMethodsToMainClass();
        Translator.addHeaderToSketchClass();
        //Translator.addPackageImports();
        //Translator.substituteIntAndPrintlnReferenceToProperFunctions();
        Translator.removeEmptyPrintlnAndIntDefinition();
        Translator.removeFrameCountVariable();
        //Translator.removeMouseVariables();
        //Translator.fixReferencesToDrawFunctionSoThatEventIsPassed(); // found a better way
        Translator.putAllTopLevelInitialisationsInConstructor();
        //Translator.addPushAndPopMatricAtTopAndBottomOfDrawMethod(); // found a better way
        Translator.cleanupClassSeparators();
        Translator.enableTheMouseEventCallsThatNeedBe(); 
        // these deal with converting ArrayLists to Haxe arrays
        Translator.collectArrayListVariables();

        Translator.replaceArrayListMethods();
        Translator.fixCastings();
        Translator.putTypeInArrayDeclarationsIfThereIsAHint();
        Translator.replaceArrayListTypeWithArrayInDeclarations();
        Translator.replaceArrayListConstructorsWithArrayConstructors();
        Translator.addEmptyStringToPrintsSoIntegersCanBePrinted();
        Translator.fixArrayInitialisationInCaseOfloadString();

        Translator.removingTouchInterfaceSimulator();
        Translator.removingArgCountFromCharAtFunction();
        Translator.removingArgCountFromReturnFunction();
        Translator.removingArgCountFromLengthFunction();
        Translator.translatingParseFloatReferences();
        Translator.translatingParseIntReferences();
        Translator.removingArgCountFromIndexOfFunction();
        Translator.removingArgCountFromSubstringFunction();
        Translator.translatingDotEquals();
        Translator.makeSetupFunctionStatic();
        Translator.replaceArrayArgCount0LeftByTopLevelArrayDeclWithInit();
        Translator.SystemOutPrintlnArgCount1WithTrace();
        Translator.replaceSlasQuotesAndSlashCharsFromToken();

        String outputFileName;


        String MainHeaderTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/MainHeader.template"), this);
        if (flash)
          MainHeaderTemplate = MainHeaderTemplate.replaceAll("/\\*ifFlash","").replaceAll("endifFlash\\*/","");
        else if (openGL)
          MainHeaderTemplate = MainHeaderTemplate.replaceAll("/\\*ifOpenGL","").replaceAll("endifOpenGL\\*/","");
        Translator.transformedProgram = Translator.transformedProgram.replaceAll("class\\s*Main\\s*extends\\s*Bitmap\\s*\\{",MainHeaderTemplate);
        outputFileName = allTheDirectories.get(i)+"/data/translatedToHaxe/Main.hx"; 
        FileLoaderAndSaver.saveFile( new File(outputFileName), Translator.transformedProgram, this);

        // PGraphics spawns two versions of himself: the openGL accelerated version used for the main
        // application and the bitmap version used for the attached children
        // note that is the flash flag is set then they are both software-rendered bitmaps

          String PGraphicsTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PGraphics.template"), this);
        outputFileName = allTheDirectories.get(i)+"/data/translatedToHaxe/PGraphicsRoot.hx"; 
        if (flash)
          PGraphicsTemplate = PGraphicsTemplate.replaceAll("/\\*ifFlash","").replaceAll("endifFlash\\*/","");
        else if (openGL)
          PGraphicsTemplate = PGraphicsTemplate.replaceAll("/\\*ifOpenGL","").replaceAll("endifOpenGL\\*/","");
        PGraphicsTemplate = PGraphicsTemplate.replaceAll("class\\s*PGraphics\\s*extends","class PGraphicsRoot extends");
        FileLoaderAndSaver.saveFile( new File(outputFileName), PGraphicsTemplate, this);

        PGraphicsTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PGraphics.template"), this);
        outputFileName = allTheDirectories.get(i)+"/data/translatedToHaxe/PGraphics.hx"; 
        PGraphicsTemplate = PGraphicsTemplate.replaceAll("/\\*ifFlash","").replaceAll("endifFlash\\*/","");
        FileLoaderAndSaver.saveFile( new File(outputFileName), PGraphicsTemplate, this);

        String PImageTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PImage.template"), this);
        outputFileName = allTheDirectories.get(i)+"/data/translatedToHaxe/PImage.hx";
        FileLoaderAndSaver.saveFile( new File(outputFileName), PImageTemplate, this);
      }

      // delete the old XCode folder and copy over the latest
      // version from the template directory
      String XCodeDirectoryName = allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/";
      File XCodeDirectory = new File(XCodeDirectoryName);
      if (XCodeDirectory.exists()) {
        println("XCode directory exists - deleting it");
        DirectoryDeleter.deleteDir(XCodeDirectory);
      }
      XCodeDirectory.mkdir();
      println("copying XCode directory template");
      try {
        DirectoryCopier.copyDirectory(new File(dataPath("")+"templates/HaxeProjectTemplate/"), XCodeDirectory );
      }
      catch (Exception e) {
        println("exception: "+e);
      }

      // now rename both the plist file and the xcodeproj file to match
      // the new project name

        File pListFile = new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/HaxeProjectTemplate-Info.plist");
      File pListFileRenamed = new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/XCodeProject" + sketchName+"-Info.plist");
      pListFile.renameTo(pListFileRenamed);

      File xCodeProjFile = new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/HaxeProjectTemplate.xcodeproj");
      File xCodeProjFileRenamed = new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/XCodeProject" + sketchName+".xcodeproj");
      xCodeProjFile.renameTo(xCodeProjFileRenamed);

      // now replace all the occurrences of the old project name inside the pbxproj file
      // with the new project name
      File newXCodeProjFile = new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/XCodeProject" + sketchName+".xcodeproj/project.pbxproj");

      String xCodeProjFileContents = FileLoaderAndSaver.loadFile(newXCodeProjFile, this);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("HaxeProjectTemplate", "XCodeProject" + sketchName);
      FileLoaderAndSaver.saveFile( newXCodeProjFile, xCodeProjFileContents, this);

      // ok now let's find the sketch files (the ones in  the data directory)
      // we'll later also update the project.pbxproj file accordingly
      // note that we'll skip the .vlw files (which are for the fonts)
      Vector filesToInclude = null;
      try {
        filesToInclude = (new FileTraversal()).nonRecursivelyListFilesInside( new File(allTheDirectories.get(i) + "/data/") );
      }
      catch (Exception e) {
        println("exception: "+e);
      }
      Vector selectedFilesToIncludePath = new Vector();
      Vector selectedFilesToIncludeNameWithExtension = new Vector();
      Vector selectedFilesToIncludeExtension = new Vector();
      for (int k = 0; k < filesToInclude.size(); k++) {
        String fileName = ((String)filesToInclude.get(k));
        String fname="";
        String ext="";
        int mid0= fileName.lastIndexOf("/") + 1;
        int mid= fileName.lastIndexOf(".");
        fname=fileName.substring(mid0,mid);
        ext=fileName.substring(mid+1,fileName.length());
        println("file to include: >" + fname + "< , extension: >" + ext + "<");
        if ( (!fname.equals("")) && (!ext.equals("vlw"))) {
          selectedFilesToIncludePath.add(fileName);
          selectedFilesToIncludeNameWithExtension.add(fname + "." + ext);
          selectedFilesToIncludeExtension.add(ext);
        }
      }

      // copy all the selected files into the xcode folder
      for (int k = 0; k < selectedFilesToIncludePath.size(); k++) {
        try {
          FileLoaderAndSaver.copy(selectedFilesToIncludePath.get(k) + "", allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/" + selectedFilesToIncludeNameWithExtension.get(k) );
        }
        catch (Exception e) {
          println("exception: "+e);
        }
      }

      Vector selectedFilesToIncludeHex1 = new Vector();
      Vector selectedFilesToIncludeHex2 = new Vector();
      for (int k = 0; k < selectedFilesToIncludePath.size(); k++) {
        selectedFilesToIncludeHex1.add("1"+k);
        selectedFilesToIncludeHex2.add("2"+k);
      }

      String Change1 = "" ;
      String Change2 = "" ;
      String Change3 = "" ;
      String Change4 = "" ;
      String fileEncoding = "" ;

      for (int k = 0; k < selectedFilesToIncludePath.size(); k++) {

        if (selectedFilesToIncludeExtension.get(k).equals("ehsvg")) {
          fileEncoding = "fileEncoding = 4; ";
        }
        else if (selectedFilesToIncludeExtension.get(k).equals("txt")) {
          fileEncoding = "fileEncoding = 4; ";
        }

        Change1 = Change1 +
          "		" + selectedFilesToIncludeHex1.get(k) + " /* " +
          selectedFilesToIncludeNameWithExtension.get(k) +
          " in Resources */ = {isa = PBXBuildFile; "+
          "fileRef = " +
          selectedFilesToIncludeHex2.get(k) +
          " /* " +
          selectedFilesToIncludeNameWithExtension.get(k) +
          " */; };\n";

        Change2 = Change2 + "		" +
          selectedFilesToIncludeHex2.get(k) +
          " /* " +
          selectedFilesToIncludeNameWithExtension.get(k) +
          " */ = {isa = PBXFileReference; "+
          fileEncoding +
          "lastKnownFileType = dummy; path = "+
          selectedFilesToIncludeNameWithExtension.get(k) +
          "; sourceTree = \"<group>\"; };\n";
        Change3 = Change3 + "\n				" +
          selectedFilesToIncludeHex2.get(k) +
          " /* " +
          selectedFilesToIncludeNameWithExtension.get(k) +
          " */,";
        Change4 = Change4 + "\n				" +
          selectedFilesToIncludeHex1.get(k) +
          " /* " +
          selectedFilesToIncludeNameWithExtension.get(k) +
          " in Resources */,";
      }

      // ok now put the strings in place
      xCodeProjFileContents = FileLoaderAndSaver.loadFile(newXCodeProjFile, this);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sEnd\\sPBXBuildFile\\ssection\\s\\*/", Change1 + "/* End PBXBuildFile section */");
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sEnd\\sPBXFileReference\\ssection\\s\\*/", Change2 + "/* End PBXFileReference section */");
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sCustomTemplate\\s\\*/\\s\\=\\s\\{[\\n\\s\\t]*isa\\s\\=\\sPBXGroup\\;[\\n\\s\\t]*children\\s\\=\\s\\(", "/* CustomTemplate */ = {\n\t\t\tisa = PBXGroup;\n\t\t\tchildren = (" + Change3);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("\\)\\;[\\n\\s\\t]*runOnlyForDeploymentPostprocessing\\s\\=\\s0\\;[\\n\\s\\t]*\\}\\;[\\n\\s\\t]*/\\*\\sEnd\\sPBXResourcesBuildPhase\\ssection\\s\\*/", Change4 + ");\n\t\t\trunOnlyForDeploymentPostprocessing = 0;\n\t\t\t};\n/* End PBXResourcesBuildPhase section */");
      FileLoaderAndSaver.saveFile( newXCodeProjFile, xCodeProjFileContents, this);


      // now copy all the generated hx files into the haxe/src directory
      // of the xcode folder

      try {
        DirectoryCopier.copyDirectory(new File(allTheDirectories.get(i) + "/data/translatedToHaxe"), new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/haxe/src/") );
      }
      catch (Exception e) {
        println("exception: "+e);
      }

      // now copy all additional haxe files
      // into the xcode folder              
      // these are generic files like 
      try {
        DirectoryCopier.copyDirectory( new File(dataPath("")+"templates/additionalHaxeFilesToBeCopiedToProject/"), new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/haxe/src/") );
      }
      catch (Exception e) {
        println("exception: "+e);
      }

      // now copy all additional haxe files that are sketch-specific
      // into the xcode folder              
      try {
        DirectoryCopier.copyDirectory(new File(allTheDirectories.get(i) + "/data/additionalHaxeFilesToBeCopiedToProject"), new File(allTheDirectories.get(i) + "/data/XCodeProject" + sketchName+"/haxe/src/") );
      }
      catch (Exception e) {
        println("exception: "+e);
      }
    }
    /*
    // run diff script
     try{
     Runtime.getRuntime().exec("/Users/davidedellacasa/Desktop/inputFilesForTranslatorFolder/showMeTheDifferences.sh");
     }
     catch(java.io.IOException e){
     println(e);
     }
     */

    /*
    String mergedSketch = SketchMerger.mergeSketchInDirectory(
     new File("/Users/davidedellacasa/Desktop/inputFilesForTranslatorFolder/") ,
     this
     );
     
     println("merged file:");
     println(mergedSketch);
     */
    exit();
  }

  public void mousePressed() {
  }
}

