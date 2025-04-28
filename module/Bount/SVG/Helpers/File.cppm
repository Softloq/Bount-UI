module;

#include "Bount/SVG/Helpers/File.hpp"
#include <fstream>

export module Bount.SVG.File;
export namespace Bount::SVG
{
class File final
{
    std::ifstream _file;

public:
    BOUNT_SVG_API File(const String& path) noexcept;
    BOUNT_SVG_API ~File() noexcept = default;

    BOUNT_SVG_API std::vector<Char> getContent() const noexcept;
};
}
