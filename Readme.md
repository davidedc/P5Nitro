P5Nitro
=======

Overview
--------

P5Nitro lets you create small processing sketches and put them on your phone.

How to use it
----------------
  - You can install P5Nitro in a guest login in both OSX and Linux
  - Open a terminal and run one command, as shown [here](https://github.com/davidedc/P5Nitro/blob/master/Docs/How%20to%20install%20and%20run%20P5Nitro.md).
  - This will create a P5Nitro folder
  - If you are on osx, launch the P5Nitro.app, f you are on linux, launch the P5Nitro script inside the application.linux folder
  - Type a simple Processing program
  - Hit the play button - the sketch should show up on the screen
  - The translated sketch is inside the CompiledSketches folder
  - Open the XCode project with XCode and deploy if you want

It's also possible to make executables that work on windows/linux/osx and flash - manuals for those cases still have to be written.

The bare truth
--------------
**Advantages**

  - works on platforms where using a JVM is impractical (e.g. iOS)

**Disadvantages**

  - processing API and language mimicking is not complete yet

**Working features**

  - basic 2D primitives
  - mouse (one finger) input

**Notable missing features**

  - The editor doesn't support multiple files, selection, loading, saving, and copying. You can paste by using CTRL-V though (also in OSX, which would normally use the command key)
  - 3D primitives
  - multitouch
  - accelerometer
  - gestures

How does it work
----------------
P5Nitro translates your sketches into Haxe source files. The haxe compiler then translates the haxe files into VM bytecode (called Neko) and c++. Your favorite compiler then creates native code.

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