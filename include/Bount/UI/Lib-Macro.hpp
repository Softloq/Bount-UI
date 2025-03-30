#ifndef BOUNT_UI_LIB_MACRO_HPP
#define BOUNT_UI_LIB_MACRO_HPP

#include "Bount/Core/Datatypes.hpp"

#if defined(_DLL)
    #define BOUNT_UI_EXPORT __declspec(dllexport)
    #define BOUNT_UI_IMPORT __declspec(dllimport)
#elif defined(__PIC__) || defined(__pic__)
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