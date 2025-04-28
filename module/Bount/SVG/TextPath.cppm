module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.TextPath;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class TextPath final : public Element
{
public:
    BOUNT_SVG_API TextPath(const File& file);
    BOUNT_SVG_API TextPath() noexcept;
    BOUNT_SVG_API ~TextPath() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
};
}
