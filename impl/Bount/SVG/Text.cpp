#include "Bount/SVG/Precompiled.hpp"

import Bount.SVG.Text;

namespace Bount::SVG
{
struct TextAttributeTraversalPolicy : svgpp::policy::attribute_traversal::default_policy
{
    static const bool parse_style = false;
    static const bool css_hides_presentation_attribute = true;

    typedef boost::mpl::quote1<svgpp::traits::element_required_attributes> get_required_attributes_by_element;
};
typedef  boost::mpl::set<svgpp::tag::element::text>::type ProcessedTextElements;
typedef boost::mpl::set<
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::x>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::y>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::dx>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::dy>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::rotate>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::textLength>,
    boost::mpl::pair<svgpp::tag::element::text, svgpp::tag::attribute::lengthAdjust>
>::type ProcessedTextAttributes;

Text::Text(const File& file)
    : Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Ellipse.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Ellipse.frag"}}})
{
    auto content = file.getContent();

    XML::Doc doc;
    doc.parse<0>(&content[0]);
    XML::Element element = doc.first_node("text");
    if (!element)
    {
        std::cerr << "Bad element." << std::endl;
        return;
    }

    svgpp::document_traversal<
        svgpp::processed_elements<ProcessedTextElements>,
        svgpp::processed_attributes<ProcessedTextAttributes>,
        svgpp::attribute_traversal_policy<TextAttributeTraversalPolicy>
    >::load_expected_element(element, *this, svgpp::tag::element::text());
}
Text::Text() noexcept
    : Drawable({{Graphics::Shader::Type::Vert, Graphics::Shader::File{"SVG/Shaders/Ellipse.vert"}},
                {Graphics::Shader::Type::Frag, Graphics::Shader::File{"SVG/Shaders/Ellipse.frag"}}})
{
}
Text::~Text() noexcept
{
}

Element::Type Text::getElementType() const noexcept
{
    return Type::Text;
}
void Text::updateUniforms() noexcept
{

}

template <class Range>
void Text::set(svgpp::tag::attribute::x, const Range& value)
{

}
template <class Range>
void Text::set(svgpp::tag::attribute::y, const Range& value)
{

}
template <class Range>
void Text::set(svgpp::tag::attribute::dx, const Range& value)
{
    
}
template <class Range>
void Text::set(svgpp::tag::attribute::dy, const Range& value)
{

}

template <class Range>
void Text::set(svgpp::tag::attribute::rotate, const Range& value)
{

}

template <class Range>
void Text::set(svgpp::tag::attribute::textLength, const Range& value)
{

}
template <class Range>
void Text::set(svgpp::tag::attribute::lengthAdjust, const Range& value)
{
    
}

template <class Range>
void Text::set_text(const Range& text)
{
    _text.append(boost::begin(text), boost::end(text));
    std::cout << "Text: " << _text << std::endl;
}
}