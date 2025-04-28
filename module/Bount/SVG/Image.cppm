module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Image;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Image final : public Element
{
public:
    BOUNT_SVG_API Image(const File& file);
    BOUNT_SVG_API Image() noexcept;
    BOUNT_SVG_API ~Image() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
};
}
