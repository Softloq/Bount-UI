#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Rectangle.hpp"
#include <Bount/SVG/Helpers/svgpp.hpp>

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
    : Drawable({{GL::Shader::Type::Vert, GL::Shader::File{"Resources/SVG/Shaders/Rectangle.vert"}},
                {GL::Shader::Type::Frag, GL::Shader::File{"Resources/SVG/Shaders/Rectangle.frag"}}})
{
    auto content = file.Content();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::ElementT element = doc.first_node("rect");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedRectangleElementsT>,
        svgpp::processed_attributes<ProcessedRectangleAttributesT>,
        svgpp::attribute_traversal_policy<RectangleAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<RectangleShapePolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::rect());
}
BOUNT_SVG_API Rectangle::~Rectangle()
{
}

BOUNT_SVG_API Element::Type Rectangle::getElementType() const
{
    return Type::Rectangle;
}

BOUNT_SVG_API void Rectangle::updateUniforms()
{
    if (_uniformChanges.empty()) return;
    if (_uniformChanges.contains("u_RectPos"))
    {
        _shaderProgram.setUniformFloat("u_RectPos", _x, _y);
    }
    if (_uniformChanges.contains("u_RectSize"))
    {
        _shaderProgram.setUniformFloat("u_RectSize", _width, _height);
    }
    if (_uniformChanges.contains("u_RectRadius"))
    {
        _shaderProgram.setUniformFloat("u_RectRadius", _rx, _ry);
    }
    _uniformChanges.clear();
}

BOUNT_SVG_API void Rectangle::set_rect(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _rx = rx;
    _ry = ry;
    _uniformChanges.insert("u_RectPos");
    _uniformChanges.insert("u_RectSize");
    _uniformChanges.insert("u_RectRadius");
}
BOUNT_SVG_API void Rectangle::set_rect(F32 x, F32 y, F32 width, F32 height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _shaderProgram.use();
    _uniformChanges.insert("u_RectPos");
    _uniformChanges.insert("u_RectSize");
}

BOUNT_SVG_API void Rectangle::set_radius(F32 rx, F32 ry)
{
    _rx = rx;
    _ry = ry;
    _uniformChanges.insert("u_RectRadius");
}
}