#!/bin/bash

PROJ_DIR=`dirname $0`

mkdir $PROJ_DIR/build
pushd $PROJ_DIR/build
cmake ..
make
CTEST_OUTPUT_ON_FAILURE=1 ctest .
popd
