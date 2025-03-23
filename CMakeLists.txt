cmake_minimum_required(VERSION 3.25)

option(BUILD_SHARED_LIBS "Build shared version of ${PROJECT_NAME}" on)

project(AuriText LANGUAGES C)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
set(CMAKE_C_FLAGS_RELEASE "-s -O2")

file(GLOB SOURCE_FILES "*.c")

find_package(SDL3 REQUIRED)
include_directories(${SDL3_INCLUDE_DIRS})

if(BUILD_SHARED_LIBS)
	add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
else()
	add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif()
target_link_libraries(${PROJECT_NAME} SDL3)
target_include_directories(${PROJECT_NAME} PRIVATE src/)