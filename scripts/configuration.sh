#!/bin/bash

export HOST_SSH_DIR=~/.ssh
export HOST_PRIVATE_KEY=$SSH_DIR/id_rsa
export HOST_MOUNT_POINT=/mnt/qnx

export TARGET_USER_NAME=bartek
export TARGET_IP=172.16.126.129
export TARGET_HOME_DIR=/home/$TARGET_USER_NAME
export TARGET_LIB_DIR=lib
export TARGET_BIN_DIR=bin

