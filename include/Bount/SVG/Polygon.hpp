#ifndef BOUNT_SVG_POLYGON_HPP
#define BOUNT_SVG_POLYGON_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Polygon : public Element
{
public:
    BOUNT_SVG_API Polygon();
    BOUNT_SVG_API ~Polygon();
    BOUNT_SVG_API Type getElementType() const override;
};
}

#endif
