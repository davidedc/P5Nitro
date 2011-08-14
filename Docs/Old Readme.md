P5Nitro - old readme file
=========================

Why is this old readme file here?
---------------------------------
P5Nitro's features have been shrunk in order to make it a bit more fun. Those features will make it back in the project one day, so hopefully this file will be useful again.


Overview
--------

P5Nitro turns your processing sketches into native code.

How to use it
----------------
For using P5Nitro, three things are needed: Processing, Haxe and the nekonme library. For deploying on iOS, XCode is also needed. The general workflow looks as follows:

  - Make a sketch using Processing. Some examples are in P5Nitro / data / inputFilesForTranslatorFolder
  - When done, put the sketch in P5Nitro / data / inputFilesForTranslatorFolder
  - Open P5Nitro.pde in Processing and tweak the paragraph that selects which sketch to translate
  - Hit the play button
  - The translated sketch and ready-made XCode project are now in the data folder of the sketch
  - Open the XCode project with XCode and deploy

It's also possible to make executables that work on windows/linux/osx and flash - manuals for those cases still have to be written.

The bare truth
--------------
**Advantages**

  - faster than Java
  - works on platforms where using a JVM is impractical (e.g. iOS)

**Disadvantages**

  - processing API and language mimicking is not complete yet

**Working features**

  - sound and music via Minim
  - text (via custom API)
  - network (some)
  - basic 2D primitives
  - loading and writing files (some)
  - mouse (one finger) input

**Missing features**

  - 3D primitives
  - multitouch
  - accelerometer
  - gestures

How does it work
----------------
P5Nitro translates your sketches into Haxe source files. The haxe compiler then translates the haxe files into c++. Your favorite compiler then creates native code.

Current state of affairs
------------------------
P5Nitro is in its infancy. It needs TLC and forgiveness. It won't understand you all the times, so please be patient. Feel free to feed the project with suggestions or code submissions. That said, there are four apps in the App Store that have been coded in processing and used P5Nitro, and more are coming.

Keep in touch
-------------
P5Nitro contributors are on the haxe mailing list.

Related projects
----------------

**iProcessing** by Tom Hulbert at Luckybytes is a perfectly working implementation of Processing for iOS devices. It works by translating Processing to Javascript using processing.js, and using the Titanium implementation of the Canvas element. It's a solid implementation with support for multitouch, accelerometer, gestures. The indirect layer of javascript interpretation and canvas implementation penalize performance in respect to a native c++ / opengl solution.

**hxOpenFrameworks** by Andy Li is a binding of the OpenFrameworks API for Haxe. It allows you to use Haxe (a clean garbage-collected language similar to javascript/actionscript) to use the great opengl-accelerated OpenFrameworks API.

**OpenFrameworks and Cinder** are great and work on iOS devices. If you like C++ and don't mind doing memory management manually, then these are perfectly good solutions for creative coding done natively.

**Processing.js** is a good solution that works on any device/platform with a browser supporting the canvas element. Performance on low-power devices is somewhat limited, but it's a broad implementation of the Processing language and API

Where credit is due
-------------------
P5Nitro wishes to thank:

  - the **Haxe** community started by **Nicolas Cannasse**
  - the **hxcpp** and **nekonme** projects by **Hugh Sanderson**
  - the mapping of the processing API into flash API first made by **Tim Cameron Ryan**
  - **Nutsu**'s **Frocessing** is another implementation of the processing API using flash and it's been of inspiration
  - Sophie McDonald for the encouragement and willingness to be the first user
  - Tom Hulbert and Durrel Bishop from Luckybytes, Evan Raskob for the encouragement

Obviously a big thanks goes to the Haxe and Processing founders and community at large.