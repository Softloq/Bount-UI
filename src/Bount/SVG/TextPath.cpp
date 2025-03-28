#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/TextPath.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API TextPath::TextPath()
{
}
BOUNT_SVG_API TextPath::~TextPath()
{
}
BOUNT_SVG_API Element::Type TextPath::getElementType() const
{
    return Type::TextPath;
}
}