#ifndef BOUNT_SVG_ELLIPSE_HPP
#define BOUNT_SVG_ELLIPSE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Ellipse : public Node
{
public:
    BOUNT_SVG_API Ellipse();
    BOUNT_SVG_API ~Ellipse();
};
}

#endif
