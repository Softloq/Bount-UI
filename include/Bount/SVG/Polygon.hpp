#ifndef BOUNT_SVG_POLYGON_HPP
#define BOUNT_SVG_POLYGON_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Polygon : public Node
{
public:
    BOUNT_SVG_API Polygon();
    BOUNT_SVG_API ~Polygon();
};
}

#endif
