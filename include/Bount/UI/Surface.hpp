#ifndef BOUNT_UI_SURFACE_HPP
#define BOUNT_UI_SURFACE_HPP

#include "Bount/UI/Lib-Macro.hpp"

#include <include/core/SkSurface.h>
#include <include/core/SkCanvas.h>
#include <modules/svg/include/SkSVGDOM.h>
#include <modules/svg/include/SkSVGRenderContext.h>

namespace Bount::UI
{
class Surface
{
    sk_sp<SkSurface> _surface;
    SkCanvas* _canvas;

public:
    BOUNT_UI_API Surface();
    BOUNT_UI_API ~Surface();

    BOUNT_UI_API void drawSVGDOM(const sk_sp<SkSVGDOM>& dom);

    BOUNT_UI_API void clear(SkColor color);
    BOUNT_UI_API void clear(const SkColor4f& color);
};
}

#endif