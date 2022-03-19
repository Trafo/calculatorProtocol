cmake_minimum_required (VERSION 3.16.3 FATAL_ERROR)

set (PROJECT_NAME "calculatorProtocol")
project (${PROJECT_NAME})

set (PROJECT_MAJOR_VERSION 0)
set (PROJECT_MINOR_VERSION 1)
set (PROJECT_PATCH_VERSION 0)

set (PROJECT_VERSION_STRING
    "${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION}")

message (STATUS "Running CMake version ${CMAKE_VERSION}")
message (STATUS "Running CMake for ${PROJECT_NAME} ${PROJECT_VERSION_STRING}")

set (PROJECT_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set (PROJECT_EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")

set (PROJECT_WARNING_FLAGS "")

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_COMPILER_IS_GNUCC)
  set (CMAKE_CXX_STANDARD 17)
  set (PROJECT_WARNING_FLAGS "-Werror" "-Wall" "-Wextra" "-pedantic")
endif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_COMPILER_IS_GNUCC)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set (CMAKE_CXX_STANDARD 17)
  set (PROJECT_WARNING_FLAGS "/W2" "/WX")
endif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

add_subdirectory (${PROJECT_EXTERNAL_DIR})
include_directories(${PROJECT_SRC_DIR})

set (PROJECT_SOURCES 
"src/main.cpp"

"src/operations/OperationType.h"
"src/operations/BaseOperation.h"
"src/operations/AddOperation.h"
"src/operations/InvalidOperation.h"
"src/operations/SubOperation.h"
"src/operations/MulOperation.h"
"src/operations/DivOperation.h"
"src/operations/VariantOperation.h"
"src/utils/parseJsonFile.h"
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann)