#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.Line;

namespace Bount::SVG
{
Line::Line(const File& file)
{
}
Line::Line() noexcept
{
}
Line::~Line() noexcept
{
}
Element::Type Line::getElementType() const noexcept
{
    return Type::Line;
}
}