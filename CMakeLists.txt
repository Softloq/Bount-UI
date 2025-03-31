cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CONFIGURATION_TYPES "Debug" "Development" "Release" "RelWithDebInfo" "MinSizeRel")
foreach(config ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${config} UPPER_config)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${UPPER_config} "${CMAKE_BINARY_DIR}/${UPPER_config}/bin")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${UPPER_config} "${CMAKE_BINARY_DIR}/${UPPER_config}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${UPPER_config} "${CMAKE_BINARY_DIR}/${UPPER_config}/lib")
endforeach()

set(BOUNT_GL_MODULE "${CMAKE_CURRENT_LIST_DIR}/GL")
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/Custom.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/Custom.cmake")
endif()

if(NOT TARGET Bount::UI)
    project(Bount-UI)

    # Modules
    add_subdirectory(${BOUNT_GL_MODULE} GL)

    # Resources
    add_custom_target(
        Bount-UI-Resources
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__run_always
        COMMENT "Copying UI Resources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_LIST_DIR}/resources" "${CMAKE_BINARY_DIR}/$<CONFIG>/bin/Resources")

    # Includes
    set(Bount_UI_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

    # Sources
    file(GLOB_RECURSE Bount_UI_SRC
        "${CMAKE_CURRENT_LIST_DIR}/src/**.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/**.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/src/**.cc")

    # Building
    add_library(Bount-UI SHARED ${Bount_UI_SRC})
    add_dependencies(Bount-UI Bount-UI-Resources)
    set_target_properties(Bount-UI PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/lib"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/bin")
    target_compile_definitions(Bount-UI PRIVATE BOUNT_UI_BUILD_API)
    target_compile_definitions(Bount-UI PUBLIC BOUNT_UI_USE_API)
    target_compile_options(Bount-UI PUBLIC /wd4244 /wd4267)
    target_include_directories(Bount-UI PUBLIC ${Bount_UI_INCLUDE_DIRS})
    target_link_libraries(Bount-UI PUBLIC Bount::GL)
    target_precompile_headers(Bount-UI PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/Bount/UI/Precompiled.hpp")
    add_library(Bount::UI ALIAS Bount-UI)
endif()
