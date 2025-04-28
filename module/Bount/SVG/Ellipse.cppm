module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Ellipse;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Ellipse final : public Drawable
{
    F32 _cx, _cy;
    F32 _rx, _ry;

public:
    BOUNT_SVG_API Ellipse(const File& file);
    BOUNT_SVG_API Ellipse() noexcept;
    BOUNT_SVG_API ~Ellipse() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
    BOUNT_SVG_API void updateUniforms() noexcept override;

    BOUNT_SVG_API void set_ellipse(F32 cx, F32 cy, F32 rx, F32 ry) noexcept;
};
}
