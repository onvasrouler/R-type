@echo off

echo 0 > progress.txt
REM Simulate some installation steps

timeout /t 2
echo 20 > progress.txt

timeout /t 2
echo 40 > progress.txt

timeout /t 2
echo 60 > progress.txt

timeout /t 2
echo 80 > progress.txt

timeout /t 2
echo 100 > progress.txt
