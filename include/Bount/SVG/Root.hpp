#ifndef BOUNT_SVG_ROOT_HPP
#define BOUNT_SVG_ROOT_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include <memory>

namespace Bount::SVG
{
class Root : public Node
{
public:
    BOUNT_SVG_API Root();
    BOUNT_SVG_API ~Root();
};
}

#endif
