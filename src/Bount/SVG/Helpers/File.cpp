#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Helpers/File.hpp"
#include "Bount/Core/Filesystem.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API File::File(const String& path)
    : _path(path)
{
    _path = Core::Filesystem::BinPath(path);
    _file = std::unique_ptr<std::ifstream>(new std::ifstream(_path.c_str()));
}
BOUNT_SVG_API File::~File()
{
}
BOUNT_SVG_API std::vector<Char> File::Content() const
{
    if (!(_file && _file->is_open())) return {'\0'};
    
    std::vector<Char> buffer((std::istreambuf_iterator<Char>(*_file)), std::istreambuf_iterator<Char>());
    buffer.push_back('\0');
    return buffer;
}
}