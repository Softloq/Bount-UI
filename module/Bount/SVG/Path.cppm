module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Path;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Path final : public Element
{
public:
    BOUNT_SVG_API Path(const File& file);
    BOUNT_SVG_API Path() noexcept;
    BOUNT_SVG_API ~Path() noexcept;
    
    BOUNT_SVG_API Type getElementType() const noexcept override;
};
}
