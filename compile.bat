@echo off
cls

REM set vars
set CPP_COMPILER=g++.exe

REM create build directory
echo creating compilation environement...
mkdir build

REM Build
echo compiling...
g++ *.cpp -o build/out.exe || goto error
echo program successfully compiled, executing now...

REM execute program
echo --------------------------------------------
call "build\out.exe" || goto error
goto end

:error
cd ..

:end
echo --------------------------------------------
echo program ended.
pause