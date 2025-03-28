#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Polyline.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Polyline::Polyline()
{
}
BOUNT_SVG_API Polyline::~Polyline()
{
}
BOUNT_SVG_API Element::Type Polyline::getElementType() const
{
    return Type::Polyline;
}
}