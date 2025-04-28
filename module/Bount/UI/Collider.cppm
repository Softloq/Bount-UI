module;

#include "Bount/UI/StandardMacros.hpp"

export module Bount.UI.Collider;

export namespace Bount::UI
{
class Collider
{
public:
    BOUNT_UI_API virtual ~Collider() = 0;
    BOUNT_UI_API virtual Bool pointCollided(F32 x, F32 y) const;
};

class BoxCollider : public Collider
{
    F32 _x, _y;
    F32 _width, _height;

public:
    BOUNT_UI_API BoxCollider(F32 x, F32 y, F32 width, F32 height);
    BOUNT_UI_API Bool pointCollided(F32 x, F32 y) const override;

    BOUNT_UI_API void setX(F32 x);
    BOUNT_UI_API void setY(F32 y);
    BOUNT_UI_API void setWidth(F32 width);
    BOUNT_UI_API void setHeight(F32 height);
};
}
