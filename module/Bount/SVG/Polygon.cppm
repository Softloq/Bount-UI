module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.Polygon;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Polygon final : public Element
{
public:
    BOUNT_SVG_API Polygon(const File& file);
    BOUNT_SVG_API Polygon() noexcept;
    BOUNT_SVG_API ~Polygon() noexcept;
    
    BOUNT_SVG_API Type getElementType() const noexcept override;
};
}
