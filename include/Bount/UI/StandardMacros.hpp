/**
 * @file StandardMacros.hpp
 * @brief Standard UI Library Macros. This is included in all ui library headers.
 * @author Brandon Foster (Paradox Gene)
 */

#ifndef BOUNT_UI_STANDARD_MACROS_HPP
#define BOUNT_UI_STANDARD_MACROS_HPP

#include <Bount/Graphics/StandardMacros.hpp>

/**
 * Main Macros:
 * BOUNT_UI_API - Must be prefixed in all ui library classes and functions.
 *
 * BOUNT_DEBUG - Defined when debug information should be provided.
 * 
 * BOUNT_MSVC  - Defined when the libraries are compiled with Microsoft C++ compiler.
 * BOUNT_CLANG - Defined when the libraries are compiled with Clang C++ compiler.
 * BOUNT_GCC   - Defined when the libraries are compiled with GNU C++ compiler.
 * 
 * BOUNT_WINDOWS - Defined when the libraries are compiled for Windows.
 * BOUNT_LINUX   - Defined when the libraries are compiled for Linux.
 * BOUNT_MACOS   - Defined when the libraries are compiled for macOS.
 */

#if defined(BOUNT_MSVC)
    #define BOUNT_UI_EXPORT __declspec(dllexport)
    #define BOUNT_UI_IMPORT __declspec(dllimport)
#elif defined(BOUNT_CLANG)
    #define BOUNT_UI_EXPORT __attribute__((visibility("default")))
    #define BOUNT_UI_IMPORT
#elif defined(BOUNT_GCC)
    #define BOUNT_UI_EXPORT __attribute__((visibility("default")))
    #define BOUNT_UI_IMPORT
#endif

#if defined(BOUNT_UI_BUILD_API)
    #define BOUNT_UI_API BOUNT_UI_EXPORT
#elif defined(BOUNT_UI_USE_API)
    #define BOUNT_UI_API BOUNT_UI_IMPORT
#else
    #define BOUNT_UI_API
#endif

#ifndef BOUNT_UI_EXPORT
    #define BOUNT_UI_EXPORT
#endif

#ifndef BOUNT_UI_IMPORT
    #define BOUNT_UI_IMPORT
#endif

#ifndef BOUNT_UI_API
    #define BOUNT_UI_API
#endif

#endif