#!/bin/bash

PROJ_DIR=`dirname $0`

mkdir $PROJ_DIR/build
pushd $PROJ_DIR/build
cmake ..
make
ctest .
popd
