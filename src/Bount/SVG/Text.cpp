#include "Bount/UI/Precompiled.hpp"
#include "Bount/SVG/Text.hpp"
#include "Bount/SVG/Helpers/svgpp.hpp"

namespace Bount::SVG
{
struct TextAttributeTraversalPolicy : svgpp::policy::attribute_traversal::default_policy
{
    static const bool parse_style = false;
    static const bool css_hides_presentation_attribute = true;

    typedef boost::mpl::quote1<svgpp::traits::element_required_attributes> get_required_attributes_by_element;
};
typedef  boost::mpl::set<svgpp::tag::element::text>::type ProcessedTextElementsT;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::x>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::y>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::dx>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::dy>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::rotate>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::textLength>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::lengthAdjust>
>::type ProcessedTextAttributesT;

BOUNT_SVG_API Text::Text(File file)
    : Drawable({{GL::Shader::Type::Vert, GL::Shader::File{"Resources/SVG/Shaders/Ellipse.vert"}},
                {GL::Shader::Type::Frag, GL::Shader::File{"Resources/SVG/Shaders/Ellipse.frag"}}})
{
    auto content = file.Content();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::ElementT element = doc.first_node("text");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedTextElementsT>,
        svgpp::processed_attributes<ProcessedTextAttributesT>,
        svgpp::attribute_traversal_policy<TextAttributeTraversalPolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::text());
}
BOUNT_SVG_API Text::~Text()
{
}

BOUNT_SVG_API Element::Type Text::getElementType() const
{
    return Type::Text;
}
BOUNT_SVG_API void Text::updateUniforms()
{

}

template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::x, const Range& value)
{

}
template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::y, const Range& value)
{

}
template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::dx, const Range& value)
{
    
}
template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::dy, const Range& value)
{

}

template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::rotate, const Range& value)
{

}

template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::textLength, const Range& value)
{

}
template <class Range>
BOUNT_SVG_API void Text::set(svgpp::tag::attribute::lengthAdjust, const Range& value)
{
    
}

template <class Range>
BOUNT_SVG_API void Text::set_text(const Range& text)
{
    _text.append(boost::begin(text), boost::end(text));
    std::cout << "Text: " << _text << std::endl;
}
}