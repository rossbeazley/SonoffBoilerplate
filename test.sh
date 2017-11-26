#!/bin/bash

PROJ_DIR=`dirname $0`

mkdir $PROJ_DIR/ctestBuild
pushd $PROJ_DIR/ctestBuild
cmake ..
make
CTEST_OUTPUT_ON_FAILURE=1 ctest .
popd
