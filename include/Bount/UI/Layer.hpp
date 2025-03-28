#ifndef BOUNT_UI_LAYER_HPP
#define BOUNT_UI_LAYER_HPP

#include "Bount/UI/Lib-Macro.hpp"
#include "Bount/UI/Surface.hpp"
#include "Bount/UI/Collider.hpp"

#include <Bount/GL/Layer.hpp>

#include <unordered_map>

namespace Bount::UI
{
class Layer : public GL::Layer
{
    GL::EventDispatcher _dispatcher;
    std::unique_ptr<BoxCollider> _collider;
    Surface _surface;
    sk_sp<SkSVGDOM> _dom;

public:
    BOUNT_UI_API Layer();
    BOUNT_UI_API ~Layer();

    BOUNT_UI_API void handleEvent(const GL::Event& event) override;
    BOUNT_UI_API void draw() override;

// UI Button Features
public:
    BOUNT_UI_API void setX(const float x);
    BOUNT_UI_API void setY(const float y);
    BOUNT_UI_API void setWidth(const float width);
    BOUNT_UI_API void setHeight(const float height);
    
private:
    std::unordered_map<std::string, std::string> _updates;
    float _x, _y, _width, _height;
};
}

#endif