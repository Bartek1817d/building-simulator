#!/bin/bash

. ./configuration.sh

deploy_file()
{
	SRC_FILE=$1
	DST_DIR=${2:-~/}
	sshpass -p $PASSWORD scp $SRC_FILE ${USER_NAME}@${VM_IP}:${DST_DIR}
}

execute_vm_program()
{
	VM_PROGRAM=$1
	sshpass -p $PASSWORD ssh ${USER_NAME}@${VM_IP} $VM_PROGRAM	
}

execute_program()
{
	PROJECT=$1
	deploy_file $PROJECT/$OUT_DIR/$PROJECT
	execute_vm_program ./$PROJECT	
}

export -f execute_program

make clean > /dev/null
make all > /dev/null

gnome-terminal -x bash -c 'execute_program ./project1; bash'
#gnome-terminal -x bash -c 'execute_program ./project2; bash'

