#include "Bount/UI/Precompiled.hpp"

import Bount.UI.Collider;

namespace Bount::UI
{
Collider::~Collider()
{

}

bool Collider::pointCollided(float x, float y) const
{
    return false;
}

BoxCollider::BoxCollider(float x, float y, float width, float height)
    : _x(x), _y(y)
    , _width(width), _height(height)
{

}
bool BoxCollider::pointCollided(float x, float y) const
{
    return _x <= x && x <= _x + _width
       &&  _y <= y && y <= _y + _height;
}
void BoxCollider::setX(float x)
{
    _x = x;
}
void BoxCollider::setY(float y)
{
    _y = y;
}
void BoxCollider::setWidth(float width)
{
    _width = width;
}
void BoxCollider::setHeight(float height)
{
    _height = height;
}
}