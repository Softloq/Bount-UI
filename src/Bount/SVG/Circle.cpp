#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Circle.hpp"

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
typedef  boost::mpl::set<svgpp::tag::element::circle>::type ProcessedCircleElementsT;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::circle, svgpp::tag::attribute::cx>,
    boost::mpl::pair<svgpp::tag::element::circle, svgpp::tag::attribute::cy>,
    boost::mpl::pair<svgpp::tag::element::circle, svgpp::tag::attribute::r>
>::type ProcessedCircleAttributesT;

BOUNT_SVG_API Circle::Circle(File file)
{
    auto content = file.Content();
    
    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::ElementT element = doc.first_node("circle");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    CircleContext context;
    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedCircleElementsT>,
        svgpp::processed_attributes<ProcessedCircleAttributesT>,
        svgpp::attribute_traversal_policy<CircleAttributeTraversalPolicy>,
        svgpp::basic_shapes_policy<CircleShapePolicy>
    >::load_expected_element(element, context, svgpp::tag::element::circle());
}
BOUNT_SVG_API Circle::~Circle()
{
}
BOUNT_SVG_API Element::Type Circle::getElementType() const
{
    return Type::Circle;
}

BOUNT_SVG_API void CircleContext::set_circle(F64 cx, F64 cy, F64 r)
{
    std::cout << "Hello" << std::endl;
}
}