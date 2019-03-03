cmake_minimum_required(VERSION 3.13)
project(building-dao)
set(CMAKE_CXX_STANDARD 11)

include(../common.cmake)

set(SOURCE_FILES src/implementation/DAO.cpp)

add_library(building-dao SHARED ${SOURCE_FILES})
set_target_properties(building-dao PROPERTIES PUBLIC_HEADER src/include/DAO.h)

target_include_directories(building-dao SYSTEM PUBLIC ${TARGET_SYSTEM_INCLUDES})
target_include_directories(building-dao PUBLIC
        src/include
        ${SUBPROJECTS_INCLUDE_DIR}
        )

install(TARGETS building-dao
        LIBRARY DESTINATION ${TARGET_LIB_DIR}
        PUBLIC_HEADER DESTINATION ${TARGET_INCLUDE_DIR})