#ifndef BOUNT_SVG_LINE_HPP
#define BOUNT_SVG_LINE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Line : public Element
{
public:
    BOUNT_SVG_API Line();
    BOUNT_SVG_API ~Line();
    BOUNT_SVG_API Type getElementType() const override;
};
}

#endif
