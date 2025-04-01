#ifndef BOUNT_SVG_ELLIPSE_HPP
#define BOUNT_SVG_ELLIPSE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include "Bount/SVG/Helpers/File.hpp"
#include "Bount/SVG/Helpers/svgpp.hpp"
#include <Bount/GL/Shader.hpp>
#include <Bount/GL/Mesh.hpp>

namespace Bount::SVG
{
class Ellipse : public Element
{
    GL::Shader::Program _shaderProgram;
    GL::Mesh _mesh;

    F32 _cx, _cy, _rx, _ry;

public:
    BOUNT_SVG_API Ellipse(File file);
    BOUNT_SVG_API ~Ellipse();
    BOUNT_SVG_API Type getElementType() const override;

    BOUNT_SVG_API void draw();

    BOUNT_SVG_API void set(F32 cx, F32 cy, F32 rx, F32 ry);
};

struct EllipseContext : SVGPPContext
{
    BOUNT_SVG_API void set_ellipse(F32 cx, F32 cy, F32 rx, F32 ry);
};
}

#endif
