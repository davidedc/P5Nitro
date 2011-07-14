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
//import processing.core.*;


class Translator {
  public static String transformedProgram;
  public static String classesPattern = "";
  static String anyNumberOfArrayBrackets = "(\\[\\s*\\w*\\s*\\])*";
  static String atLeastOneArrayBracket   = "(\\[\\s*\\w*\\s*\\])+";
  static String identifier = "\\w+";
  static String spaces = " *";
  static String replacement;
  static Pattern pattern ;
  static Matcher matcher ;
  static boolean found;
  static Vector namesOfSystemTypes = null;
  static Vector namesOfSystemClasses = null;
  static Vector namesOfClassesCreatedByUsers = null;
  static Vector variablesDeclaredInMainClass = null; // in theory we don't need this one
  static Vector functionsDeclaredInMainClass = null; // in theory we don't need this one
  static Vector functionsAndVariablesDeclaredInMainClass = null;
  static Vector arrayListVariables;
  static String sketchName;
  static String characterThatCanBeAroundAVariable = "[\\t\\n =\\+\\-\\[\\*/%\\(\\)\\;\\,!<]";
  static String characterThatCanBeAroundAVariablePlusDot = "[\\t\\n =\\+\\-\\[\\*/%\\(\\)\\;\\,!<\\.]";
  static String characterThatCanBeAroundAFunction = "[\\t\\n =\\+\\-\\[\\*/%\\(\\)\\;\\,!<\\.]";
  static boolean foundReferencesToMinimSoundLibrary;
  static boolean foundReferencesToProcessingNetLibrary;
  static int frameSizeXFromSource = 100;
  static int frameSizeYFromSource = 100;
  static int frameRateFromSource = 60;


  public static void findFrameSizeAndFrameRate() {
    String patternForFindingTheFrameSize;

    patternForFindingTheFrameSize = "sizeArgCount2\\s*\\(\\s*(\\d+)\\s*\\,\\s*(\\d+)\\s*\\)\\s*\\;";
    matcher = Pattern.compile(patternForFindingTheFrameSize).matcher(transformedProgram);

    if (matcher.find()) {
      frameSizeXFromSource = Integer.parseInt(matcher.group(1));
      frameSizeYFromSource = Integer.parseInt(matcher.group(2));
    } 
    else {

      patternForFindingTheFrameSize = "sizeArgCount1\\s*\\(\\s*(\\d+)\\s*\\)\\s*\\;";
      matcher = Pattern.compile(patternForFindingTheFrameSize).matcher(transformedProgram);

      if (matcher.find()) {
        frameSizeXFromSource = Integer.parseInt(matcher.group(1));
        frameSizeYFromSource = Integer.parseInt(matcher.group(1));
      }
    }

    println("x:" + frameSizeXFromSource);
    println("y:" + frameSizeYFromSource);

    String patternForFindingTheFrameRate;

    patternForFindingTheFrameRate = "frameRateArgCount1\\s*\\(\\s*(\\d+)\\s*\\)\\s*\\;";
    matcher = Pattern.compile(patternForFindingTheFrameRate).matcher(transformedProgram);

    if (matcher.find()) {
      frameRateFromSource = Integer.parseInt(matcher.group(1));
    } 


    return;
  }


  // this is necessary to simplify the regular expressions to check when a class
  // is followed by any number of square brackets and then an identifier
  // If we don't perform this substitution, it's difficult to make the square brackets
  // (which can have any nuber of leading or following spaces around or inside them)
  // optional and still check that an identifier is always separated from the class
  // by either a space or a square bracket.
  // After this substitution, the structure should be always:
  // class name + no spaces + optional square brackets + space + identifier
  // or
  // class name + one or more spaces + identifier
  public static void fixSpacesAroundSquareBrackets() {
    transformedProgram = transformedProgram.replaceAll("\\s*\\[", "[");
    transformedProgram = transformedProgram.replaceAll("\\]", "] ");
  }


  public static void transformJavaAwtRectangleIntoRectangle() {
    // todo this mechanism of mapping the Rectangle class works
    // in simple cases but it doesn't work if the user defines his own Rectangle
    // class or if the user imports java.awt.Rectangle...
    // We should think how to do this a bit cleaner
    transformedProgram = transformedProgram.replaceAll("java\\.awt\\.Rectangle", "Rectangle");
  }


  public static void removeSuperDotStop() {
    // first we remove the version with the semicolon and then we remove any other instances
    // this is because haxe doesn't like lines with the semicolon left alone
    transformedProgram = transformedProgram.replaceAll("super\\.stop\\s*\\(\\s*\\)\\s*\\;", "");
    transformedProgram = transformedProgram.replaceAll("super\\.stop\\s*\\(\\s*\\)", "");
  }


  public static void simplifyClientConstructor() {
    if (foundReferencesToProcessingNetLibrary) {
      transformedProgram = transformedProgram.replaceAll("\\snew\\s*Client\\s*\\(\\s*this", " new Client( null");
    }
  }

  public static void simplifyMinimConstructor() {
    if (foundReferencesToMinimSoundLibrary) {
      transformedProgram = transformedProgram.replaceAll("\\=\\s*new\\s*Minim\\s*\\(\\s*\\w+\\s*\\)", "= new Minim()");
    }
  }

  public static void simplifyMinimPanGainVolumeCalls () {
    if (foundReferencesToMinimSoundLibrary) {

      transformedProgram = transformedProgram.replaceAll("\\.volume\\s*\\(\\s*\\)\\s*\\.getValue\\s*\\(", ".getVolume(");
      transformedProgram = transformedProgram.replaceAll("\\.volume\\s*\\(\\s*\\)\\s*\\.setValue\\s*\\(", ".setVolume(");
      transformedProgram = transformedProgram.replaceAll("\\.volume\\s*\\(\\s*\\)\\s*\\.getMinimum\\s*\\(", ".getMinimumVolume(");
      transformedProgram = transformedProgram.replaceAll("\\.volume\\s*\\(\\s*\\)\\s*\\.getMaximum\\s*\\(", ".getMaximumVolume(");

      transformedProgram = transformedProgram.replaceAll("\\.gain\\s*\\(\\s*\\)\\s*\\.getValue\\s*\\(", ".getGain(");
      transformedProgram = transformedProgram.replaceAll("\\.gain\\s*\\(\\s*\\)\\s*\\.setValue\\s*\\(", ".setGain(");
      transformedProgram = transformedProgram.replaceAll("\\.gain\\s*\\(\\s*\\)\\s*\\.getMinimum\\s*\\(", ".getMinimumGain(");
      transformedProgram = transformedProgram.replaceAll("\\.gain\\s*\\(\\s*\\)\\s*\\.getMaximum\\s*\\(", ".getMaximumGain(");

      transformedProgram = transformedProgram.replaceAll("\\.pan\\s*\\(\\s*\\)\\s*\\.getValue\\s*\\(", ".getPan(");
      transformedProgram = transformedProgram.replaceAll("\\.pan\\s*\\(\\s*\\)\\s*\\.setValue\\s*\\(", ".setPan(");
      transformedProgram = transformedProgram.replaceAll("\\.pan\\s*\\(\\s*\\)\\s*\\.getMinimum\\s*\\(", ".getMinimumPan(");
      transformedProgram = transformedProgram.replaceAll("\\.pan\\s*\\(\\s*\\)\\s*\\.getMaximum\\s*\\(", ".getMaximumPan(");

      transformedProgram = transformedProgram.replaceAll("\\.hasControl\\s*\\(\\s*Controller\\.PAN", ".hasPanControl(");
      transformedProgram = transformedProgram.replaceAll("\\.hasControl\\s*\\(\\s*Controller\\.GAIN", ".hasGainControl(");
      transformedProgram = transformedProgram.replaceAll("\\.hasControl\\s*\\(\\s*Controller\\.VOLUME", ".hasVolumeControl(");
    }
  }


  public static void checkIfMinimSoundLibraryIsReferenced () {
    if (transformedProgram.indexOf("ddf.minim.") != -1) {
      foundReferencesToMinimSoundLibrary = true;
    }
  }



  public static void eliminateMinimPackageInclusionIfThereIsOne () {
    if (foundReferencesToMinimSoundLibrary) {
      transformedProgram = transformedProgram.replaceAll("import\\s*ddf\\.minim\\.\\*\\;", "// eliminated minim pckage inclusion");
    }
  }




  public static void eliminateProcessingNetPackageInclusionIfThereIsOne () {
    if (foundReferencesToProcessingNetLibrary) {
      transformedProgram = transformedProgram.replaceAll("import\\s*processing\\.net\\.\\*\\;", "// eliminated processing net pckage inclusion");
    }
  }


  public static void checkIfProcessingNetLibraryIsReferenced () {
    if (transformedProgram.indexOf("processing.net.") != -1) {
      foundReferencesToProcessingNetLibrary = true;
    }
  }
 
 

  // We don't simplify the client constructor because we really only support one way
  // of constructing the client, i.e. the constructor with three arguments.
  // We don't support the constructor with two arguments because that one requires
  // a socket, which would force us to provide an implementation for that too.
  // So if there is only one constructor supported then there are no problems
  // we can just use the normal haxe way of using new
  // public static void simplifyClientConstructor() {
  // }

