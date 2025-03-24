#ifndef BOUNT_UI_SVG_LAYER_HPP
#define BOUNT_UI_SVG_LAYER_HPP

#include "Bount/UI/Lib-Macro.hpp"
#include <Bount/GL/Layer.hpp>

#include <modules/svg/include/SkSVGDOM.h>

namespace Bount::UI
{
class SVGLayer : public GL::Layer
{
    sk_sp<SkSVGDOM> _dom;

public:
    BOUNT_UI_API SVGLayer();
    BOUNT_UI_API ~SVGLayer();

    BOUNT_UI_API void handleEvent() override;
    BOUNT_UI_API void draw() override;
};
}

#endif