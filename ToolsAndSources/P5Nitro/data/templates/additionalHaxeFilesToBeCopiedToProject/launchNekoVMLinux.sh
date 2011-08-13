#!/bin/bash

which haxelib > testToSeeIfHaxelibIsInstalled.txt

if [ -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib is already installed"
    export DYLD_LIBRARY_PATH=:/usr/lib/haxe/lib/hxcpp/2,07,0/bin/Linux:/usr/lib/haxe/lib/nme/2,0,1/ndll/Linux:.
    export NEKO_INSTALL_PATH=/usr/lib/neko
    export PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/git/bin:/usr/X11/bin
  else
    echo "haxelib has been installed as portable"
    export HAXEPATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-linux/
    export NEKOPATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-linux/
    export PATH=$HAXEPATH:$NEKOPATH:$PATH
    export DYLD_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-linux/
    export HXCPP=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/
    export HAXE_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-linux/std/
    export LD_LIBRARY_PATH=$DYLD_LIBRARY_PATH # this is linux-specific
    export LD_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/2,07,0/bin/Linux/:$LD_LIBRARY_PATH
    export LD_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/nme/2,0,1/ndll/Linux/:$LD_LIBRARY_PATH
fi

neko P5NitroSketch.n
