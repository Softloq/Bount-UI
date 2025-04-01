#ifndef BOUNT_SVG_RECTANGLE_HPP
#define BOUNT_SVG_RECTANGLE_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include "Bount/SVG/Node.hpp"
#include "Bount/SVG/Helpers/File.hpp"
#include "Bount/SVG/Helpers/svgpp.hpp"
#include <Bount/GL/Shader.hpp>
#include <Bount/GL/Mesh.hpp>

namespace Bount::SVG
{
class Rectangle : public Element
{
    GL::Shader::Program _shaderProgram;
    GL::Mesh _mesh;

    F32 _width, _height, _x, _y, _rx, _ry;

public:
    BOUNT_SVG_API Rectangle(File file);
    BOUNT_SVG_API ~Rectangle();
    BOUNT_SVG_API Type getElementType() const override;

    BOUNT_SVG_API void draw();

    BOUNT_SVG_API void set(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry);
    BOUNT_SVG_API void set(F32 x, F32 y, F32 width, F32 height);

    BOUNT_SVG_API void setRadii(F32 rx, F32 ry);
};

struct RectangleContext : SVGPPContext
{
    BOUNT_SVG_API void set_rect(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry);
    BOUNT_SVG_API void set_rect(F32 x, F32 y, F32 width, F32 height);
};  
}

#endif
