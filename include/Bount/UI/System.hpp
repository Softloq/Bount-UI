#ifndef BOUNT_UI_SYSTEM_HPP
#define BOUNT_UI_SYSTEM_HPP

#include "Bount/UI/Lib-Macro.hpp"

#include <include/gpu/ganesh/GrDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLInterface.h>

#include <include/core/SkSurface.h>
#include <include/core/SkCanvas.h>
#include <include/core/SkFontMgr.h>
#include <modules/svg/include/SkSVGDOM.h>

#include <mutex>

namespace Bount::UI
{
class System
{
    static System* _instance;
    static std::once_flag _init;

    sk_sp<GrDirectContext> _context;
    sk_sp<SkSurface> _surface;
    sk_sp<SkFontMgr> _font_manager;

public:
    BOUNT_UI_API System(const System&) = delete;
    BOUNT_UI_API System& operator=(const System&) = delete;
    
    BOUNT_UI_API static System& instance();
    
    BOUNT_UI_API bool initialize();
    BOUNT_UI_API void shutdown();

    BOUNT_UI_API sk_sp<SkSVGDOM> makeSVGDOM(SkStream& stream);

    BOUNT_UI_API SkCanvas* const getCanvas() const;
    BOUNT_UI_API const sk_sp<GrDirectContext>& getContext();

private:
    BOUNT_UI_API System();
    BOUNT_UI_API ~System();
};
}

#endif