module;

#include "Bount/SVG/StandardMacros.hpp"

export module Bount.SVG.TSpan;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class TSpan final : public Element
{
public:
    BOUNT_SVG_API TSpan(const File& file);
    BOUNT_SVG_API TSpan() noexcept;
    BOUNT_SVG_API ~TSpan() noexcept;
    
    BOUNT_SVG_API Type getElementType() const noexcept override;
};
using TextSpan = TSpan;
using Span = TSpan; 
}
