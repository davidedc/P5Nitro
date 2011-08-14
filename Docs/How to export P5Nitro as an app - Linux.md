How to export P5Nitro as a standalone application (Linux)
===================================

In theory P5Nitro should work also for people who don't have Processing, so this is why P5Nitro also comes as a standalone application rather than just as a sketch.

The "Export Application" feature of Processing needs to be adapted a bit
though.

So here is how to do it.

* In the sketch, in P5Nitro.pde, uncomment the main method. Note that P5Nitro changes the relative positions of the input/output folders when it's ran as an application, because it's ran in a different point in the directory structure.
* In processing, use "Export Application"
* Check the Linux version
* Ok now you should have an app in a place like:

      /P5Nitro/ToolsAndSources/P5Nitro/application.linux/
* Copy that folder and put it inside the top P5Nitro folder
* Inside that folder there is a P5Nitro file, which is just a shell script: change the reference to "java" into "../ToolsAndSources/processing-1.5.1/java/bin/java"
* Create a place to hold the data foldes in:

      /P5Nitro/application.linux/Contents/Resources
* Copy in here the "data" directory of the P5Nitro sketch
* Inside the data directory, change the permissions of the file "killProcessByName" to 777
* Go to:

      /P5Nitro/application.linux/lib/

* This directory should contain two jar files. Rename P5Nitro.jar to P5Nitro.zip
and unpack it in place (you can double-click it in Finder)
* in the unpacked folder, (which should be named P5Nitro), delete all the contents of the data folder apart from the font file
* Now with the terminal go to:

      whereverYouPutP5Nitro/P5Nitro/application.linux/lib/P5Nitro

* Make the jar anew:

      jar -cvf ../P5Nitro.jar *
* Now you can delete the P5Nitro directory:

      /P5Nitro/application.linux/lib/P5Nitro

* And also delete the .zip file:

      /P5Nitro/application.linux/lib/P5Nitro.zip
