#!/bin/bash

. ./configuration.sh

sshfs -oIdentityFile=$HOST_PRIVATE_KEY $TARGET_USER_NAME@$TARGET_IP:$TARGET_HOME_DIR $HOST_MOUNT_POINT