  public static void SystemOutPrintlnArgCount1WithTrace () {
    transformedProgram = transformedProgram.replaceAll("System\\.out\\.printlnArgCount1\\s*\\(", 
    "trace(");
  }

  public static void replaceArrayArgCount0LeftByTopLevelArrayDeclWithInit () {
    transformedProgram = transformedProgram.replaceAll("\\>\\s*\\=\\s*new\\s*ArrayArgCount0", 
    "> = new Array");
  }

  public static void makeSetupFunctionStatic () {
    transformedProgram = transformedProgram.replaceAll("public\\s*function\\s*setupArgCount0\\s*\\(", 
    "public static function setupArgCount0(");
  }



  public static void replaceSlasQuotesAndSlashCharsFromToken() {
    String backSlash = "\\";
    println("backslash: " + backSlash );
    transformedProgram = transformedProgram.replaceAll("SLASHQUOTE", "\\\\\"");
    transformedProgram = transformedProgram.replaceAll("SLASHN", "\\\\n");
    transformedProgram = transformedProgram.replaceAll("SLASHR", "\\\\r");
  }

  public static void replaceSlasQuotesAndSlashCharsWithToken() {
    transformedProgram = transformedProgram.replaceAll("\\\\\"", "SLASHQUOTE");
    transformedProgram = transformedProgram.replaceAll("\\\\n", "SLASHN");
    transformedProgram = transformedProgram.replaceAll("\\\\r", "SLASHR");
  }

  public static void translatingDotEquals() {
    transformedProgram = transformedProgram.replaceAll("\\.equalsArgCount1", "==");
  }

  public static void translatingParseFloatReferences() {
    transformedProgram = transformedProgram.replaceAll("parseFloatArgCount1\\(", "Std.parseFloat(");
  }

  public static void translatingParseIntReferences() {
    transformedProgram = transformedProgram.replaceAll("parseIntArgCount1\\(","Std.parseInt(");
  }

  public static void removingArgCountFromIndexOfFunction() {
    transformedProgram = transformedProgram.replaceAll("\\.indexOfArgCount1\\s*\\(",".indexOf(");
    transformedProgram = transformedProgram.replaceAll("\\.indexOfArgCount2\\s*\\(",".indexOf(");
  }

  public static void removingArgCountFromSubstringFunction() {
    transformedProgram = transformedProgram.replaceAll("\\.substringArgCount1\\s*\\(",".substr(");
    transformedProgram = transformedProgram.replaceAll("\\.substringArgCount2\\s*\\(",".substr(");
  }

  public static void removingArgCountFromLengthFunction() {
    transformedProgram = transformedProgram.replaceAll("\\.lengthArgCount0\\(\\s*\\)",".length");
  }

  public static void removingArgCountFromReturnFunction() {
    transformedProgram = transformedProgram.replaceAll("returnArgCount1","return");
  }

  public static void removingArgCountFromCharAtFunction() {
    transformedProgram = transformedProgram.replaceAll("\\.charAtArgCount1",".charAt");
  }
 
 
  public static void transformRemainingArrayInitsWithoutVariableDeclaration() {
    // transforms stuff like commands = new int[100];
    // into commands = new Array();

    String findArrayInitWithoutVariableDeclaration = "(([\\n\\s\\t])(\\w+))\\s*\\=\\s*new\\s*"+classesPattern+"\\s*\\[\\w+\\]\\s*;";
    println("pattern findArrayInitWithoutVariableDeclaration : " + findArrayInitWithoutVariableDeclaration);
    matcher = Pattern.compile(findArrayInitWithoutVariableDeclaration).matcher(transformedProgram);

    while (matcher.find()) {
      String replacement = matcher.group(1) + " = new Array();";

      // make the replacement and re-build the matcher
      transformedProgram = matcher.replaceFirst(replacement);
      matcher = Pattern.compile(findArrayInitWithoutVariableDeclaration).matcher(transformedProgram);
    }
  }

  public static void removingTouchInterfaceSimulator() {
    transformedProgram = transformedProgram.replaceAll("/\\*\\s*simulating\\s*touch\\s*interface\\,\\s*don\\'t\\s*remove\\s*this\\s*line\\s*\\*/","//");
  }


  public static void fixArrayInitialisationInCaseOfloadString() {
    String findLoadStringsWithStringArrayDeclaration = "String\\s*\\[\\s*\\]\\s*(\\w+)\\s*\\=\\s*loadStringsArgCount1";
    println("pattern: " + findLoadStringsWithStringArrayDeclaration);
    matcher = Pattern.compile(findLoadStringsWithStringArrayDeclaration).matcher(transformedProgram);

    while (matcher.find()) {
      String replacement = "var " + matcher.group(1) + ":Array<String> = loadStringsArgCount1";

      // make the replacement and re-build the matcher
      transformedProgram = matcher.replaceFirst(replacement);
      matcher = Pattern.compile(findLoadStringsWithStringArrayDeclaration).matcher(transformedProgram);
    }
  }


  // sometimes in Haxe you have to force the conversion to string
  // the quickest way to do that is to add a ""+ at the beginning
  // of the println argument.
  public static void addEmptyStringToPrintsSoIntegersCanBePrinted() {
    String findPrintoutsWithoutAString = "printlnArgCount1\\s*\\(\\s*([^\\\"])";
    println("pattern: " + findPrintoutsWithoutAString);
    matcher = Pattern.compile(findPrintoutsWithoutAString).matcher(transformedProgram);

    while (matcher.find()) {
      if (matcher.group(1) == null) continue;
      String replacement = "printlnArgCount1(\"\"+" + matcher.group(1);

      // make the replacement and re-build the matcher
      transformedProgram = matcher.replaceFirst(replacement);
      matcher = Pattern.compile(findPrintoutsWithoutAString).matcher(transformedProgram);
    }

    // the operation above also adds an empty string in the declaration of the
    // printlnArgCount1 function so we need to fix that one
    transformedProgram = transformedProgram.replaceAll("printlnArgCount1\\(\\\"\\\"\\+theString\\:String\\)","printlnArgCount1(theString:String)");
  }

  public static void replaceArrayListConstructorsWithArrayConstructors() {
    transformedProgram = transformedProgram.replaceAll("new\\s*ArrayListArgCount0\\(\\s*\\)","new Array()");
  }

  public static void replaceArrayListTypeWithArrayInDeclarations() {
    String patternForArrayListDeclarationsWithHint = "var\\s*(\\w+)\\s*\\:\\s*ArrayList\\;";
    matcher = Pattern.compile(patternForArrayListDeclarationsWithHint).matcher(transformedProgram);

    while (matcher.find()) {
      String replacement = "var " + matcher.group(1) + " : Array<Dynamic>;";

      // make the replacement and re-build the matcher
      transformedProgram = matcher.replaceFirst(replacement);
      matcher = Pattern.compile(patternForArrayListDeclarationsWithHint).matcher(transformedProgram);
    }
  }


  public static void putTypeInArrayDeclarationsIfThereIsAHint() {
    String patternForArrayListDeclarationsWithHint = "var\\s*(\\w+)\\s*\\:\\s*ArrayList\\;\\s*\\/\\/\\s*if\\s*you\\s*know\\s*the\\s*type\\s*of\\s*this\\s*array\\s*put\\s*it\\s*here\\s*\\>\\s*"+classesPattern+"\\s*\\<";
    println("pattern: " + patternForArrayListDeclarationsWithHint);
    matcher = Pattern.compile(patternForArrayListDeclarationsWithHint).matcher(transformedProgram);

    while (matcher.find()) {
      println("found: "+ matcher.group() );
      println("hint is for type: "+ matcher.group(1) );
      String replacement = "\nvar " + matcher.group(1) + " : Array<"+mapTheProcessingTypeToHaxe(matcher.group(2))+">;\n";

      // make the replacement and re-build the matcher
      transformedProgram = matcher.replaceFirst(replacement);
      matcher = Pattern.compile(patternForArrayListDeclarationsWithHint).matcher(transformedProgram);
    }
  }

  // TODO this is kind of a bad way of dealing with casting
  // because Haxe does have a cast(object, type) operator
  // so we really could do better here
  // but transforming things such as
  //       (HLine)anArray[4];
  //       (HLine)someFunction(someargument);
  //       (HLine)someVariable + ...;
  // requires checking if the casting is followed by an ID with which
  // kind of parenthesys and find the position for the end bracket accordingly.
  // It can be done, but getting rid of the castings altogether works fine
  // for the time being 
  public static void fixCastings() {
    transformedProgram = transformedProgram.replaceAll(
    "\\(\\s*" + classesPattern + "\\s*\\)",
    ""
      );
  }


