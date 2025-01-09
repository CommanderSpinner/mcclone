#!/bin/sh
cd ..
cd build
pwd

#release build
cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" .. 
ninja
mv mcclone mcclone-release

#debug build
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeLite" .. 
ninja
#mv mcclone mcclone-debug

chmod +x mcclone
./mcclone

ls
