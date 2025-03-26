#ifndef BOUNT_UI_LAYER_HPP
#define BOUNT_UI_LAYER_HPP

#include "Bount/UI/Lib-Macro.hpp"
#include <Bount/GL/Layer.hpp>

#include <modules/svg/include/SkSVGDOM.h>

namespace Bount::UI
{
class Layer : public GL::Layer
{
    sk_sp<SkSVGDOM> _dom;

public:
    BOUNT_UI_API Layer();
    BOUNT_UI_API ~Layer();

    BOUNT_UI_API void handleEvent(const GL::Event& event) override;
    BOUNT_UI_API void draw() override;
};
}

#endif