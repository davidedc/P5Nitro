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

import java.io.*;
import java.util.Vector;


class XCodeProjectMaker {

  public static void maxeXCodeProject(String sketchName, String templatesDirectory, String compiledSketchXCodeDirectory, String compiledSketchDirectory,P5Nitro theP5NitroSketch, String sketchPath) {
    
      // delete the old XCode folder and copy over the latest
      // version from the template directory
      File XCodeDirectory = new File(compiledSketchXCodeDirectory+"/");
      if (XCodeDirectory.exists()) {
        System.out.println("XCode directory exists - deleting it");
        DirectoryDeleter.deleteDir(XCodeDirectory);
      }
      XCodeDirectory.mkdir();
      System.out.println("copying XCode directory template");
      DirectoryCopier.copyDirectory(new File(templatesDirectory+"HaxeProjectTemplate/"), XCodeDirectory );

      // now rename both the plist file and the xcodeproj file to match
      // the new project name

      System.out.println("creating plist file");
      File pListFile = new File(compiledSketchXCodeDirectory+"/HaxeProjectTemplate-Info.plist");
      File pListFileRenamed = new File(compiledSketchXCodeDirectory+"/XCodeProject" + sketchName+"-Info.plist");
      pListFile.renameTo(pListFileRenamed);

      System.out.println("creating xcodeproj file");
      File xCodeProjFile = new File(compiledSketchXCodeDirectory+"/HaxeProjectTemplate.xcodeproj");
      File xCodeProjFileRenamed = new File(compiledSketchXCodeDirectory+"/XCodeProject" + sketchName+".xcodeproj");
      xCodeProjFile.renameTo(xCodeProjFileRenamed);

      // now replace all the occurrences of the old project name inside the pbxproj file
      // with the new project name
      File newXCodeProjFile = new File(compiledSketchXCodeDirectory+"/XCodeProject" + sketchName+".xcodeproj/project.pbxproj");

      String xCodeProjFileContents = FileLoaderAndSaver.loadFile(newXCodeProjFile, theP5NitroSketch);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("HaxeProjectTemplate", "XCodeProject" + sketchName);
      FileLoaderAndSaver.saveFile( newXCodeProjFile, xCodeProjFileContents, theP5NitroSketch);

      // ok now let's find the sketch files (the ones in  the data directory)
      // we'll later also update the project.pbxproj file accordingly
      // note that we'll skip the .vlw files (which are for the fonts)
      Vector filesToInclude = null;
      try {
        filesToInclude = (new FileTraversal()).nonRecursivelyListFilesInside( new File(sketchPath + "/data/") );
      }
      catch (Exception e) {
        System.out.println("exception: "+e);
      }

      int numberOfFiles = 0;
      if (filesToInclude != null) {
        numberOfFiles = filesToInclude.size();
      }

      Vector selectedFilesToIncludePath = new Vector();
      Vector selectedFilesToIncludeNameWithExtension = new Vector();
      Vector selectedFilesToIncludeExtension = new Vector();
      for (int k = 0; k < numberOfFiles; k++) {
        String fileName = ((String)filesToInclude.get(k));
        String fname="";
        String ext="";
        int mid0= fileName.lastIndexOf("/") + 1;
        int mid= fileName.lastIndexOf(".");
        fname=fileName.substring(mid0, mid);
        ext=fileName.substring(mid+1, fileName.length());
        System.out.println("file to include: >" + fname + "< , extension: >" + ext + "<");
        if ( (!fname.equals("")) && (!ext.equals("vlw"))) {
          selectedFilesToIncludePath.add(fileName);
          selectedFilesToIncludeNameWithExtension.add(fname + "." + ext);
          selectedFilesToIncludeExtension.add(ext);
        }
      }

      // copy all the selected files into the xcode folder
      for (int k = 0; k < selectedFilesToIncludePath.size(); k++) {
        try {
          FileLoaderAndSaver.copy(selectedFilesToIncludePath.get(k) + "", compiledSketchXCodeDirectory+"/" + selectedFilesToIncludeNameWithExtension.get(k) );
        }
        catch (Exception e) {
          System.out.println("exception: "+e);
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
      xCodeProjFileContents = FileLoaderAndSaver.loadFile(newXCodeProjFile, theP5NitroSketch);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sEnd\\sPBXBuildFile\\ssection\\s\\*/", Change1 + "/* End PBXBuildFile section */");
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sEnd\\sPBXFileReference\\ssection\\s\\*/", Change2 + "/* End PBXFileReference section */");
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("/\\*\\sCustomTemplate\\s\\*/\\s\\=\\s\\{[\\n\\s\\t]*isa\\s\\=\\sPBXGroup\\;[\\n\\s\\t]*children\\s\\=\\s\\(", "/* CustomTemplate */ = {\n\t\t\tisa = PBXGroup;\n\t\t\tchildren = (" + Change3);
      xCodeProjFileContents = xCodeProjFileContents.replaceAll("\\)\\;[\\n\\s\\t]*runOnlyForDeploymentPostprocessing\\s\\=\\s0\\;[\\n\\s\\t]*\\}\\;[\\n\\s\\t]*/\\*\\sEnd\\sPBXResourcesBuildPhase\\ssection\\s\\*/", Change4 + ");\n\t\t\trunOnlyForDeploymentPostprocessing = 0;\n\t\t\t};\n/* End PBXResourcesBuildPhase section */");
      FileLoaderAndSaver.saveFile( newXCodeProjFile, xCodeProjFileContents, theP5NitroSketch);

      // now copy all the generated hx files into the haxe/src directory
      // of the xcode folder

      System.out.println("putting the translated haxe files into the xcode src directory");
      DirectoryCopier.copyDirectory(new File(compiledSketchDirectory+"/translatedToHaxe"), new File(compiledSketchXCodeDirectory+"/haxe/src/") );

    }

  }


