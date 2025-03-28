#ifndef BOUNT_SVG_IMAGE_HPP
#define BOUNT_SVG_IMAGE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
class Image : public Node
{
public:
    BOUNT_SVG_API Image();
    BOUNT_SVG_API ~Image();
};
}

#endif
