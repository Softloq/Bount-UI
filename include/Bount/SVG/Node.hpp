#ifndef BOUNT_SVG_NODE_HPP
#define BOUNT_SVG_NODE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include <Bount/GL/Shader.hpp>
#include <Bount/GL/Mesh.hpp>
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

    BOUNT_SVG_API virtual Type getElementType() const = 0;
};
class Drawable : public Element
{
protected:
    GL::Shader::Program _shaderProgram;
    GL::Mesh _mesh;

public:
    BOUNT_SVG_API Drawable(GL::Shader::Program&& program);
    BOUNT_SVG_API ~Drawable();

    BOUNT_SVG_API virtual void draw() = 0;
};
}

#endif
