# dmenu - dynamic menu

dmenu is an efficient dynamic menu for X.


## Requirements

In order to build dmenu you need the Xlib header files.


## Installation

If you use nix than just use it as any other flake.
Otherwise

```
./patch.sh
cd patched
make clean install
```

## Running dmenu

See the man page for details.

## Added patches

Some of those was modified to fit new version or others:

- caseinsensitive
- nosort
- fuzzymatch
- fuzzyhighlight
- xresources-alt - with improved config that prevents segfaults on too 
  short string buffers
