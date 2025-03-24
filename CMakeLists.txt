cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

if(NOT TARGET Bount::UI)
project(Bount-UI)

set(BOUNT_GL_MODULE "${CMAKE_CURRENT_LIST_DIR}/GL")
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/Custom.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/Custom.cmake")
endif()

add_subdirectory(${BOUNT_GL_MODULE} GL)

set(SKIA_VERSION 2025-03-24)
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/external/skia-${SKIA_VERSION}.zip")
    file(DOWNLOAD "https://github.com/Softloq/Skia-Prebuilt/releases/download/v${SKIA_VERSION}/skia-win64.zip" "${CMAKE_CURRENT_LIST_DIR}/external/skia-${SKIA_VERSION}.zip" SHOW_PROGRESS)
endif()
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/external/skia-${SKIA_VERSION}")
    file(ARCHIVE_EXTRACT INPUT "${CMAKE_CURRENT_LIST_DIR}/external/skia-${SKIA_VERSION}.zip" DESTINATION "${CMAKE_CURRENT_LIST_DIR}/external/skia-${SKIA_VERSION}")
endif()
include("${CMAKE_CURRENT_LIST_DIR}/external/skia-${SKIA_VERSION}/skia.cmake")

set(Bount_UI_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")
file(GLOB_RECURSE Bount_UI_SRC "${CMAKE_CURRENT_LIST_DIR}/src/**.cpp"
                               "${CMAKE_CURRENT_LIST_DIR}/src/**.cxx"
                               "${CMAKE_CURRENT_LIST_DIR}/src/**.cc")
add_library(Bount-UI SHARED ${Bount_UI_SRC})
add_library(Bount::UI ALIAS Bount-UI)
target_compile_definitions(Bount-UI PRIVATE BOUNT_UI_BUILD_API)
target_compile_definitions(Bount-UI PUBLIC BOUNT_UI_USE_API)
target_include_directories(Bount-UI PUBLIC ${Bount_UI_INCLUDE_DIRS})
target_link_libraries(Bount-UI PUBLIC Bount::GL skia::all)
endif()
