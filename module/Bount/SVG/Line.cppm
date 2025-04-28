module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Line;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Line final : public Element
{
public:
    BOUNT_SVG_API Line(const File& file);
    BOUNT_SVG_API Line() noexcept;
    BOUNT_SVG_API ~Line() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
};
}
