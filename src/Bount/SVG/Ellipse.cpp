#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Ellipse.hpp"
#include "Bount/SVG/Helpers/svgpp.hpp"

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
typedef  boost::mpl::set<svgpp::tag::element::ellipse>::type ProcessedEllipseElementsT;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::cx>,
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::cy>,
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::rx>,
    boost::mpl::pair<svgpp::tag::element::ellipse, svgpp::tag::attribute::ry>
>::type ProcessedEllipseAttributesT;

BOUNT_SVG_API Ellipse::Ellipse(File file)
    : Drawable({{GL::Shader::Type::Vert, GL::Shader::File{"Resources/SVG/Shaders/Ellipse.vert"}},
                {GL::Shader::Type::Frag, GL::Shader::File{"Resources/SVG/Shaders/Ellipse.frag"}}})
{
    auto content = file.Content();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::ElementT element = doc.first_node("ellipse");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedEllipseElementsT>,
        svgpp::processed_attributes<ProcessedEllipseAttributesT>,
        svgpp::attribute_traversal_policy<EllipseAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<EllipseShapePolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::ellipse());
}
BOUNT_SVG_API Ellipse::~Ellipse()
{
}

BOUNT_SVG_API Element::Type Ellipse::getElementType() const
{
    return Type::Ellipse;
}

BOUNT_SVG_API void Ellipse::updateUniforms()
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

BOUNT_SVG_API void Ellipse::set_ellipse(F32 cx, F32 cy, F32 rx, F32 ry)
{
    _cx = cx;
    _cy = cy;
    _rx = rx;
    _ry = ry;
    _uniformChanges.insert("u_EllipsePos");
    _uniformChanges.insert("u_EllipseRadius");
}
}