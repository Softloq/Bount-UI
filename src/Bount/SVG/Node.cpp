#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Node.hpp"

namespace Bount::SVG
{
BOUNT_SVG_API Node::~Node()
{
}

BOUNT_SVG_API Drawable::Drawable(GL::Shader::Program&& program)
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
BOUNT_SVG_API Drawable::~Drawable()
{

}

BOUNT_SVG_API void Drawable::draw()
{
    _shaderProgram.use();
    updateUniforms();
    _mesh.draw();
}

BOUNT_SVG_API void Drawable::updateUniforms()
{
}
}