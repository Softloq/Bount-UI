#include "Bount/SVG/Precompiled.hpp"
#include "Bount/SVG/Helpers/File.hpp"

import Bount.SVG.Circle;

namespace Bount::SVG
{
struct CircleAttributeTraversalPolicy : svgpp::policy::attribute_traversal::default_policy
{
    static const bool parse_style = false;
    static const bool css_hides_presentation_attribute = true;

    typedef boost::mpl::quote1<svgpp::traits::element_required_attributes> get_required_attributes_by_element;
};
struct CircleShapePolicy
{
    typedef boost::mpl::set<>::type convert_to_path;
    typedef boost::mpl::set<svgpp::tag::element::circle>::type collect_attributes;

    static const bool convert_only_rounded_rect_to_path = false;
};
typedef  boost::mpl::set<svgpp::tag::element::circle>::type ProcessedCircleElements;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::circle, svgpp::tag::attribute::cx>,
    boost::mpl::pair<svgpp::tag::element::circle, svgpp::tag::attribute::cy>,
    boost::mpl::pair<svgpp::tag::element::circle, svgpp::tag::attribute::r>
>::type ProcessedCircleAttributes;

Circle::Circle(const File& file)
    : _cx(0.0f), _cy(0.0f)
    , _r(0.0f)
    , Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Circle.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Circle.frag"}}})
{
    auto content = file.getContent();
    
    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::Element element = doc.first_node("circle");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedCircleElements>,
        svgpp::processed_attributes<ProcessedCircleAttributes>,
        svgpp::attribute_traversal_policy<CircleAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<CircleShapePolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::circle());
}
Circle::Circle() noexcept
    : _cx(0.0f), _cy(0.0f)
    , _r(0.0f)
    , Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Circle.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Circle.frag"}}})
{
}
Circle::~Circle() noexcept
{
}

Element::Type Circle::getElementType() const noexcept
{
    return Type::Circle;
}

void Circle::updateUniforms() noexcept
{
    if (_uniformChanges.empty()) return;
    if (_uniformChanges.contains("u_CirclePos"))
    {
        _shaderProgram.setUniformFloat("u_CirclePos", _cx, _cy);
    }
    if (_uniformChanges.contains("u_CircleRadius"))
    {
        _shaderProgram.setUniformFloat("u_CircleRadius", _r);
    }
    _uniformChanges.clear();
}

void Circle::set_circle(F32 cx, F32 cy, F32 r) noexcept
{
    _cx = cx;
    _cy = cy;
    _r = r;
    _uniformChanges.insert("u_CirclePos");
    _uniformChanges.insert("u_CircleRadius");
}
}