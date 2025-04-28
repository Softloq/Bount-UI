module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Rectangle;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Rectangle final : public Drawable
{
    F32 _width, _height;
    F32 _x, _y;
    F32 _rx, _ry;

public:
    BOUNT_SVG_API Rectangle(const File& file);
    BOUNT_SVG_API Rectangle() noexcept;
    BOUNT_SVG_API ~Rectangle() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
    BOUNT_SVG_API void updateUniforms() noexcept override;

    BOUNT_SVG_API void set_rect(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry) noexcept;
    BOUNT_SVG_API void set_rect(F32 x, F32 y, F32 width, F32 height) noexcept;

    BOUNT_SVG_API void set_radius(F32 rx, F32 ry) noexcept;
};
}
