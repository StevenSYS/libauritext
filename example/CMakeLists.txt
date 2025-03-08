cmake_minimum_required(VERSION 3.25)

project(AuriTextExample LANGUAGES C VERSION 0.1)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
set(CMAKE_C_FLAGS_RELEASE "-s -O2")

file(GLOB SOURCE_FILES "*.c")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
include_directories(
	${SDL3_INCLUDE_DIRS}
	${SDL3_image_INCLUDE_DIRS}
)

add_library(AuriText STATIC ../auriText.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
	SDL3
	SDL3_image
	AuriText
)
target_include_directories(${PROJECT_NAME} PRIVATE src/)