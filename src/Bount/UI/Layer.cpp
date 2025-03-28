#include "Bount/UI/Layer.hpp"
#include "Bount/UI/System.hpp"

#include <include/core/SkStream.h>
#include <modules/svg/include/SkSVGText.h>

#include <iostream>

namespace Bount::UI
{
BOUNT_UI_API Layer::Layer()
    : _dispatcher(this)
    , _collider(new BoxCollider(200, 200, 100, 100))
    , _x(0.0f), _y(0.0f)
    , _width(100.0f), _height(100.0f)
{
    // Raw SVG text.
    std::string svgText = R"(
    <svg width="800" height="600" xmlns="http://www.w3.org/2000/svg">
        <rect id="button-background" x="0" y="0" width="100" height="100" fill="green" />
        <text id="button-text" x="0" y="0" text-anchor="middle" font-size="20" font-family="arial" fill="black">Hello, Skia!</text>
    </svg>
    )";
    SkMemoryStream svgStream(svgText.c_str(), svgText.length(), true);
    _dom =  System::instance().makeSVGDOM(svgStream);
    _updates["x"] = "0.0";
    _updates["y"] = "0.0";
    _updates["width"] = "100.0";
    _updates["height"] = "100.0";
    SkSVGText 
    _dom->
    if (_dom->findNodeById("button-text")->get()->)
    {
        std::cout << "Found" << std::endl;
    }
}
BOUNT_UI_API Layer::~Layer()
{
    
}
BOUNT_UI_API void Layer::handleEvent(const GL::Event& event)
{
    if (_updates.size())
    {
        if (_updates.contains("x")) _collider->setX(_x);
        if (_updates.contains("y")) _collider->setY(_y);
        if (_updates.contains("width")) _collider->setWidth(_width);
        if (_updates.contains("height")) _collider->setHeight(_height);
    }

    switch (event.getSDLEvent().type)
    {
    case SDL_EVENT_MOUSE_MOTION:
    {
        auto& motion = event.getSDLEvent().motion;
        if (_collider->pointCollided(motion.x, motion.y))
        {
            event.handled();
            _dispatcher.fire("mouse entered", event);
        }
        break;
    }
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    {
        auto& button = event.getSDLEvent().button;
        if (_collider->pointCollided(button.x, button.y))
        {
            event.handled();
            _dispatcher.fire("pressed", event);
        }
        break;
    }
    }
}
BOUNT_UI_API void Layer::draw()
{
    if (_updates.size())
    {   
        auto button_bg_svg_ptr = _dom->findNodeById("button-background");
        if (button_bg_svg_ptr)
        {
            auto svg = button_bg_svg_ptr->get();
            if (_updates.contains("x")) svg->setAttribute("x", _updates["x"].c_str());
            if (_updates.contains("y")) svg->setAttribute("y", _updates["y"].c_str());
            if (_updates.contains("width")) svg->setAttribute("width", _updates["width"].c_str());
            if (_updates.contains("height")) svg->setAttribute("height", _updates["height"].c_str());
        }
        auto button_txt_svg_ptr = _dom->findNodeById("button-text");
        if (button_txt_svg_ptr)
        {
            auto svg = button_txt_svg_ptr->get();
            if (_updates.contains("x") || _updates.contains("width"))
            {
                std::stringstream ss;
                ss << (_x + _width/2.0f);
                svg->setAttribute("x", ss.str().c_str());
            }
            if (_updates.contains("y") || _updates.contains("height"))
            {
                std::stringstream ss;
                ss << (_y + _height/2.0f);
                svg->setAttribute("y", ss.str().c_str());
            }
        }
        _updates.clear();
    }
    _surface.clear(SK_ColorWHITE);
    _surface.drawSVGDOM(_dom);
    System::instance().getContext()->flush();
}
BOUNT_UI_API void Layer::setX(const float x)
{
    _x = x;
    std::stringstream ss;
    ss << _x;
    _updates["x"] = ss.str();
}
BOUNT_UI_API void Layer::setY(const float y)
{
    _y = y;
    std::stringstream ss;
    ss << _y;
    _updates["y"] = ss.str();
}
BOUNT_UI_API void Layer::setWidth(const float width)
{
    _width = width;
    std::stringstream ss;
    ss << _width;
    _updates["width"] = ss.str();
}
BOUNT_UI_API void Layer::setHeight(const float height)
{
    _height = height;
    std::stringstream ss;
    ss << _height;
    _updates["height"] = ss.str();
}
}