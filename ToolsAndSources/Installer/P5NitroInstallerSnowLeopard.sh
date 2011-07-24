cd ~/Downloads
curl -L https://github.com/davidedc/P5Nitro/zipball/master > P5NitroCheckout.zip
unzip P5NitroCheckout.zip
mv davidedc-P5Nitro-* P5Nitro

haxelib > testToSeeIfHaxelibIsInstalled.txt

if [ -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib is already installed"
fi

if [ ! -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib has not been installed"
    curl http://nekovm.org/_media/neko-1.8.1-osx.tar.gz > neko.tgz
    curl http://haxe.org/file/haxe-2.07-osx.tar.gz > haxe.tgz
    #curl http://processing.googlecode.com/files/processing-1.5.1-macosx.zip > processing.zip
    tar -zxvf neko.tgz $HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    tar -zxvf haxe.tgz $HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    #unzip processing.zip
    rm haxe.tgz neko.tgz
    export HAXEPATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-osx/
    export NEKOPATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-osx/
    export PATH=$HAXEPATH:$NEKOPATH:$PATH
    export DYLD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-osx/
    haxelib setup $HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    haxelib install hxcpp
    haxelib install nme
    export HXCPP=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/
    export HAXE_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-osx/std/
    export LD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/2,07,0/bin/Mac/
    export LD_LIBRARY_PATH=$HOME/Downloads/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/nme/2,0,1/ndll/Mac/:$LD_LIBRARY_PATH
fi