#ifndef BOUNT_SVG_CIRCLE_HPP
#define BOUNT_SVG_CIRCLE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include "Bount/SVG/Helpers/File.hpp"

namespace Bount::SVG
{
class Circle final : public Drawable
{
    F32 _cx, _cy, _r;

public:
    BOUNT_SVG_API Circle(File file);
    BOUNT_SVG_API ~Circle();

    BOUNT_SVG_API Type getElementType() const override;
    BOUNT_SVG_API void updateUniforms() override;

    BOUNT_SVG_API void set_circle(F32 cx, F32 cy, F32 r);
};
}

#endif
