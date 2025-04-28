#include "Bount/UI/Precompiled.hpp"

import Bount.UI.Layer;

namespace Bount::UI
{
Layer::Layer()
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

    _updates["x"] = "0.0";
    _updates["y"] = "0.0";
    _updates["width"] = "100.0";
    _updates["height"] = "100.0";
}
Layer::~Layer()
{
    
}
void Layer::handleEvent(const Event::Base& event)
{

}
void Layer::draw()
{

}
void Layer::setX(F32 x)
{
    _x = x;
    std::stringstream ss;
    ss << _x;
    _updates["x"] = ss.str();
}
void Layer::setY(F32 y)
{
    _y = y;
    std::stringstream ss;
    ss << _y;
    _updates["y"] = ss.str();
}
void Layer::setWidth(F32 width)
{
    _width = width;
    std::stringstream ss;
    ss << _width;
    _updates["width"] = ss.str();
}
void Layer::setHeight(F32 height)
{
    _height = height;
    std::stringstream ss;
    ss << _height;
    _updates["height"] = ss.str();
}
}