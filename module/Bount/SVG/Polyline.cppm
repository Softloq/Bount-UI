module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Polyline;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Polyline final : public Element
{
public:
    BOUNT_SVG_API Polyline(const File& file);
    BOUNT_SVG_API Polyline() noexcept;
    BOUNT_SVG_API ~Polyline() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
};
}
