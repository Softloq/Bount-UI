#ifndef BOUNT_SVG_TEXT_HPP
#define BOUNT_SVG_TEXT_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Text : public Node
{
public:
    BOUNT_SVG_API Text();
    BOUNT_SVG_API ~Text();
};
}

#endif
