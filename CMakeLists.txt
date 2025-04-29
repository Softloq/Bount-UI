cmake_minimum_required(VERSION 4.0.1)
project(Bount-UI-Project LANGUAGES CXX)

option(BUILD_BOUNT_UI_EXAMPLES "BUILD BOUNT UI EXAMPLES" OFF)
option(BUILD_BOUNT_EXAMPLES "BUILD ALL BOUNT EXAMPLES" OFF)

include("${CMAKE_CURRENT_LIST_DIR}/.cmake/config.cmake")

load_env_cmake()

update_bount_git_module(Graphics main)

load_github_binaries(FreeType 2-13-3)

if(NOT TARGET Bount-UI-Library)
    project(Bount-UI-Library)

    add_subdirectory(${BOUNT_GRAPHICS_MODULE} Graphics)

    create_bount_library_vars(BOUNT_UI)
    add_library(Bount-UI SHARED)
    target_sources(Bount-UI
    PRIVATE
        ${BOUNT_UI_CXX_SRC}
        ${BOUNT_UI_CXX_MODULE_SRC}
    PUBLIC
        FILE_SET bount_ui_cxx_headers TYPE HEADERS
        BASE_DIRS ${BOUNT_UI_CXX_INCLUDE_DIR}
        FILES ${BOUNT_UI_CXX_HEADER_FILES}
    PUBLIC
        FILE_SET bount_ui_cxx_modules TYPE CXX_MODULES
        BASE_DIRS ${BOUNT_UI_CXX_MODULE_DIR}
        FILES ${BOUNT_UI_CXX_MODULE_FILES}
    )
    target_precompile_headers(Bount-UI
        PRIVATE
            "${BOUNT_UI_CXX_INCLUDE_DIR}/Bount/SVG/Precompiled.hpp"
            "${BOUNT_UI_CXX_INCLUDE_DIR}/Bount/UI/Precompiled.hpp"
    )

    target_link_libraries(Bount-UI PUBLIC Bount::Graphics)
    set_bount_library_api_macros(Bount-UI BOUNT_UI BOUNT_SVG)
    set_bount_library_common_properties(Bount-UI)
    add_library(Bount::UI ALIAS Bount-UI)

    copy_bount_resources(Bount-UI-Resources Bount-UI)
endif()

if((BUILD_BOUNT_UI_EXAMPLES OR BUILD_BOUNT_EXAMPLES) AND (NOT TARGET Bount-UI-Examples))
    project(Bount-UI-Examples)

    list(APPEND BOUNT_UI_EXAMPLES BasicShapes)
    foreach(example ${BOUNT_UI_EXAMPLES})
        file(GLOB_RECURSE BOUNT_UI_EXAMPLE_${example}_SRC
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.cc"
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.cxx"
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.c++"
            "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/src/**.cpp"
        )
        add_executable(Bount-UI-Example-${example} ${BOUNT_UI_EXAMPLE_${example}_SRC})
        target_include_directories(Bount-UI-Example-${example} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/examples/${example}/include")
        target_link_libraries(Bount-UI-Example-${example} PRIVATE Bount::UI)
        set_bount_example_common_properties(Bount-UI-Example-${example} ${example})
    endforeach()

    add_custom_command(TARGET Bount-UI
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            "${CMAKE_CURRENT_LIST_DIR}/examples/Resources"
            "${CMAKE_BINARY_DIR}/$<CONFIG>/Resources"
    )
endif()
