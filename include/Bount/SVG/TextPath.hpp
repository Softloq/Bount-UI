#ifndef BOUNT_SVG_TEXT_PATH_HPP
#define BOUNT_SVG_TEXT_PATH_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class TextPath : public Element
{
public:
    BOUNT_SVG_API TextPath();
    BOUNT_SVG_API ~TextPath();
    BOUNT_SVG_API Type getElementType() const override;
};
}

#endif
