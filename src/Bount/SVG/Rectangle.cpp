#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Rectangle.hpp"

namespace Bount::SVG
{
struct RectangleAttributeTraversalPolicy : svgpp::policy::attribute_traversal::default_policy
{
    static const bool parse_style = false;
    static const bool css_hides_presentation_attribute = true;

    typedef boost::mpl::quote1<svgpp::traits::element_required_attributes> get_required_attributes_by_element;
};
struct RectangleShapePolicy
{
    typedef boost::mpl::set<>::type convert_to_path;
    typedef boost::mpl::set<svgpp::tag::element::rect>::type collect_attributes;

    static const bool convert_only_rounded_rect_to_path = false;
};
typedef  boost::mpl::set<svgpp::tag::element::rect>::type ProcessedRectangleElementsT;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::x>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::y>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::width>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::height>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::rx>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::ry>
>::type ProcessedRectangleAttributesT;
BOUNT_SVG_API Rectangle::Rectangle(File file)
: _shaderProgram{
    {GL::Shader::Type::Vert, GL::Shader::File{"Resources/SVG/Shaders/Rectangle.vert"}},
    {GL::Shader::Type::Frag, GL::Shader::File{"Resources/SVG/Shaders/Rectangle.frag"}}}
{
    _mesh.addVertices({
        { {-1.0f, 1.0f, 0.0f}}, // Top Left
        {  {1.0f, 1.0f, 0.0f}}, // Top Right
        { {1.0f, -1.0f, 0.0f}}, // Bottom Right
        {{-1.0f, -1.0f, 0.0f}}  // Bottom Left
    });
    _mesh.addIndices({
        0, 1, 2,    
        2, 3, 0
    });
    _mesh.update();

    auto content = file.Content();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::ElementT element = doc.first_node("rect");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    RectangleContext context;
    context.node = this;
    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedRectangleElementsT>,
        svgpp::processed_attributes<ProcessedRectangleAttributesT>,
        svgpp::attribute_traversal_policy<RectangleAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<RectangleShapePolicy>
    >::load_expected_element(element, context, svgpp::tag::element::rect());
}
BOUNT_SVG_API Rectangle::~Rectangle()
{
}
BOUNT_SVG_API Element::Type Rectangle::getElementType() const
{
    return Type::Rectangle;
}
BOUNT_SVG_API void Rectangle::draw()
{
    _shaderProgram.use();
    _mesh.draw();
}

BOUNT_SVG_API void Rectangle::set(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _rx = rx;
    _ry = ry;
    _shaderProgram.use();
    _shaderProgram.setUniformFloat("u_RectPos", _x, _y);
    _shaderProgram.setUniformFloat("u_RectSize", _width, _height);
    _shaderProgram.setUniformFloat("u_RectRadius", _rx, _ry);
}
BOUNT_SVG_API void Rectangle::set(F32 x, F32 y, F32 width, F32 height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _shaderProgram.use();
    _shaderProgram.setUniformFloat("u_RectPos", _x, _y);
    _shaderProgram.setUniformFloat("u_RectSize", _width, _height);
}

BOUNT_SVG_API void Rectangle::setRadii(F32 rx, F32 ry)
{
    _rx = rx;
    _ry = ry;
    _shaderProgram.use();
    _shaderProgram.setUniformFloat("u_RectRadius", _rx, _ry);
}

BOUNT_SVG_API void RectangleContext::set_rect(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry)
{
    static_cast<Rectangle*>(node)->set(x, y, width, height, rx, ry);
}
BOUNT_SVG_API void RectangleContext::set_rect(F32 x, F32 y, F32 width, F32 height)
{
    static_cast<Rectangle*>(node)->set(x, y, width, height);
}
}