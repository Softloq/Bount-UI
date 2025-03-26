#include "Bount/UI/Collider.hpp"

namespace Bount::UI
{
BOUNT_UI_API Collider::~Collider()
{

}

BOUNT_UI_API BoxCollider::BoxCollider(float x, float y, float width, float height)
    : _x(x), _y(y)
    , _width(width), _height(height)
{

}
BOUNT_UI_API bool BoxCollider::pointCollided(float x, float y)
{
    return _x <= x && x <= _x + _width
       &&  _y <= y && y <= _y + _height;
}
}