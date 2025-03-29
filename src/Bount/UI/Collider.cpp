#include "Bount/UI/Precompiled.hpp"
#include "Bount/UI/Collider.hpp"

namespace Bount::UI
{
BOUNT_UI_API Collider::~Collider()
{

}

BOUNT_UI_API bool Collider::pointCollided(float x, float y) const
{
    return false;
}

BOUNT_UI_API BoxCollider::BoxCollider(float x, float y, float width, float height)
    : _x(x), _y(y)
    , _width(width), _height(height)
{

}
BOUNT_UI_API bool BoxCollider::pointCollided(float x, float y) const
{
    return _x <= x && x <= _x + _width
       &&  _y <= y && y <= _y + _height;
}
BOUNT_UI_API void BoxCollider::setX(float x)
{
    _x = x;
}
BOUNT_UI_API void BoxCollider::setY(float y)
{
    _y = y;
}
BOUNT_UI_API void BoxCollider::setWidth(float width)
{
    _width = width;
}
BOUNT_UI_API void BoxCollider::setHeight(float height)
{
    _height = height;
}
}