module;

#include "Bount/SVG/StandardMacros.hpp"
#include <unordered_set>
#include <memory>

export module Bount.SVG.Node;

import Bount.Graphics.Mesh; 
export import Bount.Graphics.Shader;
export namespace Bount::SVG
{
class Node
{
    std::weak_ptr<Node> _parent;

public:
    BOUNT_SVG_API virtual ~Node() noexcept = 0;
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

    BOUNT_SVG_API virtual Type getElementType() const noexcept = 0;
};
class Drawable : public Element
{
protected:
    Graphics::Shader::Program _shaderProgram;
    Graphics::Mesh _mesh;

    std::unordered_set<String> _uniformChanges;

public:
    BOUNT_SVG_API Drawable(Graphics::Shader::Program&& program);
    BOUNT_SVG_API ~Drawable() noexcept;

    BOUNT_SVG_API void draw() noexcept;

protected:
    BOUNT_SVG_API virtual void updateUniforms() noexcept = 0;
};
}
