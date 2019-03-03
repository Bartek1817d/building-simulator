#!/bin/bash

. ./configuration.sh
. ./functions.sh

PROGRAM=$1
ssh_wrapper $TARGET_BIN_DIR/$PROGRAM

