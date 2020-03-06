#!/bin/sh
# running qsym in the docker image for example3, assisting afl-slave via
# output directory [o]
# [qsym-cmd] -a [afl-slave-name] -o [output-dir] -n [name] -- target command...
/workdir/qsym/bin/run_qsym_afl.py -a afl-slave -o o -n qsym -- ./example3
