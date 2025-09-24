#!/usr/bin/env sh

set -e pipefail

SCRIPT_DIR="$(readlink -f "$0")"
SCRIPT_DIR="${SCRIPT_DIR%/*}"
PATCH_DIR="$SCRIPT_DIR/patches"
SRC="$SCRIPT_DIR/src"
PATCHED="$SCRIPT_DIR/patched"

mkdir -p "$PATCHED"
rm -fr "${PATCHED:?}"/*
cp -r "$SRC"/* "$PATCHED"
cd "$PATCHED"

for patch in \
    dmenu-caseinsensitive-20200523-db6093f.diff \
    dmenu-nosort-5.0.diff \
    dmenu-fuzzymatch-5.3.diff \
    dmenu-fuzzyhighlight-5.3.diff \
    dmenu-xresources-alt-5.0.diff \

    # dmenu-nonblockingstdincontrol-4.9.diff \

do
    echo "Applying $patch"
    patch -p1 <"$PATCH_DIR/$patch"
done

cp "$SCRIPT_DIR/config.h" "$PATCHED"
if [ "$(uname)" = "FreeBSD" ]; then
    cp "$SCRIPT_DIR/config.freebsd.mk" "$PATCHED/config.mk"
fi
