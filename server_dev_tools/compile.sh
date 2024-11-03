# You can edit this script to be more specific to your project

# This script is used to compile the server modules

# remove every .so in serverModules exept the gameModule.so and networkModule.so
if [ "$1" = "build" ]; then
    rm -rf build
    ls serverModules | grep -v gameModule.so | grep -v networkModule.so | xargs -I {} rm serverModules/{}
    cmake -S . -B build
    cd build
    make
    cd ..

    #you can add more modules here
    #mv build/modules/subdirectory/lib + you_module_name.so serverModules
    #in this case their is no subdirectory
    #in this case the module name is ModuleTemplate
    #mv serverModules/lib + you_module_name.so serverModules/your_module_name.so

    mv build/modules/template/libModuleTemplate.so serverModules
    mv serverModules/libModuleTemplate.so serverModules/ModuleTemplate.so
    mv build/modules/adminPanelModule/libAdminPanelModule.so serverModules
    mv serverModules/libAdminPanelModule.so serverModules/AdminPanelModule.so
else if [ "$1" = "clean" ]; then
    rm -rf build
    ls serverModules | grep -v gameModule.so | grep -v networkModule.so | xargs -I {} rm serverModules/{}
else
    echo "Usage: ./compile.sh [build|clean]"
fi
fi