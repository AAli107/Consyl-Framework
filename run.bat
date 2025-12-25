@echo off
setlocal enabledelayedexpansion

set "BUILD_FOLDER=build"
set "SRC_FOLDER=src"
set "EXE_OUTPUT_FILE=program.exe"

if exist "%BUILD_FOLDER%" (
    rmdir /s /q "%BUILD_FOLDER%"
)

mkdir "%BUILD_FOLDER%"

set "CPP_FILES="
for /r "%SRC_FOLDER%" %%f in (*.cpp) do (
    set "CPP_FILES=!CPP_FILES! "%%f""
)

g++ -O3 !CPP_FILES! -o "%BUILD_FOLDER%\%EXE_OUTPUT_FILE%"

if exist "%BUILD_FOLDER%\%EXE_OUTPUT_FILE%" (
    start "" "%BUILD_FOLDER%\%EXE_OUTPUT_FILE%"
)