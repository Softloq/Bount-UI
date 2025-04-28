#include "Bount/SVG/Precompiled.hpp"
#include "Bount/SVG/Helpers/File.hpp"

import Bount.SVG.Rectangle;

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
typedef  boost::mpl::set<svgpp::tag::element::rect>::type ProcessedRectangleElements;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::x>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::y>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::width>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::height>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::rx>,
    boost::mpl::pair<svgpp::tag::element::rect, svgpp::tag::attribute::ry>
>::type ProcessedRectangleAttributes;
Rectangle::Rectangle(const File& file)
    : _width(0.0f), _height(0.0f)
    , _x(0.0f), _y(0.0f)
    , Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Rectangle.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Rectangle.frag"}}})
{
    auto content = file.getContent();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::Element element = doc.first_node("rect");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedRectangleElements>,
        svgpp::processed_attributes<ProcessedRectangleAttributes>,
        svgpp::attribute_traversal_policy<RectangleAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<RectangleShapePolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::rect());
}
Rectangle::Rectangle() noexcept
    : _width(0.0f), _height(0.0f)
    , _x(0.0f), _y(0.0f)
    , Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Rectangle.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Rectangle.frag"}}})
{
}
Rectangle::~Rectangle() noexcept
{
}

Element::Type Rectangle::getElementType() const noexcept
{
    return Type::Rectangle;
}

void Rectangle::updateUniforms() noexcept
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

void Rectangle::set_rect(F32 x, F32 y, F32 width, F32 height, F32 rx, F32 ry) noexcept
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
void Rectangle::set_rect(F32 x, F32 y, F32 width, F32 height) noexcept
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _shaderProgram.use();
    _uniformChanges.insert("u_RectPos");
    _uniformChanges.insert("u_RectSize");
}

void Rectangle::set_radius(F32 rx, F32 ry) noexcept
{
    _rx = rx;
    _ry = ry;
    _uniformChanges.insert("u_RectRadius");
}
}