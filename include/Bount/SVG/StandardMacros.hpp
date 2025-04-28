/**
 * @file StandardMacros.hpp
 * @brief Standard SVG Library Macros. This is included in all svg library headers.
 * @author Brandon Foster (Paradox Gene)
 */

#ifndef BOUNT_SVG_STANDARD_MACROS_HPP
#define BOUNT_SVG_STANDARD_MACROS_HPP

#include <Bount/Graphics/StandardMacros.hpp>

/**
 * Main Macros:
 * BOUNT_SVG_API - Must be prefixed in all svg library classes and functions.
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
    #define BOUNT_SVG_EXPORT __declspec(dllexport)
    #define BOUNT_SVG_IMPORT __declspec(dllimport)
#elif defined(BOUNT_CLANG)
    #define BOUNT_SVG_EXPORT __attribute__((visibility("default")))
    #define BOUNT_SVG_IMPORT
#elif defined(BOUNT_GCC)
    #define BOUNT_SVG_EXPORT __attribute__((visibility("default")))
    #define BOUNT_SVG_IMPORT
#endif

#if defined(BOUNT_SVG_BUILD_API)
    #define BOUNT_SVG_API BOUNT_SVG_EXPORT
#elif defined(BOUNT_SVG_USE_API)
    #define BOUNT_SVG_API BOUNT_SVG_IMPORT
#else
    #define BOUNT_SVG_API
#endif

#ifndef BOUNT_SVG_EXPORT
    #define BOUNT_SVG_EXPORT
#endif

#ifndef BOUNT_SVG_IMPORT
    #define BOUNT_SVG_IMPORT
#endif

#ifndef BOUNT_SVG_API
    #define BOUNT_SVG_API
#endif

#endif