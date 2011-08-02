#!/bin/bash

which haxelib > testToSeeIfHaxelibIsInstalled.txt

if [ -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib is already installed"
    export DYLD_LIBRARY_PATH=:/usr/lib/haxe/lib/hxcpp/2,07,0/bin/Mac:/usr/lib/haxe/lib/nme/2,0,1/ndll/Mac:.
    export NEKO_INSTALL_PATH=/usr/lib/neko
  else
	echo "haxelib has been installed as portable"
    export HAXEPATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-osx/
    export NEKOPATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-osx/
    export PATH=$HAXEPATH:$NEKOPATH:$PATH
    export DYLD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-osx/
    export HXCPP=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/
    export HAXE_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-osx/std/
    export LD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/2,07,0/bin/Mac/
    export LD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/nme/2,0,1/ndll/Mac/:$LD_LIBRARY_PATH
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