  public static void replaceArrayListMethods() {

    // go through all the variables that have been declared as vectors
    // and replace the add and get methods
    // note that this can be incorrect because
    // you could use the same name
    // to hold another object that has add and get methods but hey
    // the chances are pretty low and we start this easy yeah?
    // you could assign the arrayList to another

    for (int i = 0; i < arrayListVariables.size(); i++) {

      println("mapping all add and get methods of arrayList variable: " + arrayListVariables.get(i));

      transformedProgram = transformedProgram.replaceAll(
      //characterThatCanBeAroundAVariable +
      arrayListVariables.get(i) +
        "\\s*\\.\\s*addArgCount1\\s*\\(",
      " "+arrayListVariables.get(i)+".push("
        );

      transformedProgram = transformedProgram.replaceAll(
      //characterThatCanBeAroundAVariable +
      arrayListVariables.get(i) +
        "\\s*\\.\\s*sizeArgCount0\\s*\\(\\s*\\)",
      " "+arrayListVariables.get(i)+".length"
        );

      println(characterThatCanBeAroundAVariable +
        arrayListVariables.get(i) +
        "\\s*\\.\\s*addArgCount1\\s*\\(");

      String patternForFindingGetInvokations = characterThatCanBeAroundAVariable + arrayListVariables.get(i)+"\\s*\\.\\s*getArgCount1\\s*\\(";
      matcher = Pattern.compile(patternForFindingGetInvokations).matcher(transformedProgram);
      println(characterThatCanBeAroundAVariable + arrayListVariables.get(i)+"\\s*\\.\\s*getArgCount1\\s*\\(");
      while (matcher.find()) {
        int positionOfGet = matcher.start() + matcher.group().indexOf("getArgCount1");
        int positionOfOpeningBracket = matcher.start() + matcher.group().lastIndexOf("(");
        int positionOfClosingBracket = positionOfGet + matchRoundParens(transformedProgram.substring(positionOfGet,transformedProgram.length()));
        //println("this should be the g of get: >" +  transformedProgram.charAt(positionOfGet));
        //println("this should be the opening bracket: >" +  transformedProgram.charAt(positionOfOpeningBracket));
        //println("stuff around closed parend: " +
        //  transformedProgram.charAt(positionOfClosingBracket-4) +
        //  transformedProgram.charAt(positionOfClosingBracket-3) +
        //  transformedProgram.charAt(positionOfClosingBracket-2) +
        //  transformedProgram.charAt(positionOfClosingBracket-1) +
        //  " !!! >"+transformedProgram.charAt(positionOfClosingBracket-0) + "< !!! " +
        //  transformedProgram.charAt(positionOfClosingBracket+1) +
        //  transformedProgram.charAt(positionOfClosingBracket+2) +
        //  transformedProgram.charAt(positionOfClosingBracket+3) +
        //  transformedProgram.charAt(positionOfClosingBracket+4)
        //);

        transformedProgram = transformedProgram.substring(0,positionOfGet - 1) +
          "[" +
          transformedProgram.substring(positionOfOpeningBracket + 1, positionOfClosingBracket ) +
          "]" + 
          transformedProgram.substring(positionOfClosingBracket + 1, transformedProgram.length());

        // once you've made all the substitutions above, you have to re-build the matcher
        // otherwise you'll get subsequent matches on the old string
        matcher = Pattern.compile(patternForFindingGetInvokations).matcher(transformedProgram);
      }
    }
  }


  public static void collectArrayListVariables() {
    arrayListVariables = new Vector();

    matcher = Pattern.compile("(static)?[\\n\\s\\t]var\\s*(\\w+)\\s*\\:\\s*ArrayList").matcher(transformedProgram);
    while (matcher.find()) arrayListVariables.add(matcher.group(2));

    for (int i = 0; i < arrayListVariables.size(); i++) {
      println("arrayList variable: " + arrayListVariables.get(i));
    }
  }

  public static void enableTheMouseEventCallsThatNeedBe() {

    matcher = Pattern.compile("public\\s*static\\s*function\\s*mouseClickedArgCount0\\(\\s*\\)\\:\\s*Void\\s*\\{").matcher(transformedProgram);
    if (matcher.find()) transformedProgram = transformedProgram.replaceAll("\\/\\/onlyIfMouseClickedFunctionExists","");

    matcher = Pattern.compile("public\\s*static\\s*function\\s*mouseMovedArgCount0\\(\\s*\\)\\:\\s*Void\\s*\\{").matcher(transformedProgram);
    if (matcher.find()) transformedProgram = transformedProgram.replaceAll("\\/\\/onlyIfMouseMovedFunctionExists","");

    matcher = Pattern.compile("public\\s*static\\s*function\\s*mouseDraggedArgCount0\\(\\s*\\)\\:\\s*Void\\s*\\{").matcher(transformedProgram);
    if (matcher.find()) transformedProgram = transformedProgram.replaceAll("\\/\\/onlyIfMouseDraggedFunctionExists","");

    matcher = Pattern.compile("public\\s*static\\s*function\\s*mousePressedArgCount0\\(\\s*\\)\\:\\s*Void\\s*\\{").matcher(transformedProgram);
    if (matcher.find()) transformedProgram = transformedProgram.replaceAll("\\/\\/onlyIfMousePressedFunctionExists","");

    matcher = Pattern.compile("public\\s*static\\s*function\\s*mouseReleasedArgCount0\\(\\s*\\)\\:\\s*Void\\s*\\{").matcher(transformedProgram);
    if (matcher.find()) transformedProgram = transformedProgram.replaceAll("\\/\\/onlyIfMouseReleasedFunctionExists","");
  }

  // TODO
  // this method and the method matching the curly parens should really be factored into the same code
  public static int matchRoundParens(String toMatch) {

    int parethesesNesting = 0;
    int charScanning = 0;
    boolean enterParen = false;

    while(true) {
      //println("matchRoundParens: " + charScanning + " char: " + toMatch.charAt(charScanning));
      char theChar = toMatch.charAt(charScanning);

      if (!enterParen && theChar == '(') {
        enterParen = true;
        charScanning++;
        continue;
      }

      if (!enterParen && theChar != ')') {
        charScanning++;
        continue;
      }

      if (theChar == '(')
        parethesesNesting++;

      if (theChar == ')')
        parethesesNesting--;


      if (parethesesNesting == -1 )
        return charScanning;

      charScanning++;
    }
  }
 
 

  public static int matchCurlyParens(String toMatch) {

    int parethesesNesting = 0;
    int charScanning = 0;
    boolean enterParen = false;

    while(true) {
      //println("matchCurlyParens: " + charScanning + " char: " + toMatch.charAt(charScanning));
      char theChar = toMatch.charAt(charScanning);

      if (!enterParen && theChar == '{') {
        enterParen = true;
        charScanning++;
        continue;
      }

      if (!enterParen && theChar != '}') {
        charScanning++;
        continue;
      }

      if (theChar == '{')
        parethesesNesting++;

      if (theChar == '}')
        parethesesNesting--;


      if (parethesesNesting == -1 )
        return charScanning;

      charScanning++;
    }
  }

  // found a better way to do this but keeping the code here just in case
  /*
    public static void addPushAndPopMatricAtTopAndBottomOfDrawMethod () {
   pattern = Pattern.compile("public\\s*static\\s*function\\s*drawArgCount0\\s*\\(\\s*event\\:Event\\)\\:\\s*Void\\s*\\{");
   System.out.println("pattern: "+ pattern);
   matcher = pattern.matcher(transformedProgram);
   matcher.find();
   
   int endOfFunctionPosition = matchCurlyParens(transformedProgram.substring(matcher.start(),transformedProgram.length()));
   
   
   transformedProgram =
   transformedProgram.substring(0,matcher.end()) +
   "\nstartOfDrawMethod();\n" +
   transformedProgram.substring(matcher.end()+1, matcher.start() + endOfFunctionPosition) + 
   "\nendOfDrawMethod();\n" +
   transformedProgram.substring(matcher.start() + endOfFunctionPosition, transformedProgram.length())
   ;
   }
   */

