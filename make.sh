#!/bin/bash
echo `flex morriscript.l`
echo flex DONE!
echo `bison -d -v morriscript.y`
echo bison DONE!
echo `gcc morriscript.tab.c tree.c create.c string.c main.c -std=c89 -o ms`
echo gcc DONE!