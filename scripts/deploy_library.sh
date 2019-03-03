#!/bin/bash

. ./configuration.sh
. ./functions.sh

LIBRARY=$1
deploy $LIBRARY $TARGET_LIB_DIR/$LIBRARY