  public static void putAllTopLevelInitialisationsInConstructor () {

    // instance variables cannot be initialised outside a piece of code
    // so we need, for each class,  to
    // move all initialisations of instance
    // variables inside its constructor

      System.out.println("putAllTopLevelInitialisationsInConstructor ///////////////////////");

    // ------ we iterate in each class
    pattern = Pattern.compile("\\s*class\\s*(\\w+)\\s*(extends\\s+\\w+)?\\s*\\{[^~]*");
    System.out.println("pattern: "+ pattern);
    matcher = pattern.matcher(transformedProgram);
    while (matcher.find()) {
      String className = matcher.group(1);
      String classBody = matcher.group();
      println("visiting class " + className);
      if (className.equals("Main")) {
        transformedProgram = transformedProgram.replaceAll("class\\s*Main","class Main /*visited*/ ");
        matcher = pattern.matcher(transformedProgram);
        println("finished visiting class " + className);
        continue;
      }


      Vector variables = new Vector();
      Vector types = new Vector();
      Vector initialisation = new Vector();

      Pattern initialisedVariables = Pattern.compile(
      "public\\s*var\\s*(\\w+)\\s*:\\s*(\\w+)\\s*(\\=\\s*[^\\;]*)"
        );
      Matcher matcher2 = initialisedVariables.matcher(classBody);

      while (matcher2.find()) {
        println("found variable  " + matcher2.group(1) +" of class " + matcher2.group(2) + " initialised to " + matcher2.group(3) );
        variables.add(matcher2.group(1) );
        types.add(matcher2.group(2) );
        initialisation.add(matcher2.group(3) );

        classBody = matcher2.replaceFirst("public var "+matcher2.group(1)+":"+matcher2.group(2));
        matcher2 = initialisedVariables.matcher(classBody);
      }
      println("collected all variables, now adding the inits in the setup method" );


      String initString = "";
      for (int i = 0; i < initialisation.size(); i++) {
        initString = initString + "\n " + variables.get(i) + " " + initialisation.get(i) + ";";
      }
      println("init string will be: " + initString );

      Pattern constructorsPatterns;

      //if (sketchName.equals(className)) {
      //   constructorsPatterns = Pattern.compile(
      //        "/\\*putInitialisationOfMainSketchTopLevelVariablesHere\\*/"
      //      );
      //}
      //else {
      constructorsPatterns = Pattern.compile(
      //                "super\\(\\)\\;"
      // capture everything in the beginning of the constructor up to the open curly brace
      // including the curly brace
      "public\\s*function\\s*new\\s*\\(([^\\{]*\\{)"
        );
      //}

      /*putInitialisationOfMainSketchTopLevelVariablesHere*/
      Matcher matcher3 = constructorsPatterns.matcher(classBody);
      while (matcher3.find()) {
        println("found the constructor");          

        //if (!sketchName.equals(className)) {
        //initString = "super()/*visitedSuper*/;" + initString;
        initString = "public function new/*visitedConstructor*/("+matcher3.group(1)+"\n" + initString;
        //}

        classBody = matcher3.replaceFirst(initString);
        matcher3 = constructorsPatterns.matcher(classBody);
      }

      // this is for marking the class as visited,
      // otherwise you'll keep finding the same first class
      String extensionBit = matcher.group(2);
      if (extensionBit == null) extensionBit = "";
      classBody = classBody.replaceAll("\\s*class\\s*"+className+"\\s*(extends\\s+\\w+)?\\s*\\{", "\n class "+className+" "+extensionBit+" /*visited*/ {");
      //transformedProgram = transformedProgram.substring(0,matcher.start()) + "\n"+ matcher.replaceFirst(classBody);
      transformedProgram = matcher.replaceFirst(classBody);
      println("program updated with new body of class " + className);

      // now replace the matcher with one working on the
      // new program with the visited class with replaced references
      matcher = pattern.matcher(transformedProgram);
    } // closed the while looping through classes

    println("visited all classes");

    // last step, remove the "visited" tags that you left in your way
    transformedProgram = transformedProgram.replaceAll("/\\*visited\\*/","");
    transformedProgram = transformedProgram.replaceAll("/\\*visitedConstructor\\*/","");
  }

  // this is not needed anymore as I found a better way but I'd like to keep this code
  // for future refernce
  /*
    // if you want to register the draw function as the handler of the ENTER_FRAME
   // event then Haxe/Flash forces you to make draw receive an Event as a parameter
   // so we need to fix both the definition and all the invokations
   public static void fixReferencesToDrawFunctionSoThatEventIsPassed () {
   transformedProgram = transformedProgram.replaceAll(
   "public static function drawArgCount0\\s*\\(",
   "public static function drawArgCount0 ( event:Event"
   );
   transformedProgram = transformedProgram.replaceAll(
   "Main.theSketch.drawArgCount0\\s*\\(",
   "Main.theSketch.drawArgCount0\\(null"
   );
   }
   */

  public static String stripPreFunctionCode() {
    Matcher matcherFunctionDefinition = Pattern.compile("[\\n\\s\\t]*\\w+\\s*\\w+\\s*\\(").matcher(transformedProgram);
    String toBeReturned = "";       
    if (!matcherFunctionDefinition.find()) {
      transformedProgram = "";
    }
    else {
      toBeReturned = transformedProgram.substring(0,matcherFunctionDefinition.start());
      transformedProgram = transformedProgram.substring(matcherFunctionDefinition.start(), transformedProgram.length());
      //System.out.println("toBeReturned: >"+ toBeReturned + "<");
      //System.out.println("transformedProgram: >"+ transformedProgram + "<");
      //System.exit(0);
    }
    return toBeReturned;
  }

  public static String stripPreClassCode() {
    Matcher matcherClassDefinition = Pattern.compile("\\s*class\\s*\\w+\\s*(extends\\s+\\w+)?\\s*\\{").matcher(transformedProgram);
    String toBeReturned = "";       
    if (!matcherClassDefinition.find()) {
      transformedProgram = "";
    }
    else {
      toBeReturned = transformedProgram.substring(0,matcherClassDefinition.start());
      transformedProgram = transformedProgram.substring(matcherClassDefinition.start(), transformedProgram.length());
    }
    return toBeReturned;
  }

  public static boolean containsClassDefinition() {
    Matcher matcherClassDefinition = Pattern.compile("\\s*class\\s*\\w+\\s*(extends\\s+\\w+)?\\s*\\{").matcher(transformedProgram);
    if (matcherClassDefinition.find()) {
      return true;
    }
    else {
      return false;
    }
  }

  public static boolean isMainFile() {
    Matcher matcherSetupMethod = Pattern.compile("[\\n\\s\\t]*void\\s*setup\\s*\\(").matcher(transformedProgram);
    Matcher matcherClassDefinition = Pattern.compile("\\s*class\\s*\\w+\\s*(extends\\s+\\w+)?\\s*\\{").matcher(transformedProgram);

    println("checking if setup method is there at all");
    if (!matcherSetupMethod.find()) return false;

    println("checking if there is no class definition");
    if (!matcherClassDefinition.find()) return true;

    println("checking whether the setup comes before a class definition");
    //println(matcherSetupMethod.start() +" " + matcherClassDefinition.start());
    if (matcherSetupMethod.start()  <  matcherClassDefinition.start()) return true;

    return false;
  }


  public static void removeMouseVariables () {      
    transformedProgram = transformedProgram.replaceAll( "public\\s*static\\s*var\\s*mousePressed\\s*\\:\\s*Bool\\s*\\;","");      
    transformedProgram = transformedProgram.replaceAll( "public\\s*static\\s*var\\s*keyPressed\\s*\\:\\s*Bool\\s*\\;","");
    transformedProgram = transformedProgram.replaceAll( "public\\s*static\\s*var\\s*mouseX\\s*\\:\\s*Int\\s*\\;","");
    transformedProgram = transformedProgram.replaceAll( "public\\s*static\\s*var\\s*mouseY\\s*\\:\\s*Int\\s*\\;","");
    transformedProgram = transformedProgram.replaceAll( "public\\s*static\\s*var\\s*pmouseX\\s*\\:\\s*Int\\s*\\;","");
    transformedProgram = transformedProgram.replaceAll( "public\\s*static\\s*var\\s*pmouseY\\s*\\:\\s*Int\\s*\\;","");
  }

  public static void removeFrameCountVariable () {      
    transformedProgram = transformedProgram.replaceAll(
    "public\\s*static\\s*var\\s*frameCount\\s*\\:\\s*Int\\s*\\;",
    ""
      );
  }


  public static void removeEmptyPrintlnAndIntDefinition () {

    transformedProgram = transformedProgram.replaceAll(
    "public function printlnArgCount1\\(a\\s\\:\\sString\\)\\:\\sVoid\\s\\{\\n\\}",
    ""
      );
    transformedProgram = transformedProgram.replaceAll(
    "public function intArgCount1\\(a\\s\\:\\sInt\\)\\:\\sInt\\s\\{\\n\\}",
    ""
      );
  }


  public static void addPrintlnFunction () {
    transformedProgram = transformedProgram.replaceAll("public function setupArgCount0\\(",
    "public function printlnArgCount1(a : String): Void {\n}\n\npublic function setupArgCount0(");
  }

  public static void addFrameCountVariable () {
    transformedProgram = "public static var frameCount:Int;\n" + transformedProgram;
  }

  public static void addMouseVariables () {
    transformedProgram = "public static var mousePressed:Bool;\n" + transformedProgram;
    transformedProgram = "public static var keyPressed:Bool;\n" + transformedProgram;
    transformedProgram = "public static var mouseX:Int;\n" + transformedProgram;
    transformedProgram = "public static var mouseY:Int;\n" + transformedProgram;
    transformedProgram = "public static var pmouseX:Int;\n" + transformedProgram;
    transformedProgram = "public static var pmouseY:Int;\n" + transformedProgram;
  }

  public static void addIntFunction () {
    transformedProgram = transformedProgram.replaceAll("public function setupArgCount0\\(",
    "public function intArgCount1(a : Int): Int {\n}\n\npublic function setupArgCount0(");
  }


  public static void addHeaderToSketchClass () {
    transformedProgram = transformedProgram.replaceAll("class Main extends Sprite \\{","");

    //String addedBit = "class " + sketchName + " extends PApplet {" + "\n"+
    String addedBit = "class Main extends Bitmap {" + "\n"+
      //"  public function new() {" + "\n"+
    //"    super();" + "\n"+
    //"  }" + "\n"+
    "" + "\n"+
      "  public function initialiseTopLevelVariables() {" + "\n"+
      "    /*putInitialisationOfMainSketchTopLevelVariablesHere*/" + "\n"+
      "  }" + "\n"+
      "";
    transformedProgram = addedBit + transformedProgram;
  }

