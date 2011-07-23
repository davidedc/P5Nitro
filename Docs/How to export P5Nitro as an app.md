How to export P5Nitro as a standalone application (OSX)
===================================

In theory P5Nitro should work also for people who don't have Processing, so this is why P5Nitro also comes as a standalone application rather than just as a sketch.

The "Export Application" feature of Processing needs to be adapted a bit
though.

So here is how to do it.

* In the sketch, in P5Nitro.pde, uncomment the main method. Note that P5Nitro changes the relative positions of the input/output folders when it's ran as an application, because it's ran in a different point in the directory structure.
* In processing, use "Export Application"
* Check the Mac version
* Ok now you should have an app in a place like:
~~~
      /P5Nitro/ToolsAndSources/P5Nitro/application.macosx/
~~~
* Copy the .app from that folder and put it inside the top P5Nitro folder
* so now the app should be in:
~~~
      /P5Nitro/P5Nitro.app
~~~
* now use the "Show package content" feature from the finder and dig
into the inside of the app. Go into:
~~~
      /P5Nitro/P5Nitro.app/Contents/Resources/
~~~
* Copy in here the "data" directory of the P5Nitro sketch
* Go to:
~~~
      /P5Nitro/P5Nitro.app/Contents/Resources/Java/
~~~
This directory should contain two jar files. Rename P5Nitro.jar to P5Nitro.zip
and unpack it in place (you can double-click it in Finder)
* in the unpacked folder, (which should be named P5Nitro), delete the data folder
* Now with the terminal go to:
~~~
      whereverYouPutP5Nitro/P5Nitro/P5Nitro.app/Contents/Resources/Java/P5Nitro
~~~
and make the jar anew:
~~~
      jar -cvf ../P5Nitro.jar *
~~~
* Now you can delete the P5Nitro directory:
~~~
      /P5Nitro/P5Nitro.app/Contents/Resources/Java/P5Nitro
~~~
and the .zip file:
~~~
      /P5Nitro/P5Nitro.app/Contents/Resources/Java/P5Nitro.zip
~~~