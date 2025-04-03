#ifndef BOUNT_SVG_TEXT_HPP
#define BOUNT_SVG_TEXT_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include "Bount/SVG/Helpers/File.hpp"
#include <svgpp/svgpp.hpp>

namespace Bount::SVG
{
class Text final : public Drawable
{
    String _text;
    
public:
    BOUNT_SVG_API Text(File file);
    BOUNT_SVG_API ~Text();

    BOUNT_SVG_API Type getElementType() const override;
    BOUNT_SVG_API void updateUniforms() override;

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

#endif
