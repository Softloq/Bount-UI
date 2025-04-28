#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.TSpan;

namespace Bount::SVG
{
TSpan::TSpan(const File& file)
{
}
TSpan::TSpan() noexcept
{
}
TSpan::~TSpan() noexcept
{
}
Element::Type TSpan::getElementType() const noexcept
{
    return Type::TSpan;
}
}