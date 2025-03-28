#ifndef BOUNT_SVG_TEXT_SPAN_HPP
#define BOUNT_SVG_TEXT_SPAN_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class TSpan : public Node
{
public:
    BOUNT_SVG_API TSpan();
    BOUNT_SVG_API ~TSpan();
};
typedef TSpan TextSpan;
typedef TSpan Span; 
}

#endif
