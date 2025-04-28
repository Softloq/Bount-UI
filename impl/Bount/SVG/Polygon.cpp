#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.Polygon;

namespace Bount::SVG
{
Polygon::Polygon(const File& file)
{
}
Polygon::Polygon() noexcept
{
}
Polygon::~Polygon() noexcept
{
}
Element::Type Polygon::getElementType() const noexcept
{
    return Type::Polygon;
}
}