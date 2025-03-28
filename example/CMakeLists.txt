cmake_minimum_required(VERSION 3.25)

project(AuriTextSDL2Example LANGUAGES C VERSION 1.0)

set(CMAKE_C_FLAGS_DEBUG "-g -Wall")
set(CMAKE_C_FLAGS_RELEASE "-s -O2")

file(GLOB SOURCE_FILES "*.c")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(
	${SDL2_INCLUDE_DIRS}
	${SDL2_image_INCLUDE_DIRS}
)

add_library(AuriText-SDL2 STATIC ../auriText.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}
	${SDL2_LIBRARIES}
	SDL2_image
	AuriText-SDL2
)
target_include_directories(${PROJECT_NAME} PRIVATE src/)