#include "Bount/UI/SVGLayer.hpp"
#include "Bount/UI/System.hpp"

#include <include/core/SkStream.h>

#include <iostream>

namespace Bount::UI
{
BOUNT_UI_API SVGLayer::SVGLayer()
{
    // Raw SVG text.
    const char* svgText = R"(
        <svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">
            <circle cx="100" cy="100" r="80" fill="green" />
            <text x="50" y="120" font-size="30" fill="white">SVG Text</text>
        </svg>
    )";

    SkMemoryStream svgStream(svgText, strlen(svgText));
    _dom = SkSVGDOM::MakeFromStream(svgStream);
}
BOUNT_UI_API SVGLayer::~SVGLayer()
{
    
}

BOUNT_UI_API void SVGLayer::handleEvent(const GL::Event& event)
{

}
BOUNT_UI_API void SVGLayer::draw()
{
    auto canvas = System::instance().getCanvas();
    canvas->clear(SK_ColorBLUE);
    _dom->render(canvas);
    System::instance().clear();
}
}