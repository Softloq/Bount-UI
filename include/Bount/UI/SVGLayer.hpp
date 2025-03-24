#ifndef BOUNT_UI_SVG_LAYER_HPP
#define BOUNT_UI_SVG_LAYER_HPP

#include "Bount/UI/Lib-Macro.hpp"
#include <Bount/GL/Layer.hpp>

#include <include/gpu/ganesh/GrBackendSurface.h>
#include <include/gpu/ganesh/gl/GrGLBackendSurface.h>

#include <include/gpu/ganesh/GrDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLInterface.h>

#include <include/gpu/ganesh/SkSurfaceGanesh.h>

#include <include/core/SkSurface.h>
#include <include/core/SkCanvas.h>
#include <include/core/SkPaint.h>
#include <include/core/SkColorSpace.h>

#include <include/core/SkStream.h>

#include <include/svg/SkSVGCanvas.h>
#include <modules/svg/include/SkSVGDOM.h>
#include <modules/svg/include/SkSVGTypes.h>

namespace Bount::UI
{
class SVGLayer : public GL::Layer
{
    sk_sp<GrDirectContext> _context;
    sk_sp<SkSurface> _surface;
    sk_sp<SkData> _data;
    sk_sp<SkSVGDOM> _dom;

public:
    BOUNT_UI_API SVGLayer();
    BOUNT_UI_API ~SVGLayer();

    BOUNT_UI_API void handleEvent() override;
    BOUNT_UI_API void draw() override;
};
}

#endif