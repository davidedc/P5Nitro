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

// 10th July 2011 ---------------------------------------
// some code had to be commented-out in the template files because nme has changed
// just look for COMMENTEDOUTBECAUSEOFwriteUTFBytesToBuffergetPixelAtERROR
// and for COMMENTEDOUTBECAUSEOFgetPixelAtERROR


import processing.core.*;
import javax.swing.JFileChooser;

import java.applet.*;
import java.awt.*;
import java.awt.image.*;
import java.awt.event.*;
import java.util.*;

// this one is to make the window transparent, so you don't see anything
// it would be better to not open the window at all,
// but I couldn't manage.
import com.sun.awt.AWTUtilities;


public class P5Nitro extends PApplet {
  String theCompleteProgram = "";
  static boolean openGL = true;
  static boolean flash = false;

  // these are from the old TextAreaApp
  static color outerBackgroundColor;
  static TextArea c;
  static int canvasSizeX;
  static int canvasSizeY;
  static boolean control = false;
  static boolean P5NitroMode = true;
  static int myColorBackground;

  /*
public static void main(String args[]) {
   PApplet.main(new String[] {  "P5Nitro" });
   }
   */

  // this is to make the window transparent so there is no
  // disruption
  /*
  public void init() {
   frame.removeNotify();
   frame.setUndecorated(true);
   super.init();
   }
   */

  public void setup() {

    // this paragraph of code makes the
    // window completely transparent and 1 pixel wide
    // so there is no disruption
    /*
    size(1,1);
     frame.setAlwaysOnTop(true);
     frame.setLocation(0,0);
     AWTUtilities.setWindowOpaque(frame, false);
     AWTUtilities.setWindowOpacity(frame, 0.0f);
     */

    outerBackgroundColor = color(255);
    // the last boolean is the P5Nitro mode

    if (P5NitroMode) {
      size(500, 535);
      c = new TextArea(this, 10, 133, 470, 340, color(240, 240, 240), color(20, 20, 20), 15, false, true);
    }
    else {
      size(1000, 400);
      c = new TextArea(this, 0, 30, 300, 300, color(240, 240, 240), color(20, 20, 20), 15, false, false);
    }
  }

  void draw() {
    background(outerBackgroundColor);
    c.draw(this);
  }

