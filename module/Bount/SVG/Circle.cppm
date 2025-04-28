module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Circle;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Circle final : public Drawable
{
    F32 _cx, _cy;
    F32 _r;

public:
    BOUNT_SVG_API Circle(const File& file);
    BOUNT_SVG_API Circle() noexcept;
    BOUNT_SVG_API ~Circle() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
    BOUNT_SVG_API void updateUniforms() noexcept override;

    BOUNT_SVG_API void set_circle(F32 cx, F32 cy, F32 r) noexcept;
};
}
