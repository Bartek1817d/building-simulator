set(HOST_MOUNT_POINT /mnt/qnx)
set(HOST_INCLUDE_DIR ${HOST_MOUNT_POINT}/include)

set(TARGET_SYSTEM_INCLUDES
	$ENV{QNX_TARGET}/usr/include/
	$ENV{QNX_TARGET}/usr/include/cpp
	$ENV{QNX_TARGET}/usr/include/cpp/c
)
set(TARGET_BIN_DIR ${HOST_MOUNT_POINT}/bin)
set(TARGET_LIB_DIR ${HOST_MOUNT_POINT}/lib)
set(TARGET_INCLUDE_DIR ${HOST_MOUNT_POINT}/include)

set(SOFTWARE_DIR $ENV{HOME}/Software)
set(BOOST_INCLUDE_DIR ${SOFTWARE_DIR}/boost_1_67_0/include)
set(SUBPROJECTS_INCLUDE_DIR ../include ../logger/src)
