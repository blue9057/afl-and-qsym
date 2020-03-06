# Assessing Security Vulnerabilities Automatically with AFL assisted by QSYM

## Prerequisite

Please install [Docker](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04), [git lfs](https://git-lfs.github.com/).

Also please make your system ready for building QEMU and AFL
(flex, bison, yacc, build-essential, etc.).


## Installation

### Download qsym-docker.tar.bz2

~~~{.sh}
# download the file via git lfs
$ git lfs pull
Git LFS: (0 of 2 files) 0 B / 599.55 MB
...
Git LFS: (2 of 2 files) 599.55 MB / 599.55 MB

# load image
$ ./load-image.sh
9e6f810a2aab: Loading layer [==================================================>]    128MB/128MB
0040d8f00d7e: Loading layer [==================================================>]  11.78kB/11.78kB
aa6685385151: Loading layer [==================================================>]  15.87kB/15.87kB
4ae3adcb66cb: Loading layer [==================================================>]  3.072kB/3.072kB
074deb42cadd: Loading layer [==================================================>]  25.91MB/25.91MB
7889842018e0: Loading layer [==================================================>]  237.2MB/237.2MB
5718c8c27a7b: Loading layer [==================================================>]   2.56kB/2.56kB
272578abc3b5: Loading layer [==================================================>]  228.7MB/228.7MB
260bec79d78e: Loading layer [==================================================>]  580.2MB/580.2MB
c7ec00209c82: Loading layer [==================================================>]  268.4MB/268.4MB
190d8021e383: Loading layer [==================================================>]  596.5MB/596.5MB
4f9bff0ad785: Loading layer [==================================================>]  311.6MB/311.6MB
Loaded image: qsym:latest

# check image
$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
qsym                latest              86b5c1972d61        2 days ago          2.34GB

~~~


### Build afl-fuzz

~~~{.sh}
# run command
$ ./build-afl.sh

# this will build both afl and qemu mode
[+] Build process successful!
[*] Copying binary...
-rwxrwxr-x 1 blue9057 blue9057 10982736 Mar  5 17:56 ../afl-qemu-trace
[+] Successfully created '../afl-qemu-trace'.
[*] Testing the build...
[+] Instrumentation tests passed.
[+] All set, you can now use the -Q mode in afl-fuzz!
~/afl-and-qsym/afl-2.52b ~/afl-and-qsym
~/afl-and-qsym
~~~


## Running AFL with QSYM on example3

### Setup the example
~~~{.sh}
# build example3
$ cd example/example3
$ make
gcc -fno-stack-protector -o example3 example3.c
# create output directory
$ mkdir o
~~~

### Run afl-master
~~~{.sh}
# run afl-master
$ ../../afl-2.52b/afl-fuzz -i i -o o -Q -M afl-master -- ./example3
~~~

### Run afl-slave
~~~{.sh}
# run afl-slave
$ ../../afl-2.52b/afl-fuzz -i i -o o -Q -S afl-slave -- ./example3
~~~

### Run QSYM
~~~{.sh}
# in the root of the repository
# run qsym in docker
$ ./run-qsym-in-docker.sh
# running in a docker image qsym:latest
# get into the example3 directory
root@8b317cc37ad9:/workdir/qsym# cd /shared/example/example3/
# run qsym
root@8b317cc37ad9:/shared/example/example3# /workdir/qsym/bin/run_qsym_afl.py -o o -a afl-slave -n qsym -- ./example3
~~~


