How to export P5Nitro as an app
===============================

In theory P5Nitro should work also for people who don't have Processing.
So this is why P5Nitro also comes with binaries rather than just as a sketch.

The "Export Application" feature of Processing needs to be adapted a bit
though.

So here is how to do it.

1) In the sketch, in P5Nitro.pde, uncomment the main method
2) In processing, use "Export Application"
3) Check the Mac version
4) Ok now you should have an app in a place like:
/P5Nitro/ToolsAndSources/P5Nitro/application.macosx/
5) Copy the .app from that folder and put it inside the top P5Nitro folder
6) so now the app should be in:
/P5Nitro/P5Nitro.app
7) now use the "Show package content" feature from the finder and dig
into the inside of the app. Go into
/P5Nitro/P5Nitro.app/Contents/Resources/
8) Copy in here the "data" directory of the P5Nitro sketch
9) Go to
/P5Nitro/P5Nitro.app/Contents/Resources/Java/
This directory should contain two jar files. Rename P5Nitro.jar to P5Nitro.zip
and unpack it in place (you can double-click it in Finder)
10) in the unpacked folder, (which should be named P5Nitro), delete the data folder
11) Now with the terminal go to
whereverYouPutP5Nitro/P5Nitro/P5Nitro.app/Contents/Resources/Java/P5Nitro
and make the jar anew:
jar -cvf ../P5Nitro.jar *
12) Now you can delete the P5Nitro directory:
/P5Nitro/P5Nitro.app/Contents/Resources/Java/P5Nitro
and the .zip file
/P5Nitro/P5Nitro.app/Contents/Resources/Java/P5Nitro.zip
