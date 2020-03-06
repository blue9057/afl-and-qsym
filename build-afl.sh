#!/bin/bash
pushd afl-2.52b
make
pushd qemu_mode
./build_qemu_support.sh
popd
popd
