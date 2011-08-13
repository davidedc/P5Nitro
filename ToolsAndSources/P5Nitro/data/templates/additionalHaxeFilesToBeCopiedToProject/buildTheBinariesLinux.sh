#!/bin/bash

which haxelib > testToSeeIfHaxelibIsInstalled.txt

if [ -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib is already installed"
    export DYLD_LIBRARY_PATH=:/usr/lib/haxe/lib/hxcpp/2,07,0/bin/Linux:/usr/lib/haxe/lib/nme/2,0,1/ndll/Linux:.
    export NEKO_INSTALL_PATH=/usr/lib/neko
  else
	echo "haxelib has been installed as portable"
    export HAXEPATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-linux/
    export NEKOPATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-linux/
    export PATH=$HAXEPATH:$NEKOPATH:$PATH
    export DYLD_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-linux/
    export HXCPP=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/
    export HAXE_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-linux/std/
    export LD_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/2,07,0/bin/Linux/
    export LD_LIBRARY_PATH=$PWD/../../../ToolsAndSources/HaxeNekoAndHaxelib/nme/2,0,1/ndll/Linux/:$LD_LIBRARY_PATH
fi

which gcc > testToSeeIfGccIsInstalled.txt
if [ -s testToSeeIfGccIsInstalled.txt ]
  then
	echo "gcc is installed"
	haxelib run nme build P5NitroSketch.nmml cpp
  else
	echo "gcc is not installed"
	haxe -main Main -neko P5NitroSketch.n -lib nme -lib hxcpp --remap flash:nme
fi
