#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.Path;

namespace Bount::SVG
{
Path::Path(const File& file)
{

}
Path::Path() noexcept
{
}
Path::~Path() noexcept
{
}
Element::Type Path::getElementType() const noexcept
{
    return Type::Path;
}
}