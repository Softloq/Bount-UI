#ifndef BOUNT_SVG_SVGPLUSPLUS_RapidXML_HPP
#define BOUNT_SVG_SVGPLUSPLUS_RapidXML_HPP

#include <rapidxml_ns/rapidxml_ns.hpp>
#include <rapidxml_ns/rapidxml_ns_utils.hpp>
#include <svgpp/policy/xml/rapidxml_ns.hpp>

namespace Bount::XML
{
using Doc = rapidxml_ns::xml_document<>;
using Element = rapidxml_ns::xml_node<> const *;
}

#endif
