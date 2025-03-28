#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Line.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Line::Line()
{
}
BOUNT_SVG_API Line::~Line()
{
}
BOUNT_SVG_API Element::Type Line::getElementType() const
{
    return Type::Line;
}
}