  public static void cleanupArgCountForConstructors () {
    transformedProgram = transformedProgram.replaceAll("\\s*function\\s*newArgCount\\d+\\("," function new (");

    for (int i = 0; i < namesOfClassesCreatedByUsers.size(); i++) {
      transformedProgram = transformedProgram.replaceAll(
      "new\\s+"+namesOfClassesCreatedByUsers.get(i)+"ArgCount\\d+",
      "new "+namesOfClassesCreatedByUsers.get(i));
    }

    for (int i = 0; i < namesOfSystemClasses.size(); i++) {
      // skip ArrayLists cause they are handled separately - they
      // require special handling because they specify a type in brackets
      // and there is a translation of some of its methods.
      if ((namesOfSystemClasses.get(i)+"").equals("ArrayList")) continue;
      transformedProgram = transformedProgram.replaceAll(
      "new\\s+"+namesOfSystemClasses.get(i)+"ArgCount\\d+",
      "new "+mapTheProcessingTypeToHaxe(""+namesOfSystemClasses.get(i)));
    }
  }

  public static void cleanupClassSeparators () {
    transformedProgram = transformedProgram.replaceAll("/\\* closed class~ \\*/","");
    transformedProgram = transformedProgram.replaceAll("/\\* closing token for the last class ~ \\*/","");
  }

  public static void adjustReferencesToMainClassVariablesAndFunctions () {
    // ok this is one of the more complicated transformations
    // What it does is it goes and finds all references to "top-level" variables
    // and functions, and replaces those with [sketchName].reference
    // So for example any class that calls the draw(); method will now call the
    // [sketchName].draw() method.
    // Before making the substitution, we check whether the draw() method is also
    // defined locally in the class we are manipulating. This is because if there is
    // a local draw() declaration then calling the [sketchName].draw() method would be wrong.
    // Also note that in for loops there is an implicit variable declaration
    // that you can't substitute
    // e.g. in
    //  for(k in 1... 
    // the k shouldn't be transformed in Main.k if there is a k variable declared top-level
    // so we do that check too

    // So, in order to do this transformation
    //  1) we find all variables and methods in the Main class and for each of those
    //      2) we iterate in each other class
    //      3) if the class in question has a definition for it
    //          of it's an argument in a function definition , then we move on
    //          to the next class
    //      4) if the class in question hasn't got a definition of the
    //          variable, and the variable doesn't appear to be passed
    //          as a parameter in a function anywhere, we replace the
    //          reference with [sketchName].reference

    // 1 ------ find all variables and methods in the Main class

      variablesDeclaredInMainClass = new Vector();
    functionsAndVariablesDeclaredInMainClass = new Vector();
    functionsDeclaredInMainClass = new Vector();

    System.out.println("adjustReferencesToMainClassVariablesAndFunctions ///////////////////////");

    String mainClassContents = "";
    matcher = Pattern.compile("\\s*class Main(\\s*extends\\s*Sprite\\s*)?\\{[^~]*").matcher(transformedProgram);
    if (matcher.find()) mainClassContents = matcher.group();

    // find all the variables and put them in a vector
    matcher = Pattern.compile("\\s*class Main(\\s*extends\\s*Sprite\\s*)?\\{[^~]*").matcher(transformedProgram);
    while (matcher.find()) {
      Matcher matcher2 = Pattern.compile("\\n[ \\t]*public\\s*static\\s*var\\s*(\\w+)").matcher(transformedProgram);
      while (matcher2.find()) {
        variablesDeclaredInMainClass.add(matcher2.group(1));
        functionsAndVariablesDeclaredInMainClass.add(matcher2.group(1));
        println("variable in Main class: " + matcher2.group(1));
        //if (matcher2.group(1).equals("handy")) {
        // println("variable in Main class: " + matcher2.group(0));
        // System.exit(0);
        //  
        //}
      }
    }

    // find all the functions and put them in a vector
    matcher = Pattern.compile("\\s*class Main(\\s*extends\\s*Sprite\\s*)?\\{[^~]*").matcher(transformedProgram);
    //String staticInlineBit = ""
    while (matcher.find()) {
      //println("searching for functions declared within the main body here: " + matcher.group(0));
      //System.exit(0);
      //Matcher matcher2 = Pattern.compile("\\s*public\\s*((static)?\\s*(inline)?)?\\s*function\\s*(\\w+)").matcher(transformedProgram);
      Matcher matcher2 = Pattern.compile("\\s*public\\s*((static)?\\s*(inline)?)?\\s*function\\s*(\\w+)").matcher(matcher.group(0));
      while (matcher2.find()) {
        //staticInlineBit = matcher2.group(1);
        functionsDeclaredInMainClass.add(matcher2.group(4));
        functionsAndVariablesDeclaredInMainClass.add(matcher2.group(4));
        println("function in Main class: " + matcher2.group(4));
      }
    }

    // 2 ------ we iterate in each class other than the Main one
    pattern = Pattern.compile("\\s*class\\s*(\\w+)\\s*\\{[^~]*");
    matcher = pattern.matcher(transformedProgram);
    while (matcher.find()) {
      String className = matcher.group(1);
      String classBody = matcher.group();

      println("visiting class " + className);

      //if (className.equals("EhsvgFileParser"))
      //   println("class body before substitution:---------------------------------\n" +classBody + "\n -----------------------------------------");

      //if (className.equals("EhsvgFileParser")) {
      //   println("whole program before:---------------------------------\n" +transformedProgram + "\n -----------------------------------------");
      //   System.exit(1);
      //}

      for (int i = 0; i < functionsAndVariablesDeclaredInMainClass.size(); i++) {

        Matcher matcherForAlreadyDeclaredVariablesOrFunctionsOrArgument = Pattern.compile(
        "((\\n[ \\t]*(public )?(var|function)\\s*"+
          functionsAndVariablesDeclaredInMainClass.get(i)+"\\s*[:|\\(])|"+
          "([\\s\\(\\,]\\s*"+functionsAndVariablesDeclaredInMainClass.get(i)+"\\s*\\:))"
          ).matcher(classBody);


        Matcher matcherForVariablesImplicitlyDeclaredInForLoops = Pattern.compile(
        "[\\n\\t\\s]for\\s*\\(\\s*"+
          functionsAndVariablesDeclaredInMainClass.get(i)+"\\s+in\\s"
          ).matcher(classBody);

        /*
     if (className.equals("EhsvgFileParser")) {
         println("pattern: " + "\\s*(((var|function)\\s*"+
         functionsAndVariablesDeclaredInMainClass.get(i)+"\\s*[:|\\(])|"+
         "([\\s\\(\\,]"+functionsAndVariablesDeclaredInMainClass.get(i)+"\\s*\\:))");
         }
         */

        //      3) if the class in question has a definition for it
        //          of it's an argument in a function definition,
        //          OR it's a variable of a for loop, then we move on
        //          to the next class
        if (matcherForAlreadyDeclaredVariablesOrFunctionsOrArgument.find() || matcherForVariablesImplicitlyDeclaredInForLoops.find()) {
          println("  variable or function  " + functionsAndVariablesDeclaredInMainClass.get(i) +" is already declared in class " + className);
          continue;
        }
        //      4) if the class in question hasn't got a definition of the
        //          variable, and the variable doesn't appear to be passed
        //          as a parameter in a function anywhere, we replace the
        //          reference with [sketchName].reference
        else {
          /*
          if (className.equals("EhsvgFileParser"))
           println("  variable/function >" + functionsAndVariablesDeclaredInMainClass.get(i) +"< not declared in class " + className );
           */
          Pattern pattern3 = Pattern.compile("("+characterThatCanBeAroundAVariable+")"+
            functionsAndVariablesDeclaredInMainClass.get(i)+"("+ characterThatCanBeAroundAVariablePlusDot +")");
          Matcher matcher3 = pattern3.matcher(classBody);
          while (matcher3.find()) {

            //String theReplacement = matcher3.group(1) + "/*visitedVar*/" + variablesDeclaredInMainClass.get(i) + matcher3.group(2);
            String theReplacement = matcher3.group(1) +  "Main." + functionsAndVariablesDeclaredInMainClass.get(i) + matcher3.group(2);
            /*
            if (className.equals("EhsvgFileParser"))
             println("     >>> substituting in: >" + matcher3.group() + "< with: >" + theReplacement + "<");
             */
            classBody = matcher3.replaceFirst(theReplacement);
            matcher3 = pattern3.matcher(classBody);
          }
        }
      }

      // this is for marking the class as visited,
      // otherwise you'll keep finding the same first class
      classBody = classBody.replaceAll("\\s*class\\s*"+className+"\\s*\\{", "\n class "+className+" /*visited*/ {");
      transformedProgram = matcher.replaceFirst(classBody);
      println("program updated with new body of class " + className);

      //if (className.equals("EhsvgFileParser"))
      //   println("class body after substitution:---------------------------------\n" +classBody + "\n -----------------------------------------");

      /*
      if (className.equals("EhsvgFileParser")) {
       println("whole program:---------------------------------\n" +transformedProgram + "\n -----------------------------------------");
       System.exit(1);
       }
       */

      // now replace the matcher with one working on the
      // new program with the visited class with replaced references
      matcher = pattern.matcher(transformedProgram);
    } // closed the while looping through classes

    println("visited all classes");

    // last step, remove the "visited" tags that you left in your way
    transformedProgram = transformedProgram.replaceAll("/\\*visited\\*/","");
    //System.exit(0);
  }

