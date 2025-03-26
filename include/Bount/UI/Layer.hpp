#ifndef BOUNT_UI_LAYER_HPP
#define BOUNT_UI_LAYER_HPP

#include "Bount/UI/Lib-Macro.hpp"
#include "Bount/UI/Surface.hpp"

#include <Bount/GL/Layer.hpp>

namespace Bount::UI
{
class Layer : public GL::Layer
{
    Surface _surface;
    sk_sp<SkSVGDOM> _dom;

public:
    BOUNT_UI_API Layer();
    BOUNT_UI_API ~Layer();

    BOUNT_UI_API void handleEvent(const GL::Event& event) override;
    BOUNT_UI_API void draw() override;
};
}

#endif