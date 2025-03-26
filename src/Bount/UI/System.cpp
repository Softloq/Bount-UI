#include "Bount/UI/System.hpp"

#include <include/gpu/ganesh/SkSurfaceGanesh.h>
#include <include/gpu/ganesh/GrBackendSurface.h>
#include <include/gpu/ganesh/gl/GrGLBackendSurface.h>
#include <src/gpu/ganesh/gl/GrGLDefines.h>

#include <include/core/SkColorSpace.h>
#include <include/core/SkGraphics.h>

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

    GrGLFramebufferInfo framebufferInfo;
    framebufferInfo.fFBOID = 0; // Default framebuffer
    framebufferInfo.fFormat = GR_GL_RGBA8; // Or your desired format

    auto backendRenderTarget =
    GrBackendRenderTargets::MakeGL(
        800, 600,
		0, // sample count
		8, // stencil bits
		framebufferInfo
    );

    SkSurfaceProps surfaceProps(0, kUnknown_SkPixelGeometry);
    SkColorType colorType = kRGBA_8888_SkColorType;
    // SkImageInfo imageInfo = SkImageInfo::Make(800, 600, colorType, kPremul_SkAlphaType);

    _surface = SkSurfaces::WrapBackendRenderTarget(_context.get(), backendRenderTarget, kBottomLeft_GrSurfaceOrigin, colorType, nullptr, &surfaceProps);
    if (!_surface)
    {
        std::cerr << "Error creating SkSurface." << std::endl;
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

BOUNT_UI_API SkCanvas* const System::getCanvas() const
{
    return _surface->getCanvas();
}

BOUNT_UI_API const sk_sp<GrDirectContext>& System::getContext()
{
    return _context;
}
}