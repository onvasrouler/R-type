#!/bin/bash

rm -rf build
rm -rf serverModules
rm -f r-type_server
rm -f r-type_client
rm -f r-type_tests
if [ "$1" == "clean" ]; then
    rm -rf build
    rm -rf serverModules
    rm -f r-type_server
    rm -f r-type_client
    rm -f r-type_tests
    rm -rf server_dev_tools/serverModules
    rm -f server_dev_tools/r-type_server
    rm -f server_dev_tools/server/config/unix/*.a
else if [ "$1" == "tests" ]; then
    cmake -S . -B build -DTESTS=ON
    cd build
    make
    cd ..
    sudo ./build/tests/r-type_tests
else if [ "$1" == "server" ]; then
    rm -f serverModules/*
    rm -f server_dev_tools/server/config/unix/*.a
    rm -rf server_dev_tools/serverModules/gameModule.so server_dev_tools/serverModules/networkModule.so server_dev_tools/serverModules/logModule.so
    rm -f server_dev_tools/r-type_server
    rm -f server_dev_tools/source_code/*.cpp
    rm -f server_dev_tools/source_code/*.hpp
    cp server/modules/MultiThread.* server_dev_tools/source_code
    cp server/modules/AbstractModule.* server_dev_tools/source_code
    cp server/modules/UUID.* server_dev_tools/source_code
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=OFF
    cd build
    make
    cd ..
    mv build/server/r-type_server .
    mv build/server/modules/gameModule/*.so .
    mv build/server/modules/networkModule/*.so .
    mv build/server/modules/logModule/*.so .
    mv libgameModule.so gameModule.so
    mv libnetworkModule.so networkModule.so
    mv liblogModule.so logModule.so
    mv build/server_dev_tools/source_code/libmoduleSourceCode.a server_dev_tools/server/config/unix
    mv server_dev_tools/server/config/unix/libmoduleSourceCode.a server_dev_tools/server/config/unix/moduleSourceCode.a
    mkdir serverModules
    mv gameModule.so serverModules
    mv networkModule.so serverModules
    mv logModule.so serverModules
    mkdir server_dev_tools/serverModules
    cp serverModules/*.so server_dev_tools/serverModules
    cp r-type_server server_dev_tools
    chmod 444 server_dev_tools/serverModules/*.so
else if [ "$1" == "client" ]; then
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=ON
    cd build
    make
    cd ..
    mv build/client/r-type_client .
else
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=ON
    cd build
    make
    cd ..
    mv build/server/r-type_server .
    mv build/client/r-type_client .
fi
fi
fi
fi