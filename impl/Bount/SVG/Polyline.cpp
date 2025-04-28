#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.Polyline;

namespace Bount::SVG
{
Polyline::Polyline(const File& file)
{
}
Polyline::Polyline() noexcept
{
}
Polyline::~Polyline() noexcept
{
}
Element::Type Polyline::getElementType() const noexcept
{
    return Type::Polyline;
}
}