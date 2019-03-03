#!/bin/bash

. ./configuration.sh
. ./functions.sh

PROGRAM=$1
deploy $PROGRAM $TARGET_BIN_DIR/$PROGRAM
scp_wrapper $TARGET_BIN_DIR/$PROGRAM

