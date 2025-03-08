cmake_minimum_required(VERSION 3.25)
project(AuriText LANGUAGES C)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
set(CMAKE_C_FLAGS_RELEASE "-s -O2")

file(GLOB SOURCE_FILES "*.c")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
include_directories(
	${SDL3_INCLUDE_DIRS}
	${SDL3_image_INCLUDE_DIRS}
)

if(BUILD_SHARED_LIBS)
	add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
else()
	add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
endif()
target_include_directories(${PROJECT_NAME} PRIVATE src/)