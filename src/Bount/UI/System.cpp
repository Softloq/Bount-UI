#include "Bount/UI/System.hpp"

#include <include/ports/SkTypeface_win.h>

#include <iostream>

namespace Bount::UI
{
System* System::_instance = nullptr;
std::once_flag System::_init;
BOUNT_UI_API System& System::instance()
{
    std::call_once(_init, []()
    {
        _instance = new System;
    });
    return *_instance;
}
BOUNT_UI_API System::System()
    : _font_manager(SkFontMgr_New_GDI())
{
}
BOUNT_UI_API System::~System()
{
}
BOUNT_UI_API bool System::initialize()
{
    auto glInterface = GrGLMakeNativeInterface();
    if (!glInterface)
    {
        std::cerr << "Failed to create GrGLInterface" << std::endl;
        return false;
    }

    _context = GrDirectContexts::MakeGL(glInterface);
    if (!_context)
    {
        std::cerr << "Failed to create GrDirectContext" << std::endl;
        return false;
    }
    return true;
}
BOUNT_UI_API void System::shutdown()
{

}

BOUNT_UI_API sk_sp<SkSVGDOM> System::makeSVGDOM(SkStream& stream)
{   
    return SkSVGDOM::Builder().setFontManager(_font_manager).make(stream);
}

BOUNT_UI_API const sk_sp<GrDirectContext>& System::getContext()
{
    return _context;
}
}