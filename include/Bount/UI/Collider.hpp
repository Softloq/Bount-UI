#ifndef BOUNT_UI_COLLIDER_HPP
#define BOUNT_UI_COLLIDER_HPP

#include "Bount/UI/Lib-Macro.hpp"

namespace Bount::UI
{
class Collider
{
public:
    BOUNT_UI_API virtual ~Collider() = 0;
};
class BoxCollider : public Collider
{
    float _x, _y;
    float _width, _height;

public:
    BOUNT_UI_API BoxCollider(float x, float y, float width, float height);
    BOUNT_UI_API bool pointCollided(float x, float y);
};
}

#endif