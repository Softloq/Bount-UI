#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Polygon.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Polygon::Polygon()
{
}
BOUNT_SVG_API Polygon::~Polygon()
{
}
BOUNT_SVG_API Element::Type Polygon::getElementType() const
{
    return Type::Polygon;
}
}