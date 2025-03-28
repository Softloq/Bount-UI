#ifndef BOUNT_SVG_IMAGE_HPP
#define BOUNT_SVG_IMAGE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Image : public Element
{
public:
    BOUNT_SVG_API Image();
    BOUNT_SVG_API ~Image();
    BOUNT_SVG_API Type getElementType() const override;
};
}

#endif
