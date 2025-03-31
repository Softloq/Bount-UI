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

class Element : public Node
{
public:
    enum class Type
    {
        Circle,
        Ellipse,
        Rectangle,
        Image,
        Line,
        Path,
        Polygon,
        Polyline,
        Text,
        TextPath,
        TSpan
    };
    BOUNT_SVG_API Element();
    BOUNT_SVG_API ~Element();

    BOUNT_SVG_API virtual Type getElementType() const = 0;
};

/** Base Context for the svg++ parser. */
struct SVGPPContext
{
    /** Node that this context will update. */
    Node* node;
};
}

#endif
