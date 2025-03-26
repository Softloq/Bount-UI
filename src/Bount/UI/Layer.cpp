#include "Bount/UI/Layer.hpp"
#include "Bount/UI/System.hpp"

#include <include/core/SkStream.h>
#include <include/core/SkTypeface.h>
#include <include/core/SkPaint.h>
#include <include/core/SkFont.h>
#include <include/core/SkString.h>
#include <include/ports/SkTypeface_win.h>
#include <include/core/SkFontMgr.h>
#include <include/core/SkFontStyle.h>

#include <iostream>

SkPaint textPaint;
SkFont textFont;
SkString text;

namespace Bount::UI
{
BOUNT_UI_API Layer::Layer()
{
    sk_sp<SkFontMgr> fontMgr = SkFontMgr_New_GDI();

    // Raw SVG text.
    std::string svgText = R"(
        <svg width="800" height="600" xmlns="http://www.w3.org/2000/svg">
        <circle cx="100" cy="100" r="80" fill="green" />
        <text x="400" y="300" font-size="40" font-family="arial" fill="black">Hello, Skia!</text>
        </svg>
    )";
    SkMemoryStream svgStream(svgText.c_str(), svgText.length(), true);
    _dom =  SkSVGDOM::Builder().setFontManager(fontMgr).make(svgStream);
}
BOUNT_UI_API Layer::~Layer()
{
    
}

BOUNT_UI_API void Layer::handleEvent(const GL::Event& event)
{
    if (event.getSDLEvent().type == SDL_EVENT_MOUSE_MOTION)
    {
        // std::cout << "Mouse Move" << std::endl;
    }
}
BOUNT_UI_API void Layer::draw()
{
    auto canvas = System::instance().getCanvas();
    canvas->clear(SK_ColorWHITE);

    _dom->render(canvas);
    System::instance().clear();
}
}