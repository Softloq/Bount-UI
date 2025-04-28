#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.TextPath;

namespace Bount::SVG
{
TextPath::TextPath(const File& file)
{
}
TextPath::TextPath() noexcept
{
}
TextPath::~TextPath() noexcept
{
}
Element::Type TextPath::getElementType() const noexcept
{
    return Type::TextPath;
}
}