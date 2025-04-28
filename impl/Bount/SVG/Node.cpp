#include "Bount/SVG/Precompiled.hpp"
#include <unordered_set>
#include <memory>

import Bount.SVG.Node;
import Bount.Graphics.Mesh; 
namespace Bount::SVG
{
Node::~Node()
{
}

Drawable::Drawable(Graphics::Shader::Program&& program)
    : _shaderProgram(std::move(program))
{
    _mesh.addVertices({
        {{-1.0f,  1.0f, 0.0f}}, // Top Left
        { {1.0f,  1.0f, 0.0f}}, // Top Right
        { {1.0f, -1.0f, 0.0f}}, // Bottom Right
        {{-1.0f, -1.0f, 0.0f}}  // Bottom Left
    });
    _mesh.addIndices({
        0, 1, 2,    
        2, 3, 0
    });
    _mesh.update();
}
Drawable::~Drawable() noexcept
{

}

void Drawable::draw() noexcept
{
    _shaderProgram.use();
    updateUniforms();
    _mesh.draw();
}

void Drawable::updateUniforms() noexcept
{
}
}