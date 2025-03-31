#ifndef BOUNT_SVG_CIRCLE_HPP
#define BOUNT_SVG_CIRCLE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include "Bount/SVG/Helpers/File.hpp"
#include "Bount/SVG/Helpers/svgpp.hpp"
#include <Bount/GL/Shader.hpp>
#include <Bount/GL/Mesh.hpp>

namespace Bount::SVG
{
class Circle : public Element
{
    GL::Shader::Program _shaderProgram;
    GL::Mesh _mesh;

public:
    BOUNT_SVG_API Circle(File file);
    BOUNT_SVG_API ~Circle();
    BOUNT_SVG_API Type getElementType() const override;

    BOUNT_SVG_API void draw();
};

struct CircleContext : SVGPPContext
{
    BOUNT_SVG_API void set_circle(F64 cx, F64 cy, F64 r);
};
}

#endif
