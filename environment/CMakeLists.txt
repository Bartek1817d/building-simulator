cmake_minimum_required(VERSION 3.13)
project(environment)
include(../common.cmake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp configuration.cpp Period.cpp)

link_directories(${CMAKE_INSTALL_PREFIX}/${TARGET_LIB_DIR})

add_executable(environment ${SOURCE_FILES})

target_include_directories(environment SYSTEM PUBLIC
        ${TARGET_SYSTEM_INCLUDES}
        )
target_include_directories(environment PUBLIC
        ${BOOST_INCLUDE_DIR}
        ${SUBPROJECTS_INCLUDE_DIR}
        )

target_link_libraries(environment yaml-cpp m)

install(TARGETS environment
        RUNTIME DESTINATION ${TARGET_BIN_DIR})
install(FILES config.yml DESTINATION ${TARGET_CONFIG_DIR})