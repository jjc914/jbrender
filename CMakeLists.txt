cmake_minimum_required(VERSION 3.5)

# Definitions
set(PROJECT_NAME jbrender)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")
set(CMAKE_BUILD_TYPE Debug)

project(${PROJECT_NAME})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# Include paths
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib/linalg)
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib/input)
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib/meshtools)

# Source paths
set(SRC_DIRS ${SRC_DIRS} ${PROJECT_SOURCE_DIR}/src/render)

# Merge paths
set(ALL_DIRS ${INCLUDE_DIRS} ${SRC_DIRS})

# Assign the include directories
include_directories(${ALL_DIRS})

# Find library sources
file(GLOB_RECURSE LIB_SRC_FILES lib/*/*.c src/*/*.c)

# Build static/shared library
add_library(${PROJECT_NAME}_LIB STATIC ${LIB_SRC_FILES})

# Install library
install(TARGETS ${PROJECT_NAME}_LIB DESTINATION lib)

# Install library headers
file(GLOB_RECURSE LIB_INC_FILES lib/*/*.h src/*/*.h)
install(FILES ${LIB_INC_FILES} DESTINATION include)

set(SOURCE_FILES src/main.c)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_LIB)
