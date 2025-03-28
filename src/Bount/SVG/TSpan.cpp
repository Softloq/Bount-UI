#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/TSpan.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API TSpan::TSpan()
{
}
BOUNT_SVG_API TSpan::~TSpan()
{
}
BOUNT_SVG_API Element::Type TSpan::getElementType() const
{
    return Type::TSpan;
}
}