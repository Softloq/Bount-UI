#include "Bount/SVG/Precompiled.hpp"
#include "Bount/SVG/Helpers/File.hpp"

import Bount.SVG.Ellipse;

namespace Bount::SVG
{
struct EllipseAttributeTraversalPolicy : svgpp::policy::attribute_traversal::default_policy
{
    static const bool parse_style = false;
    static const bool css_hides_presentation_attribute = true;

    typedef boost::mpl::quote1<svgpp::traits::element_required_attributes> get_required_attributes_by_element;
};
struct EllipseShapePolicy
{
    typedef boost::mpl::set<>::type convert_to_path;
    typedef boost::mpl::set<svgpp::tag::element::ellipse>::type collect_attributes;

    static const bool convert_only_rounded_rect_to_path = false;
};
typedef  boost::mpl::set<svgpp::tag::element::ellipse>::type ProcessedEllipseElements;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::cx>,
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::cy>,
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::rx>,
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::ry>
>::type ProcessedEllipseAttributes;

Ellipse::Ellipse(const File& file)
    : _cx(0.0f), _cy(0.0f)
    , _rx(0.0f), _ry(0.0f)
    , Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Ellipse.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Ellipse.frag"}}})
{
    auto content = file.getContent();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::Element element = doc.first_node("ellipse");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedEllipseElements>,
        svgpp::processed_attributes<ProcessedEllipseAttributes>,
        svgpp::attribute_traversal_policy<EllipseAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<EllipseShapePolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::ellipse());
}
Ellipse::Ellipse() noexcept
    : _cx(0.0f), _cy(0.0f)
    , _rx(0.0f), _ry(0.0f)
    , Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Ellipse.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Ellipse.frag"}}})
{
}

Ellipse::~Ellipse() noexcept
{
}

Element::Type Ellipse::getElementType() const noexcept
{
    return Type::Ellipse;
}

void Ellipse::updateUniforms() noexcept
{
    if (_uniformChanges.empty()) return;
    if (_uniformChanges.contains("u_EllipsePos"))
    {
        _shaderProgram.setUniformFloat("u_EllipsePos", _cx, _cy);
    }
    if (_uniformChanges.contains("u_EllipseRadius"))
    {
        _shaderProgram.setUniformFloat("u_EllipseRadius", _rx, _ry);
    }
    _uniformChanges.clear();
}

void Ellipse::set_ellipse(F32 cx, F32 cy, F32 rx, F32 ry) noexcept
{
    _cx = cx;
    _cy = cy;
    _rx = rx;
    _ry = ry;
    _uniformChanges.insert("u_EllipsePos");
    _uniformChanges.insert("u_EllipseRadius");
}
}