#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.Image;

namespace Bount::SVG
{
Image::Image(const File& file)
{
}
Image::Image() noexcept
{
}
Image::~Image() noexcept
{
}
Element::Type Image::getElementType() const noexcept
{
    return Type::Image;
}
}