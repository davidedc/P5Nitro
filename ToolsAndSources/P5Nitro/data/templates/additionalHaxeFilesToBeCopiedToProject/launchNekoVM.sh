#!/bin/bash

haxelib > testToSeeIfHaxelibIsInstalled.txt

if [ -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib is already installed"
    export DYLD_LIBRARY_PATH=:/usr/lib/haxe/lib/hxcpp/2,07,0/bin/Mac:/usr/lib/haxe/lib/nme/2,0,1/ndll/Mac:.
    export HOME=/Users/davidedellacasa
    export LOGNAME=davidedellacasa
    export NEKO_INSTALL_PATH=/usr/lib/neko
    export PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/git/bin:/usr/X11/bin
fi    
    

if [ ! -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib has been installed as portable"
    export HAXEPATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-osx/
    export NEKOPATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-osx/
    export PATH=$HAXEPATH:$NEKOPATH:$PATH
    export DYLD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-osx/
    #haxelib setup $HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    #haxelib install hxcpp
    #haxelib install nme
    export HXCPP=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/
    export HAXE_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-osx/std/
    export LD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/2,07,0/bin/Mac/
    export LD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/nme/2,0,1/ndll/Mac/:$LD_LIBRARY_PATH
fi

neko P5NitroSketch.n
