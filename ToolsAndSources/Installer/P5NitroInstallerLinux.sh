# the linux version replaces curl with wget and also adds a LD_LIBRARY_PATH environment variable
wget -O P5NitroCheckout.zip https://github.com/davidedc/P5Nitro/zipball/master
unzip P5NitroCheckout.zip
rm P5NitroCheckout.zip
mv davidedc-P5Nitro-* P5Nitro

which haxelib > testToSeeIfHaxelibIsInstalled.txt

if [ -s testToSeeIfHaxelibIsInstalled.txt ]
  then
    echo "haxelib is already installed"
  else
    echo "haxelib has not been installed"
    mkdir $PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib
    wget -O neko.tgz http://nekovm.org/_media/neko-1.8.1-linux.tar.gz
    wget -O haxe.tgz http://haxe.org/file/haxe-2.07-linux.tar.gz
    #curl http://processing.googlecode.com/files/processing-1.5.1-linux.zip > processing.zip
    tar -zxvf neko.tgz -C $PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    tar -zxvf haxe.tgz -C $PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    #unzip processing.zip
    rm haxe.tgz neko.tgz
    export HAXEPATH=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-linux/
    export NEKOPATH=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-linux/
    export PATH=$HAXEPATH:$NEKOPATH:$PATH
    export DYLD_LIBRARY_PATH=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/neko-1.8.1-linux/
    export LD_LIBRARY_PATH=$DYLD_LIBRARY_PATH # this is linux-specific
    haxelib setup $PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/
    haxelib install hxcpp
    haxelib install nme
    export HXCPP=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/
    export HAXE_LIBRARY_PATH=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/haxe-2.07-linux/std/
    export LD_LIBRARY_PATH=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/hxcpp/2,07,0/bin/Mac/
    export LD_LIBRARY_PATH=$PWD/P5Nitro/ToolsAndSources/HaxeNekoAndHaxelib/nme/2,0,1/ndll/Mac/:$LD_LIBRARY_PATH
fi

rm testToSeeIfHaxelibIsInstalled.txt
echo Installation complete.