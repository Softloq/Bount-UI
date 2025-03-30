#ifndef BOUNT_SVG_HELPERS_SVGPP_HPP
#define BOUNT_SVG_HELPERS_SVGPP_HPP

#include "Bount/SVG/Lib-Macro.hpp"
#include <rapidxml_ns/rapidxml_ns.hpp>
#include <rapidxml_ns/rapidxml_ns_utils.hpp>
#include <svgpp/policy/xml/rapidxml_ns.hpp>
#include <svgpp/svgpp.hpp>


namespace Bount::XML
{
typedef rapidxml_ns::xml_document<> Doc;
typedef rapidxml_ns::xml_node<> const * ElementT;
}

#endif
