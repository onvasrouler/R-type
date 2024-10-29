rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
mv Rtype ../.
cd ..
mv src/raygui/raygui.h src/raygui/raygui.c
./Rtype
