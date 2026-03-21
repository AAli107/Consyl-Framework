@echo off
setlocal enabledelayedexpansion

set "BUILD_FOLDER=build"
set "OBJECT_FOLDER=obj"
set "SRC_FOLDER=src"
set "EXE_OUTPUT_FILE=program.exe"

for /f %%a in ('echo prompt $E^| cmd') do set "ESC=%%a"
set "CLR=!ESC![2K!ESC![1G"

if exist "%BUILD_FOLDER%" (
    rmdir /s /q "%BUILD_FOLDER%"
)

mkdir "%BUILD_FOLDER%"
mkdir "%BUILD_FOLDER%\%OBJECT_FOLDER%"

set "CPP_FILES="
set /a TOTAL=0
for /r "%SRC_FOLDER%" %%f in (*.cpp) do (
    set "CPP_FILES=!CPP_FILES!%%f;"
    set /a TOTAL+=1
)

set /a CURRENT=0
set "OBJ_FILES="
for /r "%SRC_FOLDER%" %%f in (*.cpp) do (
    set /a CURRENT+=1
    <nul set /p "=!CLR![!CURRENT!/%TOTAL%] Compiling file: %%~nxf"
    if !CURRENT! == %TOTAL% (
        echo(
    )
    g++ -std=c++20 -O3 -c "%%f" -o "%BUILD_FOLDER%\%OBJECT_FOLDER%\%%~nf.o"
    if errorlevel 1 (
        echo Failed to compile "%%~nxf"
        del /q "%BUILD_FOLDER%\%OBJECT_FOLDER%\*.o"
        exit /b 1
    )
    set "OBJ_FILES=!OBJ_FILES! "%BUILD_FOLDER%\%OBJECT_FOLDER%\%%~nf.o""
)

echo [Linking] %EXE_OUTPUT_FILE%...
g++ -std=c++20 -O3 !OBJ_FILES! -o "%BUILD_FOLDER%\%EXE_OUTPUT_FILE%"

if exist "%BUILD_FOLDER%\%EXE_OUTPUT_FILE%" (
    echo Build successful. Running...
    start "" "%BUILD_FOLDER%\%EXE_OUTPUT_FILE%"
) else (
    echo Build failed.
)

del /q "%BUILD_FOLDER%\%OBJECT_FOLDER%\*.o"