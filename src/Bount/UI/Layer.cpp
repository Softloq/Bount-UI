#include "Bount/UI/Layer.hpp"
#include "Bount/UI/System.hpp"

#include <include/core/SkStream.h>

#include <iostream>

namespace Bount::UI
{
BOUNT_UI_API Layer::Layer()
    : _collider(new BoxCollider(200, 200, 100, 100))
{
    // Raw SVG text.
    std::string svgText = R"(
    <svg width="800" height="600" xmlns="http://www.w3.org/2000/svg">
        <rect x="200" y="200" width="100" height="100" fill="green" />
        <text x="200" y="200" font-size="20" font-family="arial" fill="black">Hello, Skia!</text>
    </svg>
    )";
    SkMemoryStream svgStream(svgText.c_str(), svgText.length(), true);
    _dom =  System::instance().makeSVGDOM(svgStream);
}
BOUNT_UI_API Layer::~Layer()
{
    
}
BOUNT_UI_API void Layer::handleEvent(const GL::Event& event)
{
    if (event.getSDLEvent().type == SDL_EVENT_MOUSE_MOTION)
    {
        auto& motion = event.getSDLEvent().motion;
        if (_collider->pointCollided(motion.x, motion.y))
        {
            std::cout << "Entered" << std::endl;
        }
        else
        {
            std::cout << "" << std::endl;
        }
    }
}
BOUNT_UI_API void Layer::draw()
{
    _surface.clear(SK_ColorWHITE);
    _surface.drawSVGDOM(_dom);
    System::instance().getContext()->flush();
}
}