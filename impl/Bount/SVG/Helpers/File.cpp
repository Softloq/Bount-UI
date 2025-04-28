#include "Bount/SVG/Precompiled.hpp"
#include "Bount/SVG/Helpers/File.hpp"
#include <fstream>
#include <sstream>

import Bount.SVG.File;
import Bount.Filesystem;

namespace Bount::SVG
{
File::File(const String& path) noexcept
{
    auto pathString = Filesystem::Path(Filesystem::Path::Base::Resources, path).toString();
    _file = std::ifstream(pathString.c_str());
}
std::vector<Char> File::getContent() const noexcept
{
    if (!_file.is_open()) return {'\0'};
    std::stringstream ss;
    ss << _file.rdbuf();
    std::string content = ss.str();
    return std::vector<Char>(content.begin(), content.end());
}
}