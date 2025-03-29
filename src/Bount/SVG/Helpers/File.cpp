#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Helpers/File.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API File::File(const String& path)
    : _path(path)
{
}
BOUNT_SVG_API File::~File()
{
}
}