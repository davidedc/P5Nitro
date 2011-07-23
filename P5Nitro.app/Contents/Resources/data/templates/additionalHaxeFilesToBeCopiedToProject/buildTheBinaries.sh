#!/bin/bash
export DYLD_LIBRARY_PATH=:/usr/lib/haxe/lib/hxcpp/2,07,0/bin/Mac:/usr/lib/haxe/lib/nme/2,0,1/ndll/Mac:.
export HOME=/Users/davidedellacasa
export LOGNAME=davidedellacasa
export NEKO_INSTALL_PATH=/usr/lib/neko
export PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/git/bin:/usr/X11/bin

haxelib run nme build P5NitroSketch.nmml cpp
