#!/bin/bash

server_binary="r-type_server"
head_server_binary="r-type_head_server"
client_binary="r-type_client"
tests_binary="r-type_tests"
serverModulesDir="serverModules"

clean_server() {
    rm -f $server_binary
    rm -f $serverModulesDir/*
    rm -f server_dev_tools/server/config/unix/*.a
    rm -rf server_dev_tools/$serverModulesDir/gameModule.so server_dev_tools/$serverModulesDir/networkModule.so server_dev_tools/$serverModulesDir/logModule.so
    rm -f server_dev_tools/$server_binary
    rm -f server_dev_tools/source_code/*.cpp
    rm -f server_dev_tools/source_code/*.hpp
}

clean_head_server() {
    rm -f $head_server_binary
}

clean_client() {
    rm -f $client_binary
}

clean_tests() {
    rm -f $tests_binary
}

clean_all() {
    clean_server
    clean_head_server
    clean_client
    clean_tests
}

copy_server_source_code() {
    cp server/modules/MultiThread.* server_dev_tools/source_code
    cp server/modules/AbstractModule.* server_dev_tools/source_code
    cp server/modules/UUID.* server_dev_tools/source_code
}

move_server_and_modules() {
    mv build/server/$server_binary .
    mv build/server/modules/gameModule/*.so .
    mv build/server/modules/networkModule/*.so .
    mv build/server/modules/logModule/*.so .
    mv libgameModule.so gameModule.so
    mv libnetworkModule.so networkModule.so
    mv liblogModule.so logModule.so
    mkdir $serverModulesDir
    mv gameModule.so $serverModulesDir
    mv networkModule.so $serverModulesDir
    mv logModule.so $serverModulesDir
}

setup_dev_tools() {
    mv build/server_dev_tools/source_code/libmoduleSourceCode.a server_dev_tools/server/config/unix
    mv server_dev_tools/server/config/unix/libmoduleSourceCode.a server_dev_tools/server/config/unix/moduleSourceCode.a
    mkdir server_dev_tools/$serverModulesDir
    cp $serverModulesDir/*.so server_dev_tools/$serverModulesDir
    cp $server_binary server_dev_tools
    chmod 444 server_dev_tools/$serverModulesDir/*.so
}

compile_server() {
    clean_server
    copy_server_source_code
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=OFF -DHEAD_SERVER=OFF
    cd build
    make
    cd ..
    move_server_and_modules
    setup_dev_tools
}

compiler_head_server() {
    clean_head_server
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=OFF -DHEAD_SERVER=ON
    cd build
    make
    cd ..
    mv build/HeadServer/$head_server_binary .
}

compile_client() {
    clean_client
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=ON -DHEAD_SERVER=OFF
    cd build
    make
    cd ..
    mv build/client/$client_binary .
}

compile_tests () {
    clean_all
    cmake -S . -B build -DTESTS=ON -DSERVER=ON -DCLIENT=ON -DHEAD_SERVER=ON
    cd build
    make
    cd ..
    sudo ./build/tests/$tests_binary
}

compile() {
    clean_client
    clean_server
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=ON -DHEAD_SERVER=ON
    cd build
    make
    cd ..
    mv build/server/$server_binary .
    mv build/client/$client_binary .
}

rm -rf build
if [ "$1" == "clean" ]; then
    clean_all
elif [ "$1" == "tests" ]; then
    compile_tests
elif [ "$1" == "server" ]; then
    compile_server
elif [ "$1" == "HeadServer" ]; then
    compiler_head_server
elif [ "$1" == "client" ]; then
    compile_client
else
    compile
fi