  public static void terminateClassesWithSpecialCharacters () {
    setPattern("\\}"+"([\\t\\n\\s]*class\\s*"+identifier+"\\s*\\{)");

    enterTransfStage("terminateClassesWithSpecialCharacters"); 

    while (performReplaceAndFindNextMatch()) {
      replacement = "} /* closed class~ */\n" + matcher.group(1);
    }
    transformedProgram += "\n /* closing token for the last class ~ */\n";
    exitTransfStage();
  }

  public static void wrapTopLevelDeclarationsInStaticClass() {

    int beginningOfSetup = -1;  // beginningOfSetup = -1, beginningOfDraw = -1;
    int beginningOfClass = -1;  // beginningOfSetup = -1, beginningOfDraw = -1;

    matcher = Pattern.compile("\\n\\s*function\\s*\\w+\\s*\\(").matcher(transformedProgram);
    if (matcher.find()) beginningOfSetup = matcher.start();
    //matcher = Pattern.compile("\\n\\s*function\\s*drawArgCount0\\s*\\(").matcher(transformedProgram);
    //if (matcher.find()) beginningOfDraw = matcher.start();

    //Matcher matcher2 = Pattern.compile("\\n\\s*class\\s*\\w+\\s*\\{").matcher(transformedProgram);
    Matcher matcher2 = Pattern.compile("\\/\\*\\s*end\\s*of\\s*class\\s*\\~\\s*\\*\\/").matcher(transformedProgram);
    if (matcher2.find()) beginningOfClass = matcher2.start();

    //println(beginningOfSetup +"  "+ beginningOfDraw +"  "+beginningOfClass);

    /*
    int endOfTopLevelCode = 0;
     
     if (beginningOfDraw < beginningOfSetup && beginningOfDraw < beginningOfClass )
     endOfTopLevelCode = beginningOfDraw;
     
     if (beginningOfSetup < beginningOfDraw && beginningOfSetup < beginningOfClass )
     endOfTopLevelCode = beginningOfSetup;
     
     if (beginningOfClass < beginningOfDraw && beginningOfClass < beginningOfSetup )
     endOfTopLevelCode = beginningOfClass;
     */

    transformedProgram = "class Main extends Sprite {\n" +
      transformedProgram.substring(0,beginningOfSetup).replaceAll("var ","public static var ")+

      transformedProgram.substring(beginningOfSetup,beginningOfClass).replaceAll("\\n\\s*(public)?\\s*function ","\n\n public static function ")+

      "\n} // end of main class\n" + 
      transformedProgram.substring(beginningOfClass, transformedProgram.length()).
      replaceAll("\\n\\s*function ","\n\n public function ");
  }

  public static void trnsfrmBasicTypeDeclarationsWithSimpleInits() {
    setPattern("([\\t\\n\\s])"+classesPattern +"[ ]+"+"("+identifier+")"+"([^\\;]*)");

    enterTransfStage("trnsfrmBasicTypeDeclarationsWithSimpleInits");

    while (performReplaceAndFindNextMatch()) {
      //System.out.println("matched: >" + matcher.group(0) + "<");
      //System.out.println("pattern: " + "([\\t\\n\\s])"+classesPattern +"[ ]+"+"("+identifier+")"+"([^\\;]*)");
      replacement = matcher.group(1) + "var "+ matcher.group(3) + ": " +
        mapTheProcessingTypeToHaxe(matcher.group(2)) + matcher.group(4);
    }

    exitTransfStage(); 
    transformedProgram = transformedProgram.replaceAll("/\\*visited\\*/","");
  }


  public static void addParametersCountToFunctionNames() {
    // we isolate a function up to the first semicolon or open bracket
    // this is because we have to stop somewhere and it's reasonable to expect
    // that those characters are not inside a function parenthesys.
    // note that this is not entirely true cause you could pass
    // a string with those characters inside it or pass an
    // argument that is a result of another function...
    // [todo]
    setPattern("("+characterThatCanBeAroundAFunction+")"+"("+identifier+")("+spaces+"\\("+spaces+"([^\\)\\;]*)\\))");

    enterTransfStage("addParametersCountToFunctionNames"); 

    while (performReplaceAndFindNextMatch()) {

      if (
      !matcher.group(2).equals("if") &&
        !matcher.group(2).equals("for") &&
        !matcher.group(2).equals("while") &&
        !matcher.group(2).equals("return") &&
        !matcher.group(2).equals("switch") 
        ) {

        // this small routine counts the commas at the top level of arguments of functions
        // i.e. line(a,b,random(1,2,random(1,5),4,5),5,6)
        // gives a count of 5, not a count of 10 that you'd have if you
        // just counted the commas
        int numberOfArguments = 0;        
        int parethesesNesting = 0;
        int charScanning = 0;
        int actualStartOfFunction = 0;
        boolean enterParen = false;
        boolean atLeastOneArgument = false;
        //println("examining: " + matcher.group());
        //if (matcher.group(2).equals("int")) println("examining: " + matcher.group());
        while(true) {
          actualStartOfFunction = matcher.start() + matcher.group().indexOf(matcher.group(2));
          //if (matcher.group(2).equals("int")) println("charScanning: " + charScanning + " char: " + transformedProgram.charAt(actualStartOfFunction+charScanning));
          //println("charScanning: " + charScanning + " char: " + transformedProgram.charAt(actualStartOfFunction+charScanning));
          char theChar = transformedProgram.charAt(actualStartOfFunction + charScanning);

          if (!enterParen && theChar == '(') {
            enterParen = true;
            charScanning++;
            continue;
          }

          if (!enterParen && theChar != '(') {
            charScanning++;
            continue;
          }

          if (theChar != ' ')
            atLeastOneArgument = true;

          if (theChar == '(')
            parethesesNesting++;

          if (theChar == ')')
            parethesesNesting--;

          if (parethesesNesting == 0 && theChar == ',') {
            numberOfArguments++;
            //if (matcher.group(2).equals("int")) println("one more comma found, total commas found: "+ numberOfArguments );
          }

          if (parethesesNesting == -1 )
            break;

          charScanning++;
        }
        numberOfArguments++;

        if (!atLeastOneArgument)
          numberOfArguments = 0;

        //if (matcher.group(2).equals("int")) println("string inside the parens: >"+matcher.group(4));
        if (matcher.group(4) == null || matcher.group(4).equals("")) numberOfArguments = 0;

        replacement = matcher.group(1)  +  matcher.group(2) + "ArgCount" +
          numberOfArguments + "/*argsCounted*/"+
          matcher.group(3);
      }
      else {
        replacement = matcher.group(1)  +  matcher.group(2) + "/*argsCounted*/"+
          matcher.group(3);
      }
    }
    transformedProgram = transformedProgram.replaceAll("/\\*argsCounted\\*/","");
    exitTransfStage();
  }



  public static void checkThereAreNoInitialisationsInInstanceVariables() {

    println("checkThereAreNoInitialisationsInInstanceVariables ////////////// ");

    for (int i = 0; i < namesOfClassesCreatedByUsers.size(); i++) {
      pattern = Pattern.compile("class"+spaces+namesOfClassesCreatedByUsers.get(i)+spaces+"\\{"+"[^{]*");
      matcher = pattern.matcher(transformedProgram);
      println("checking class " + namesOfClassesCreatedByUsers.get(i));

      String instanceVariablesPart = "";    

      if (matcher.find()) {
        instanceVariablesPart = matcher.group();    

        Pattern pattern2 = Pattern.compile("\\n\\s*(public\\s*var\\s*\\w+\\s*\\:\\s*\\w+\\s*=)");
        Matcher matcher2 = pattern2.matcher(instanceVariablesPart);
        while (matcher2.find()) {
          println("found an instance variable with initialisations: " + matcher2.group(1));
          replacement = "\n\n// warning: Haxe can't initialise a non-static instance variable\n// the translator will do its best to initialise\n// this variable at the top of the constructor\n/*visited*/"+matcher2.group(1);      
          println("replacing with: "+ replacement);
          instanceVariablesPart = matcher2.replaceFirst(replacement);
          matcher2 = pattern2.matcher(instanceVariablesPart);
        } // end of adding error on all initialised instance variables

        transformedProgram = matcher.replaceFirst(instanceVariablesPart);
        matcher = pattern.matcher(transformedProgram);
      } // end of processing the instance variables part of the class
    } // end of for cycling through all the class names

    transformedProgram = transformedProgram.replaceAll("/\\*visited\\*/","");
  }

