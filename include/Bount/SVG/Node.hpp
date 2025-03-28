#ifndef BOUNT_SVG_NODE_HPP
#define BOUNT_SVG_NODE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include <memory>

namespace Bount::SVG
{
class Root;

class Node
{
    std::weak_ptr<Root> _root;
    std::weak_ptr<Node> _parent;

public:
    BOUNT_SVG_API virtual ~Node() = 0;
};
}

#endif
