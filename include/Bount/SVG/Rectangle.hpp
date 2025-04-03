#ifndef BOUNT_SVG_RECTANGLE_HPP
#define BOUNT_SVG_RECTANGLE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include "Bount/SVG/Helpers/File.hpp"

namespace Bount::SVG
{
class Rectangle final : public Drawable
{
    // Shape Attributes

    F32 _width, _height, _x, _y, _rx, _ry;

public:
    BOUNT_SVG_API Rectangle(File file);
    BOUNT_SVG_API ~Rectangle();

    BOUNT_SVG_API Type getElementType() const override;
    BOUNT_SVG_API void updateUniforms() override;

    BOUNT_SVG_API void set_rect(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry);
    BOUNT_SVG_API void set_rect(F32 x, F32 y, F32 width, F32 height);

    BOUNT_SVG_API void set_radius(F32 rx, F32 ry);
};
}

#endif