  public void doTheTranslation() {

    Vector allTheDirectories = null;
    try {
      allTheDirectories = new FileTraversal().nonRecursivelyListDirectoriesInside( new File(dataPath("")+"../../Sketches/"));
    }
    catch (Exception e) {
    }

    println(System.getProperty("user.dir"));
    println(dataPath(""));
    println(sketchPath(""));


    for (int i = 0; i < allTheDirectories.size(); i++) {
      String[] allDirectoriesInPath = allTheDirectories.get(i).toString().split("\\/");
      String sketchName = allDirectoriesInPath[allDirectoriesInPath.length-1];

      //if (!sketchName.equals("BubblesGAMEv26") && !sketchName.equals("Chain") && !sketchName.equals("CountDownAprilFoolsV1")) continue;

      if (!sketchName.equals("SketchFromP5NitroEditor")) continue;
      //if (!sketchName.equals("Network")) continue;
      //if (!sketchName.equals("KarmaTwitterV1")) continue;
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

      Translator.transformedProgram = "miao";
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
        Translator.findFrameSizeAndFrameRate();

        // remove all the stuff about this sketch in the compiled directory
        try {
          Process pm0 = Runtime.getRuntime().exec("rm -rdf "+sketchName+"/", null, new File(dataPath("")+"../../CompiledSketches/"));  
        }
        catch (IOException e) {  
          e.printStackTrace();
        }

        String outputFileName;

        String MainHeaderTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/MainHeader.template"), this);
        if (flash)
          MainHeaderTemplate = MainHeaderTemplate.replaceAll("/\\*ifFlash", "").replaceAll("endifFlash\\*/", "");
        else if (openGL)
          MainHeaderTemplate = MainHeaderTemplate.replaceAll("/\\*ifOpenGL", "").replaceAll("endifOpenGL\\*/", "");
        Translator.transformedProgram = Translator.transformedProgram.replaceAll("class\\s*Main\\s*extends\\s*Bitmap\\s*\\{", MainHeaderTemplate);
        outputFileName = allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/translatedToHaxe/Main.hx"; 
        FileLoaderAndSaver.saveFile( new File(outputFileName), Translator.transformedProgram, this);

        // PGraphics spawns two versions of himself: the openGL accelerated version used for the main
        // application and the bitmap version used for the attached children
        // note that is the flash flag is set then they are both software-rendered bitmaps

          String PGraphicsTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PGraphics.template"), this);
        outputFileName = allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/translatedToHaxe/PGraphicsRoot.hx"; 
        if (flash)
          PGraphicsTemplate = PGraphicsTemplate.replaceAll("/\\*ifFlash", "").replaceAll("endifFlash\\*/", "");
        else if (openGL)
          PGraphicsTemplate = PGraphicsTemplate.replaceAll("/\\*ifOpenGL", "").replaceAll("endifOpenGL\\*/", "");
        PGraphicsTemplate = PGraphicsTemplate.replaceAll("class\\s*PGraphics\\s*extends", "class PGraphicsRoot extends");
        FileLoaderAndSaver.saveFile( new File(outputFileName), PGraphicsTemplate, this);

        PGraphicsTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PGraphics.template"), this);
        outputFileName = allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/translatedToHaxe/PGraphics.hx"; 
        PGraphicsTemplate = PGraphicsTemplate.replaceAll("/\\*ifFlash", "").replaceAll("endifFlash\\*/", "");
        FileLoaderAndSaver.saveFile( new File(outputFileName), PGraphicsTemplate, this);

        String PImageTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/PImage.template"), this);
        outputFileName = allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/translatedToHaxe/PImage.hx";
        FileLoaderAndSaver.saveFile( new File(outputFileName), PImageTemplate, this);

        String NMLProjectFileTemplate = FileLoaderAndSaver.loadFile(new File(dataPath("")+"templates/NmmlProjectFile.template"), this);
        outputFileName = allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/translatedToHaxe/P5NitroSketch.nmml"; 
        NMLProjectFileTemplate = NMLProjectFileTemplate.replaceAll("SKETCHWIDTH", Translator.frameSizeXFromSource+"").replaceAll("SKETCHHEIGHT", Translator.frameSizeYFromSource+"").replaceAll("FRAMERATE", Translator.frameRateFromSource+"");

        FileLoaderAndSaver.saveFile( new File(outputFileName), NMLProjectFileTemplate, this);
      }

      // delete the old XCode folder and copy over the latest
      // version from the template directory
      String XCodeDirectoryName = allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/";
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

        println("creating plist file");
      File pListFile = new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/HaxeProjectTemplate-Info.plist");
      File pListFileRenamed = new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/XCodeProject" + sketchName+"-Info.plist");
      pListFile.renameTo(pListFileRenamed);

      println("creating xcodeproj file");
      File xCodeProjFile = new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/HaxeProjectTemplate.xcodeproj");
      File xCodeProjFileRenamed = new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/XCodeProject" + sketchName+".xcodeproj");
      xCodeProjFile.renameTo(xCodeProjFileRenamed);
      println("6");

      // now replace all the occurrences of the old project name inside the pbxproj file
      // with the new project name
      File newXCodeProjFile = new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/XCodeProject" + sketchName+".xcodeproj/project.pbxproj");

      String xCodeProjFileContents = FileLoaderAndSaver.loadFile(newXCodeProjFile, this);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("HaxeProjectTemplate", "XCodeProject" + sketchName);
      FileLoaderAndSaver.saveFile( newXCodeProjFile, xCodeProjFileContents, this);
      println("5");

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
      println("51 " + filesToInclude);

      int numberOfFiles = 0;
      if (filesToInclude != null) {
        numberOfFiles = filesToInclude.size();
      }

      Vector selectedFilesToIncludePath = new Vector();
      Vector selectedFilesToIncludeNameWithExtension = new Vector();
      Vector selectedFilesToIncludeExtension = new Vector();
      for (int k = 0; k < numberOfFiles; k++) {
        println("52");
        String fileName = ((String)filesToInclude.get(k));
        String fname="";
        String ext="";
        int mid0= fileName.lastIndexOf("/") + 1;
        int mid= fileName.lastIndexOf(".");
        fname=fileName.substring(mid0, mid);
        ext=fileName.substring(mid+1, fileName.length());
        println("file to include: >" + fname + "< , extension: >" + ext + "<");
        if ( (!fname.equals("")) && (!ext.equals("vlw"))) {
          selectedFilesToIncludePath.add(fileName);
          selectedFilesToIncludeNameWithExtension.add(fname + "." + ext);
          selectedFilesToIncludeExtension.add(ext);
        }
      }
      println("4");

      // copy all the selected files into the xcode folder
      for (int k = 0; k < selectedFilesToIncludePath.size(); k++) {
        try {
          FileLoaderAndSaver.copy(selectedFilesToIncludePath.get(k) + "", allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/" + selectedFilesToIncludeNameWithExtension.get(k) );
        }
        catch (Exception e) {
          println("exception: "+e);
        }
      }
      println("3");

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

      println("2");

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
      println("1");

      // ok now put the strings in place
      xCodeProjFileContents = FileLoaderAndSaver.loadFile(newXCodeProjFile, this);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sEnd\\sPBXBuildFile\\ssection\\s\\*/", Change1 + "/* End PBXBuildFile section */");
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sEnd\\sPBXFileReference\\ssection\\s\\*/", Change2 + "/* End PBXFileReference section */");
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sCustomTemplate\\s\\*/\\s\\=\\s\\{[\\n\\s\\t]*isa\\s\\=\\sPBXGroup\\;[\\n\\s\\t]*children\\s\\=\\s\\(", "/* CustomTemplate */ = {\n\t\t\tisa = PBXGroup;\n\t\t\tchildren = (" + Change3);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("\\)\\;[\\n\\s\\t]*runOnlyForDeploymentPostprocessing\\s\\=\\s0\\;[\\n\\s\\t]*\\}\\;[\\n\\s\\t]*/\\*\\sEnd\\sPBXResourcesBuildPhase\\ssection\\s\\*/", Change4 + ");\n\t\t\trunOnlyForDeploymentPostprocessing = 0;\n\t\t\t};\n/* End PBXResourcesBuildPhase section */");
      FileLoaderAndSaver.saveFile( newXCodeProjFile, xCodeProjFileContents, this);


      // now copy all the generated hx files into the haxe/src directory
      // of the xcode folder

      println("putting the translated haxe files into the xcode src directory");
      try {
        DirectoryCopier.copyDirectory(new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/translatedToHaxe"), new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/haxe/src/") );
      }
      catch (Exception e) {
        println("exception: "+e);
      }

      // now copy all additional haxe files
      // into the xcode folder              
      // these are generic files like 
      println("copy all the additional haxe files in the xcode folder");
      try {
        DirectoryCopier.copyDirectory( new File(dataPath("")+"templates/additionalHaxeFilesToBeCopiedToProject/"), new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/haxe/src/") );
      }
      catch (Exception e) {
        println("exception 1: "+e);
      }

      // now copy all additional haxe files that are sketch-specific
      // into the xcode folder              
      try {
        DirectoryCopier.copyDirectory(new File(allTheDirectories.get(i)+"/data/additionalHaxeFilesToBeCopiedToProject"), new File(allTheDirectories.get(i)+"/../../CompiledSketches/"+sketchName+"/XCodeProject" + sketchName+"/haxe/src/") );
      }
      catch (Exception e) {
        println("exception 2: "+e);
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
  }

  void keyPressed() {
    if (key == PConstants.CODED) {
      if (keyCode == PConstants.CONTROL) {
        control = true;
        return;
      }
    } 
    c.keyPressed(key, keyCode, control);
  }

  void keyReleased() {
    if (keyCode == CONTROL) {
      control = false;
    }
  }

  void mousePressed() {
    if (P5NitroMode) {    

      if (mouseX > 20 && mouseX < 62 && mouseY > 15 && mouseY < 56) {
        println("pressed play");

        //System.out.println(dataPath(""));
        //System.out.println(runCommand("pwd"));
        //System.out.println(runCommand("rm -R ../../P5Nitro/data/inputFilesForTranslatorFolder/SketchFromP5NitroEditor"));
        //System.out.println(runCommand("mkdir ../../P5Nitro/data/inputFilesForTranslatorFolder/SketchFromP5NitroEditor"));
        File savingAs = new File(dataPath("")+"../../Sketches/"+"SketchFromP5NitroEditor/sketch.pde");
        FileLoaderAndSaver.saveFile(savingAs, c.allText, this);

        //System.out.println(runCommand("./P5Nitro"));
        doTheTranslation();

        //System.out.println(runCommand("haxelib run nme"));

        try {

          println("creating bin directory");
          Process pm0 = Runtime.getRuntime().exec("mkdir bin", null, new File(dataPath("")+"../../CompiledSketches/"+"SketchFromP5NitroEditor/XCodeProjectSketchFromP5NitroEditor/haxe/src/"));  
          println("copying the cached bin directory");
          Process pm1 = Runtime.getRuntime().exec("cp -RLp " + dataPath("") + "/cachedBin/ ./bin/", null, new File(dataPath("")+"../../CompiledSketches/"+"SketchFromP5NitroEditor/XCodeProjectSketchFromP5NitroEditor/haxe/src/"));  
          //Process pm15 = Runtime.getRuntime().exec("mv cachedBin bin", null, new File(dataPath("")+"data/inputFilesForTranslatorFolder/SketchFromP5NitroEditor/data/XCodeProjectSketchFromP5NitroEditor/haxe/src/"));  

          println("chmodding the build binaries script");
          Process p0 = Runtime.getRuntime().exec("chmod 777 buildTheBinaries.sh", null, new File(dataPath("")+"../../CompiledSketches/"+"SketchFromP5NitroEditor/XCodeProjectSketchFromP5NitroEditor/haxe/src/"));  
          println("launching the binary generator  " + new File(dataPath("")+"../../CompiledSketches/"+"SketchFromP5NitroEditor/XCodeProjectSketchFromP5NitroEditor/haxe/src/"));  
          //String[] cmd = {"haxelib","run","nme build P5NitroSketch.nmml cpp"};
          //String[] cmd = {"sh", "-c", "haxelib run nme build P5NitroSketch.nmml cpp"};
          String[] cmd = {
            "sh", "buildTheBinaries.sh"
          };
          String[] env = {
            "DYLD_LIBRARY_PATH=:/usr/lib/haxe/lib/hxcpp/2,07,0/bin/Mac:/usr/lib/haxe/lib/nme/2,0,1/ndll/Mac:.", "NEKO_INSTALL_PATH=/usr/lib/neko", "PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/git/bin:/usr/X11/bin"
          };
          Process p = Runtime.getRuntime().exec("./buildTheBinaries.sh", env, new File(dataPath("")+"../../CompiledSketches/"+"SketchFromP5NitroEditor/XCodeProjectSketchFromP5NitroEditor/haxe/src/"));  
          BufferedReader in = new BufferedReader(  
          new InputStreamReader(p.getInputStream()));  
          String line = null;  
          while ( (line = in.readLine ()) != null) {  
            System.out.println(line);  
            //theReturnedString = theReturnedString + "\n" + line;
          } 

          print("opening the app");
          Process p1 = Runtime.getRuntime().exec("open P5NitroSketch.app", null, new File(dataPath("")+"../../CompiledSketches/"+"SketchFromP5NitroEditor/XCodeProjectSketchFromP5NitroEditor/haxe/src/bin/cpp/Mac"));
        }
        catch (IOException e) {  
          e.printStackTrace();
        }


        return;
      }

      else if (mouseX > 86 && mouseX < 133 && mouseY > 15 && mouseY < 56) {
        println("pressed stop");
        runCommand("./killProcessByName.sh P5NitroSketch");
      }
    }
    c.mousePressed(mouseX, mouseY);
  }

  public String runCommand(String theCommand) {

    String theReturnedString = "";  

    try {  
      Process p = Runtime.getRuntime().exec(theCommand, null, new File(dataPath("")));  

      BufferedReader in = new BufferedReader(  
      new InputStreamReader(p.getInputStream()));  
      String line = null;  
      while ( (line = in.readLine ()) != null) {  
        //System.out.println(line);  
        theReturnedString = theReturnedString + "\n" + line;
      }
    } 
    catch (IOException e) {  
      e.printStackTrace();
    }
    return theReturnedString;
    //return "ok";
  }
}

