P5Nitro
=======

Overview
--------

P5Nitro turns your processing sketches into native code.

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
  - mouse (or finger) input

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

Related projects
----------------

**iProcessing** by Tom Hulbert at Luckybytes is a perfectly working implementation of Processing for iOS devices. It works by translating Processing to Javascript using processing.js, and using the Titanium implementation of the Canvas element. It's a solid implementation with support for multitouch, accelerometer, gestures. The indirect layer of javascript interpretation and canvas implementation penalize performance in respect to a native c++ / opengl solution.

**hxOpenFrameworks** by Andy Li is a binding of the OpenFrameworks API for Haxe. It allows you to use Haxe (a clean garbage-collected language similar to javascript/actionscript) to use the great opengl-accelerated OpenFrameworks API.

**OpenFrameworks and Cinder** are great and work on iOS devices. If you like C++ and don't mind doing memory management manually, then this is a great and fast solution for creative coding done natively.

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