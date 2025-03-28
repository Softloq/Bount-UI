#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Circle.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Circle::Circle()
{
}
BOUNT_SVG_API Circle::~Circle()
{
}
BOUNT_SVG_API Element::Type Circle::getElementType() const
{
    return Type::Circle;
}
}