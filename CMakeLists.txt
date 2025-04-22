cmake_minimum_required(VERSION 3.10)
include("${CMAKE_CURRENT_LIST_DIR}/Utils.cmake")

option(BUILD_BOUNT_UI_EXAMPLES "BUILD BOUNT UI EXAMPLES" OFF)

# Load Environment Variables
set(BOUNT_GL_MODULE "${CMAKE_CURRENT_LIST_DIR}/GL")
if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/.env.cmake")
    include("${CMAKE_CURRENT_LIST_DIR}/.env.cmake")
endif()

# Prepares the Module Update Target
list(APPEND BOUNT_UI_MODULES GL)
bount_create_module_update_target(Bount-UI-Update-Modules BOUNT_UI_MODULES)

if(NOT TARGET Bount-UI-Library)
    project(Bount-UI-Library)

    # Load Required Libraries
    add_subdirectory(${BOUNT_GL_MODULE} GL)

    set(BOUNT_UI_INCLUDES "${CMAKE_CURRENT_LIST_DIR}/include")
    file(GLOB_RECURSE BOUNT_UI_SRC
        "${CMAKE_CURRENT_LIST_DIR}/src/**.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/**.cxx"
        "${CMAKE_CURRENT_LIST_DIR}/src/**.cc")
    
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        list(APPEND BOUNT_UI_PRIVATE_COMPILE_OPTIONS /wd4244 /wd4267)
    endif()

    add_custom_target(Bount-UI-Resources
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/__run_always
        COMMENT "Copying UI Resources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_LIST_DIR}/Resources" "${CMAKE_BINARY_DIR}/$<CONFIG>/Resources")

    # Building
    add_library(Bount-UI SHARED ${BOUNT_UI_SRC})
    add_dependencies(Bount-UI Bount-UI-Update-Modules Bount-UI-Resources)
    set_target_properties(Bount-UI PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/lib"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/bin")
    target_compile_definitions(Bount-UI PRIVATE BOUNT_UI_BUILD_API)
    target_compile_definitions(Bount-UI PUBLIC BOUNT_UI_USE_API)
    target_compile_options(Bount-UI PRIVATE ${BOUNT_UI_PRIVATE_COMPILE_OPTIONS})
    target_include_directories(Bount-UI PUBLIC ${BOUNT_UI_INCLUDES})
    target_link_libraries(Bount-UI PUBLIC Bount::GL)
    target_precompile_headers(Bount-UI PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/Bount/UI/Precompiled.hpp")
    add_library(Bount::UI ALIAS Bount-UI)
endif()

if(BUILD_BOUNT_UI_EXAMPLES AND (NOT TARGET Bount-UI-Examples))
    project(Bount-UI-Examples)

    list(APPEND BOUNT_UI_EXAMPLES BasicShapes)
    foreach(example ${BOUNT_UI_EXAMPLES})
        file(GLOB_RECURSE BOUNT_UI_EXAMPLE_${example}_SRC
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.cxx"
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.cc")
        add_executable(Bount-UI-Example-${example} ${BOUNT_UI_EXAMPLE_${example}_SRC})
        set_target_properties(Bount-UI-Example-${example} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>/examples"
            RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/$<CONFIG>/examples"
            RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/$<CONFIG>/examples"
            OUTPUT_NAME "${example}")
        target_include_directories(Bount-UI-Example-${example} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/include")
        target_link_libraries(Bount-UI-Example-${example} PRIVATE Bount::UI)
    endforeach()
    
    list(GET BOUNT_UI_EXAMPLES 0 SOME_BOUNT_UI_EXAMPLE)
    add_custom_command(TARGET Bount-UI-Example-${SOME_BOUNT_UI_EXAMPLE}
        POST_BUILD
        DEPENDS "${CMAKE_CURRENT_LIST_DIR}/__run_always"
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_BINARY_DIR}/$<CONFIG>/bin" "${CMAKE_BINARY_DIR}/$<CONFIG>/examples")
    
        add_custom_command(TARGET Bount-UI-Example-${SOME_BOUNT_UI_EXAMPLE}
        POST_BUILD
        DEPENDS "${CMAKE_CURRENT_LIST_DIR}/__run_always"
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different "${CMAKE_CURRENT_LIST_DIR}/examples/Resources" "${CMAKE_BINARY_DIR}/$<CONFIG>/Resources")
endif()

