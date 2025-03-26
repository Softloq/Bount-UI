#include "Bount/UI/Surface.hpp"
#include "Bount/UI/System.hpp"

#include <include/gpu/ganesh/SkSurfaceGanesh.h>
#include <include/gpu/ganesh/GrBackendSurface.h>
#include <include/gpu/ganesh/gl/GrGLBackendSurface.h>
#include <src/gpu/ganesh/gl/GrGLDefines.h>

#include <include/core/SkColorSpace.h>

namespace Bount::UI
{
BOUNT_UI_API Surface::Surface()
{
    GrGLFramebufferInfo framebufferInfo;
    framebufferInfo.fFBOID = 0; // Default framebuffer
    framebufferInfo.fFormat = GR_GL_RGBA8; // Or your desired format

    auto backendRenderTarget = GrBackendRenderTargets::MakeGL(800, 600, 0, 8, framebufferInfo);

    SkSurfaceProps surfaceProps(0, kUnknown_SkPixelGeometry);
    SkColorType colorType = kRGBA_8888_SkColorType;

    _surface = SkSurfaces::WrapBackendRenderTarget(System::instance().getContext().get(), backendRenderTarget, kBottomLeft_GrSurfaceOrigin, colorType, nullptr, &surfaceProps);
    _canvas = _surface->getCanvas();
}
BOUNT_UI_API Surface::~Surface()
{

}
BOUNT_UI_API void Surface::drawSVGDOM(const sk_sp<SkSVGDOM>& dom)
{
    dom->render(_canvas);
}
BOUNT_UI_API void Surface::clear(SkColor color)
{
    _canvas->clear(color);
}
BOUNT_UI_API void Surface::clear(const SkColor4f& color)
{
    _canvas->clear(color);
}
}