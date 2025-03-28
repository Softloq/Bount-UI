#ifndef BOUNT_UI_COLLIDER_HPP
#define BOUNT_UI_COLLIDER_HPP

#include "Bount/UI/Lib-Macro.hpp"

namespace Bount::UI
{
class Collider
{
public:
    BOUNT_UI_API virtual ~Collider() = 0;

    BOUNT_UI_API virtual bool pointCollided(float x, float y) const;
};
class BoxCollider : public Collider
{
    float _x, _y;
    float _width, _height;

public:
    BOUNT_UI_API BoxCollider(float x, float y, float width, float height);
    BOUNT_UI_API bool pointCollided(float x, float y) const override;

    BOUNT_UI_API void setX(float x);
    BOUNT_UI_API void setY(float y);
    BOUNT_UI_API void setWidth(float width);
    BOUNT_UI_API void setHeight(float height);
};
}

#endif