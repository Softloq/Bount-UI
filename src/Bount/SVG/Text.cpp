#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Text.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Text::Text()
{
}
BOUNT_SVG_API Text::~Text()
{
}
BOUNT_SVG_API Element::Type Text::getElementType() const
{
    return Type::Text;
}
}