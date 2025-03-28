#ifndef BOUNT_SVG_POLYLINE_HPP
#define BOUNT_SVG_POLYLINE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Polyline : public Node
{
public:
    BOUNT_SVG_API Polyline();
    BOUNT_SVG_API ~Polyline();
};
}

#endif