  public static void makeAllInstanceVariablePublic() {

    for (int i = 0; i < namesOfClassesCreatedByUsers.size(); i++) {
      setPattern("class"+spaces+namesOfClassesCreatedByUsers.get(i)+spaces+"\\{"+"[^{]*");
      enterTransfStage("makeAllInstanceVariablePublic"+namesOfClassesCreatedByUsers.get(i));    
      performReplaceAndFindNextMatch(); 
      println("found: "+matcher.group());
      replacement = matcher.group().replaceAll("\\n\\s*var","\n public var");
      println("replacing with: "+ replacement);
      performReplaceAndFindNextMatch(); 

      exitTransfStage();
    } // end of for cycling through all the class names
  }

  public static void fixContructors() {

    for (int i = 0; i < namesOfClassesCreatedByUsers.size(); i++) {
      //setPattern("([\\{|\\;|\\}])"+spaces+"(\\n[\\t|\\s]*)"+"("+namesOfClassesCreatedByUsers.get(i)+")"+spaces+"\\(");
      setPattern("(\\n[\\t|\\s]*)"+"("+namesOfClassesCreatedByUsers.get(i)+")"+spaces+"\\(");

      enterTransfStage("fixContructor"+namesOfClassesCreatedByUsers.get(i));    

      while (performReplaceAndFindNextMatch()) {
        String linesAndSpacesPrecedingConstructorDefinition = matcher.group(1);
        if (linesAndSpacesPrecedingConstructorDefinition == null)
          linesAndSpacesPrecedingConstructorDefinition = "";

        println("Found constructor of class :>" + matcher.group(2)+"<");
        replacement = "\n" + "public function new(";
      }

      exitTransfStage();
    } // end of for cycling through all the class names
  }


  public static void findNamesOfUserDefinedClasses() {
    namesOfClassesCreatedByUsers = new Vector();
    namesOfSystemTypes = new Vector();
    namesOfSystemClasses = new Vector();

    namesOfSystemTypes.add("int");
    namesOfSystemTypes.add("float");
    namesOfSystemTypes.add("double");
    namesOfSystemTypes.add("short");
    namesOfSystemTypes.add("color");
    namesOfSystemTypes.add("void");
    namesOfSystemTypes.add("boolean");

    namesOfSystemClasses.add("String");
    namesOfSystemClasses.add("ArrayList");
    namesOfSystemClasses.add("PGraphics");
    namesOfSystemClasses.add("Rectangle");

    if (foundReferencesToMinimSoundLibrary) {
      namesOfSystemClasses.add("Minim");
      namesOfSystemClasses.add("AudioSnippet");
      namesOfSystemClasses.add("AudioPlayer");
      namesOfSystemClasses.add("AudioOutput");
      namesOfSystemClasses.add("AudioPlayer");
    }

    if (foundReferencesToProcessingNetLibrary) {
      namesOfSystemClasses.add("Client");
    }

    classesPattern = "(";
    //classesPattern = "(int|float|short|color|String|void|boolean|ArrayList|PGraphics|Rectangle";

    for (int k = 0; k< namesOfSystemTypes.size(); k++ )
      classesPattern = classesPattern + namesOfSystemTypes.get(k) + "|";

    // note the small hack cause we want the last one not to have
    // the trailing pipe simbol.
    for (int k = 0; k< namesOfSystemClasses.size()-1; k++ )
      classesPattern = classesPattern + namesOfSystemClasses.get(k) + "|";
    classesPattern = classesPattern + namesOfSystemClasses.get(namesOfSystemClasses.size()-1);


    setPattern("class"+spaces+"("+identifier+")"+
      spaces+"\\{"
      );

    enterTransfStage("findNamesOfUserDefinedClasses");

    while (matcher.find()) {
      println("Found user-defined class :>" + matcher.group(1)+"<");
      namesOfClassesCreatedByUsers.add(matcher.group(1));
      classesPattern = classesPattern+"|"+ matcher.group(1);
    }
    classesPattern = classesPattern+")";

    exitTransfStage();
  }


  public static void trnsfrmForLoopWithExplicitIncrement() {
    setPattern("for"+spaces+"\\("+spaces+"int"+spaces+"("+identifier+")"+
      spaces+"="+spaces+"([^\\;]*)"+spaces+"\\;"+spaces+"\\1"+spaces+"<"+
      spaces+"([^\\;]*)"+spaces+"\\;"+spaces+"\\1"+spaces+"\\="+
      spaces+"\\1"+spaces+"\\+"+spaces+"1"+spaces+"\\)"
      );

    enterTransfStage("trnsfrmForLoop");

    while (performReplaceAndFindNextMatch()) {
      println("Lower bound of for loop :>" + matcher.group(2)+
        "< upper bound: >"+matcher.group(3)+"<");
      replacement = "for ("+matcher.group(1) + " in " +
        matcher.group(2)+" ... "+matcher.group(3)+")";
    }

    exitTransfStage();
  }

  public static void trnsfrmForLoopWithPlusPlusIncrement() {
    setPattern("for"+spaces+"\\("+spaces+"int"+spaces+"("+identifier+")"+
      spaces+"="+spaces+"([^\\;]*)"+spaces+"\\;"+spaces+"\\1"+spaces+"<"+
      spaces+"([^\\;]*)"+spaces+"\\;"+spaces+"\\1"+spaces+"\\+"+
      spaces+"\\+"
      );
    println("Pattern for for loop: "+pattern);

    enterTransfStage("trnsfrmForLoop");

    while (performReplaceAndFindNextMatch()) {
      println("Lower bound of for loop :>" + matcher.group(2)+
        "< upper bound: >"+matcher.group(3)+"<");
      replacement = "for ("+matcher.group(1) + " in " +
        matcher.group(2)+" ... "+matcher.group(3);
    }

    exitTransfStage();
  }

  public static void trnsfrmMultipleDeclarationsInOneLine() {
    setPattern("\\n[\\t ]*(("+classesPattern+ anyNumberOfArrayBrackets+")"+
      "\\s+("+identifier+")"+anyNumberOfArrayBrackets+spaces+"),");

    enterTransfStage("trnsfrmMultipleDeclarationsInOneLine");

    while (performReplaceAndFindNextMatch()) {
      println("Type with array brackets is :>" + matcher.group(2));
      replacement = "\n"+matcher.group(1) + ";\n" +
        matcher.group(2) + " ";
    }

    exitTransfStage();
  }

  public static void trnsfrmArrayDeclNoInitBrcktsOnTypeSide() {
    setPattern(classesPattern+"("+anyNumberOfArrayBrackets+")"+
      "\\s+("+identifier+")"+ spaces + anyNumberOfArrayBrackets+spaces+"([;\\,\\)])");

    enterTransfStage("trnsfrmArrayDeclNoInitBrcktsOnTypeSide"); 

    while (performReplaceAndFindNextMatch()) {
      println("Type is:>" + matcher.group(1)+
        "< variable name is >"+matcher.group(4)+"<");

      String bracketsOnTypeSide = matcher.group(2);
      if (bracketsOnTypeSide == null) bracketsOnTypeSide = "";
      println("bracketsOnTypeSide is:>" + bracketsOnTypeSide+"<");

      int arrayDimension = bracketsOnTypeSide.replaceAll("[^\\[]", "").length();
      println("array dimension is:>" + arrayDimension + "<");

      String arrayNestingString = createNestedArrayString(arrayDimension, matcher.group(1));

      if (arrayDimension > 1)
        replacement = "\n// warning: using one-dimensional arrays is vastly more efficient\n"+
          "// warning: you'll have to manually initialise each array\n"+
          "//          in the dimensions beyond one\n";

      replacement = replacement + "var "+ matcher.group(4) + " : "+ arrayNestingString + matcher.group(6);
      println("replacing with:>" + replacement + "<");
    }
    exitTransfStage();
    //System.exit(1);
  }

  public static void trnsfrmArrayDeclBringBracketsOnTypeSide() {
    setPattern(classesPattern+anyNumberOfArrayBrackets+
      "\\s+("+identifier+")\\s*"+"("+atLeastOneArrayBracket+")");

    enterTransfStage("trnsfrmArrayDeclBringBracketsOnTypeSide"); 

    while (performReplaceAndFindNextMatch()) {
      println("Type is:>" + matcher.group(1)+
        "< brackets on the side of the type name: >"+matcher.group(2)+
        "< brackets on the side of the variable name: >"+matcher.group(4)+
        "< variable name: >"+matcher.group(3)+"<");

      String  bracketsOnTypeSide = matcher.group(2);
      if (bracketsOnTypeSide == null) bracketsOnTypeSide = "";

      replacement = matcher.group(1) + bracketsOnTypeSide +" "+
        matcher.group(4) +" "+ matcher.group(3) +" ";

      // we want to normalise the positions of type, square brackets
      // and variable names in order to make the regular
      // expressions simpler.
      replacement = replacement.replaceAll("\\s*\\[", "[");
      replacement = replacement.replaceAll("]", "] ");
      replacement = replacement.replaceAll("\\s+", " ");
    }

    exitTransfStage();
  }

