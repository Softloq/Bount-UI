module;

#include "Bount/SVG/StandardMacros.hpp"
#include <svgpp/svgpp.hpp>

export module Bount.SVG.Text;

import Bount.SVG.Node;
export import Bount.SVG.File;
export namespace Bount::SVG
{
class Text final : public Drawable
{
    String _text;
    
public:
    BOUNT_SVG_API Text(const File& file);
    BOUNT_SVG_API Text() noexcept;
    BOUNT_SVG_API ~Text() noexcept;

    BOUNT_SVG_API Type getElementType() const noexcept override;
    BOUNT_SVG_API void updateUniforms() noexcept override;

    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::x, const Range& value);
    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::y, const Range& value);
    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::dx, const Range& value);
    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::dy, const Range& value);

    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::rotate, const Range& value);

    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::textLength, const Range& value);
    template <class Range>
    BOUNT_SVG_API void set(svgpp::tag::attribute::lengthAdjust, const Range& value);

    template <class Range>
    BOUNT_SVG_API void set_text(const Range& text);
};
}
