#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Rectangle.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Rectangle::Rectangle()
{
}
BOUNT_SVG_API Rectangle::~Rectangle()
{
}
BOUNT_SVG_API Element::Type Rectangle::getElementType() const
{
    return Type::Rectangle;
}
}