#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Ellipse.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Ellipse::Ellipse()
{
}
BOUNT_SVG_API Ellipse::~Ellipse()
{
}
BOUNT_SVG_API Element::Type Ellipse::getElementType() const
{
    return Type::Ellipse;
}
}