  public static void trnsfrmTopLevelArrayDecWithCreationOfObj() {
    int positionOfFirstOpenCurlyBraxe = transformedProgram.indexOf("{");
    boolean makeTransf = true;

    String pattern = classesPattern+"("+anyNumberOfArrayBrackets+")"+
      "\\s+("+identifier+")\\s*=\\s*new\\s*\\1\\s*("+anyNumberOfArrayBrackets+")\\s*;";
    Matcher matcher = Pattern.compile(pattern).matcher(transformedProgram);

    enterTransfStage("trnsfrmTopLevelArrayDecWithCreationOfObj"); 

    while (matcher.find()) {
      makeTransf = true;
      if ( matcher.start() > positionOfFirstOpenCurlyBraxe) {
        println("found " + matcher.group() + " but it's not a top level one, skipping" );
        makeTransf = false;
        continue;
      }

      println("Type is:>" + matcher.group(1)+
        "< variable name is >"+matcher.group(4)+"<");

      String bracketsOnTypeSide = matcher.group(2);
      if (bracketsOnTypeSide == null) bracketsOnTypeSide = "";
      println("bracketsOnTypeSide is:>" + bracketsOnTypeSide+"<");

      int arrayDimension = bracketsOnTypeSide.replaceAll("[^\\[]", "").length();
      println("array dimension is:>" + arrayDimension + "<");

      String arrayNestingString = createNestedArrayString(arrayDimension, matcher.group(1));

      replacement = "var "+ matcher.group(4) + " : "+ arrayNestingString +" = new Array();";

      if (arrayDimension > 1)
        replacement =  "// warning: using one-dimensional arrays is vastly more efficient\n"+
          "// warning: you'll have to manually initialise each array\n"+
          "//          in the dimensions beyond one\n"+replacement;

      replacement = "\n"+ replacement;
      if (makeTransf) {
        println("replacing  with: " + replacement);
        transformedProgram = matcher.replaceFirst(replacement);
        matcher = Pattern.compile(pattern).matcher(transformedProgram);
      }
    }
  }


  public static void trnsfrmArrayDecWithCreationOfObj() {
    int positionOfFirstOpenCurlyBraxe = transformedProgram.indexOf("{");
    boolean makeTransf = true;

    String pattern = classesPattern+"("+anyNumberOfArrayBrackets+")"+
      "\\s+("+identifier+")\\s*=\\s*new\\s*\\1\\s*("+anyNumberOfArrayBrackets+")\\s*;";
    Matcher matcher = Pattern.compile(pattern).matcher(transformedProgram);

    enterTransfStage("trnsfrmArrayDecWithCreationOfObj"); 
    println("pattern: " + pattern );

    while (matcher.find()) {
      makeTransf = true;
      if ( matcher.start() < positionOfFirstOpenCurlyBraxe) {
        println("found " + matcher.group() + " but it's a top level one, skipping" );
        makeTransf = false;
        continue;
      }

      println("Type is:>" + matcher.group(1)+
        "< variable name is >"+matcher.group(4)+"<");

      String bracketsOnTypeSide = matcher.group(2);
      if (bracketsOnTypeSide == null) bracketsOnTypeSide = "";
      println("bracketsOnTypeSide is:>" + bracketsOnTypeSide+"<");

      int arrayDimension = bracketsOnTypeSide.replaceAll("[^\\[]", "").length();
      println("array dimension is:>" + arrayDimension + "<");

      String arrayNestingString = createNestedArrayString(arrayDimension, matcher.group(1));

      replacement = "// warning: you'll need to initialise this array manually\n"+
        "var "+ matcher.group(4) + " : "+ arrayNestingString +";";

      if (arrayDimension > 1)
        replacement =  "// warning: using one-dimensional arrays is vastly more efficient\n"+
          "// warning: you'll have to manually initialise each array\n"+
          "//          in the dimensions beyond one\n"+replacement;

      replacement = "\n"+ replacement;
      if (makeTransf) {
        println("replacing " + matcher.group() + " with " + replacement);
        transformedProgram = matcher.replaceFirst(replacement);
        matcher = Pattern.compile(pattern).matcher(transformedProgram);
      }
    }
  }


  public static void checkIfThereAreArrayInitialisations() {
    enterTransfStage("trnsfrmMultipleDeclarationsInOneLine"); 

    setPattern(classesPattern+"(("+anyNumberOfArrayBrackets+")"+
      "\\s+("+identifier+")\\s*=\\s*\\{)");      

    while (performReplaceAndFindNextMatch()) {
      replacement = "\n// error: you'll have to translate this initialisation manually\n"+
        matcher.group(1)+"/**/"+matcher.group(2);
    }

    transformedProgram = transformedProgram.replaceAll("/\\*\\*/","");
    exitTransfStage();
  }

  public static void checkUnsupportedTypes() {
    setPattern("[\\n\\s\\t](Exception|Object|char|byte)"+"(\\s+"+"("+anyNumberOfArrayBrackets+")"+
      "\\s*("+identifier+")\\s*)");

    enterTransfStage("trnsfrmMultipleDeclarationsInOneLine"); 

    while (performReplaceAndFindNextMatch()) {      
      replacement = " error: can't translate this data type "+
        matcher.group(1)+"/**/"+matcher.group(2);
    }

    transformedProgram = transformedProgram.replaceAll("/\\*\\*/","");
    exitTransfStage();
  }

  public static String mapTheProcessingTypeToHaxe(String typeToMap) {
    if (typeToMap.equals("int")) return "Int";
    if (typeToMap.equals("float")) return "Float";
    if (typeToMap.equals("double")) return "Float"; // Haxe's floats are 64 bits so it's OK
    if (typeToMap.equals("boolean")) return "Bool";
    if (typeToMap.equals("short")) return "Int";
    if (typeToMap.equals("color")) return "Int";
    if (typeToMap.equals("void")) return "Void";
    if (typeToMap.equals("Rectangle")) return "ProcessingHaxeIntegerRectangle";

    if (foundReferencesToMinimSoundLibrary) {
      if (typeToMap.equals("Minim")) return "ProcessingHaxeMinim";
      if (typeToMap.equals("AudioSnippet")) return "ProcessingHaxeAudioSnippet";
      if (typeToMap.equals("AudioPlayer")) return "ProcessingHaxeAudioPlayer";
      if (typeToMap.equals("AudioOutput")) return "ProcessingHaxeAudioOutput";
      if (typeToMap.equals("AudioPlayer")) return "ProcessingHaxeAudioPlayer";
    }

    if (foundReferencesToProcessingNetLibrary) {
      if (typeToMap.equals("Client")) return "ProcessingHaxeClient";
    }

    return typeToMap;
  }

  public static void removeVarInsideMethodDeclarations() {
    setPattern("([\\(\\,])\\s*var\\s*");

    enterTransfStage("trnsfrmMultipleDeclarationsInOneLine"); 

    while (performReplaceAndFindNextMatch()) {
      replacement = matcher.group(1) + " ";
    }

    exitTransfStage();
  }

  public static void adjustMethodDeclaration() {
    setPattern("([\\t\\n\\s])"+classesPattern+"\\s+("+identifier+"\\s*\\([^\\)]*\\s*\\))");

    enterTransfStage("trnsfrmMultipleDeclarationsInOneLine"); 

    while (performReplaceAndFindNextMatch()) {
      replacement = matcher.group(1) + "function " + matcher.group(3) + ": " + mapTheProcessingTypeToHaxe(matcher.group(2)) + " ";
    }

    exitTransfStage();
  }

  public static void enterTransfStage(String functionName) {
    println(functionName + " ////////////////");
    found = false;
    matcher = pattern.matcher(transformedProgram);
  }

  public static void exitTransfStage() {
    //println("Transformed:\n" + transformedProgram);
  }

  public static boolean performReplaceAndFindNextMatch() {
    //println("performReplaceAndFindNextMatch");
    if (found)  makeReplacementAndReplaceMatcherInput();

    //println("doing a matcher.find");
    //println("pattern: "+ pattern);
    boolean foundAMatch = matcher.find();
    //println("finished the matcher.find");

    if (foundAMatch) {
      //println("Match found >"+matcher.group()+"< starting at char " +
      //matcher.start()+" and ending at char "+ matcher.end());
    }
    else {
      //println("No match found.");
    }

    replacement = "";
    found = foundAMatch;
    return found;
  }

  public static void makeReplacementAndReplaceMatcherInput() {
    //println("Replacing this with:>"+replacement+"<");
    transformedProgram = matcher.replaceFirst(replacement);
    matcher = pattern.matcher(transformedProgram);
  }

  public static void setPattern(String thePattern) {
    println("setPattern setting pattern: " + thePattern);
    pattern = Pattern.compile(thePattern);
  }

  public static void println(String thingToPrint) {
    System.out.println(thingToPrint);
  }

  public static String createNestedArrayString(int dimension, String type) {
    // if array size is 1 you get var []  = new Array <Int>();
    // if array size is 2 you get var []  = new Array <Array<Int>>();
    // etc.
    String arrayNestingString = "";
    for (int i = 0; i < dimension; i++) arrayNestingString += "Array <";
    arrayNestingString += mapTheProcessingTypeToHaxe(type);
    for (int i = 0; i < dimension; i++) arrayNestingString += ">";

    return arrayNestingString;
  }
}

