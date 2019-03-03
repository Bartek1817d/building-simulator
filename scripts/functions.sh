function ssh_wrapper
{
	VM_PROGRAM=$1
	ssh $TARGET_USER_NAME@$TARGET_IP $VM_PROGRAM	
}

function scp_wrapper
{
	SRC=$1
	DST=$2
	if [[ $DST != $TARGET_HOME_DIR* ]]
	then
		DST=$TARGET_HOME_DIR/$DST
	fi
	ssh_wrapper "mkdir -p $(dirname $DST)" &&
	scp $SRC $TARGET_USER_NAME@$TARGET_IP:$DST > /dev/null
}

function cp_wrapper
{
	SRC=$1
	DST=$2
	DST=$HOST_MOUNT_POINT/$DST
	mkdir -p $(dirname $DST) && cp $SRC $DST
}

function mount_filesystem
{
	echo "Mounting filesystem"
	sshfs -oIdentityFile=$HOST_PRIVATE_KEY $TARGET_USER_NAME@$TARGET_IP:$TARGET_HOME_DIR $HOST_MOUNT_POINT
}

function deploy
{
	SRC=$1
	DST=$2
	if mount | grep $HOST_MOUNT_POINT > /dev/null; then
		cp_wrapper $SRC $DST
	elif mount_filesystem; then
		cp_wrapper $SRC $DST
	else
		scp_wrapper $SRC $DST
	fi		
}
