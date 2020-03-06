#!/bin/sh
# master; afl -i [input-dir] -o [output-dir] -Q -M [master-name] -- target..
../../afl-2.52b/afl-fuzz -i i -o o -Q -M afl-master -- ./example3
# slave; afl -i [input-dir] -o [output-dir] -Q -S [slave-name] -- target..
../../afl-2.52b/afl-fuzz -i i -o o -Q -S afl-slave -- ./example3
