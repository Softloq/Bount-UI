#ifndef BOUNT_SVG_TEXT_SPAN_HPP
#define BOUNT_SVG_TEXT_SPAN_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class TSpan : public Element
{
public:
    BOUNT_SVG_API TSpan();
    BOUNT_SVG_API ~TSpan();
    BOUNT_SVG_API Type getElementType() const override;
};
typedef TSpan TextSpan;
typedef TSpan Span; 
}

#endif
