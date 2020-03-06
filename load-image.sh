#!/bin/sh
bunzip2 -d -c ./docker-image/qsym-docker.tar.bz2 | docker load
