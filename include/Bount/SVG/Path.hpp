#ifndef BOUNT_SVG_PATH_HPP
#define BOUNT_SVG_PATH_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Path : public Element
{
public:
    BOUNT_SVG_API Path();
    BOUNT_SVG_API ~Path();
    BOUNT_SVG_API Type getElementType() const override;
};
}

#endif
