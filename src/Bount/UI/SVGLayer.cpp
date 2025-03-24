#include "Bount/UI/SVGLayer.hpp"
#include "Bount/GL/Window.hpp"

#include <iostream>

namespace Bount::UI
{
BOUNT_UI_API SVGLayer::SVGLayer()
{
    auto glInterface = GrGLMakeNativeInterface();
    if (!glInterface)
    {
    }

    _context = GrDirectContexts::MakeGL(glInterface);
    if (!_context)
    {
    }

    GrGLFramebufferInfo framebufferInfo;
    framebufferInfo.fFBOID = 0; // Default framebuffer
    framebufferInfo.fFormat = GL_RGBA8; // Or your desired format

    auto backendRenderTarget =
        GrBackendRenderTargets::MakeGL(800, 600,
		0, // sample count
		8, // stencil bits
		framebufferInfo);
    

    SkSurfaceProps surfaceProps(0, kUnknown_SkPixelGeometry);
    SkColorType colorType = kRGBA_8888_SkColorType;
    SkImageInfo imageInfo = SkImageInfo::Make(800, 600, colorType, kPremul_SkAlphaType);

    _surface = SkSurfaces::WrapBackendRenderTarget(_context.get(), backendRenderTarget, kBottomLeft_GrSurfaceOrigin, colorType, nullptr, &surfaceProps);
}
BOUNT_UI_API SVGLayer::~SVGLayer()
{
    
}

BOUNT_UI_API void SVGLayer::handleEvent()
{

}
BOUNT_UI_API void SVGLayer::draw()
{
    SkCanvas* canvas = _surface->getCanvas();
    canvas->clear(SK_ColorBLUE);

    SkPaint paint;
    paint.setColor(SK_ColorRED);
    canvas->drawCircle(400, 300, 100, paint);

    _context->flush();
}
}