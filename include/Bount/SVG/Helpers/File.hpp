#ifndef BOUNT_SVG_HELPERS_FILE_HPP
#define BOUNT_SVG_HELPERS_FILE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include <memory>
#include <fstream>
#include <vector>

namespace Bount::SVG
{
class File
{
    std::unique_ptr<std::ifstream> _file; 
    String _path;

public:
    BOUNT_SVG_API File(const String& path);
    BOUNT_SVG_API ~File();

    BOUNT_SVG_API std::vector<Char> Content() const;
};
}

#endif
