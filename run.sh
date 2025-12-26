#!/usr/bin/env bash

set -euo pipefail

BUILD_FOLDER="build"
SRC_FOLDER="src"

rm -rf "$BUILD_FOLDER"
mkdir -p "$BUILD_FOLDER"

CPP_ARRAY=()
while IFS= read -r -d $'\0' file; do
    CPP_ARRAY+=("$file")
done < <(find "$SRC_FOLDER" -name "*.cpp" -print0)
if [ "${#CPP_ARRAY[@]}" -eq 0 ]; then
    echo "No .cpp files found in $SRC_FOLDER" >&2
    exit 1
fi

LDFLAGS=()
OUTPUT_NAME="program"
UNAME_S=$(uname -s)
if [ "$UNAME_S" = "Darwin" ]; then
    # MacOS; use app services(CGEventSourceKeyState) & Carbon for keycodes
    LDFLAGS+=("-framework" "ApplicationServices" "-framework" "Carbon")
elif [ "$UNAME_S" = "Linux" ]; then
    # Linux; link X11 (for future endeavours :p)
    LDFLAGS+=("-lX11")
fi

echo "Building for: $UNAME_S"
echo "Source files: ${#CPP_ARRAY[@]}"

### BUILD;
g++ -O3 "${CPP_ARRAY[@]}" -o "$BUILD_FOLDER/$OUTPUT_NAME" "${LDFLAGS[@]}"

if [ -x "$BUILD_FOLDER/$OUTPUT_NAME" ]; then
    echo "Running $BUILD_FOLDER/$OUTPUT_NAME"
    "./$BUILD_FOLDER/$OUTPUT_NAME"
else
    echo "Build produced no executable at $BUILD_FOLDER/$OUTPUT_NAME" >&2
    exit 1
fi
