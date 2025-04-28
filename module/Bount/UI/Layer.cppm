module;

#include "Bount/UI/StandardMacros.hpp"
#include <unordered_map>

export module Bount.UI.Layer;

export import Bount.UI.Collider;
export import Bount.Graphics.Layer;
export import Bount.Event.Dispatcher;
export namespace Bount::UI
{
class Layer : public Graphics::Layer
{
    Event::Dispatcher _dispatcher;
    std::unique_ptr<BoxCollider> _collider;

public:
    BOUNT_UI_API Layer();
    BOUNT_UI_API ~Layer();

    BOUNT_UI_API void handleEvent(const Event::Base& event) override;
    BOUNT_UI_API void draw() override;

// UI Button Features
public:
    BOUNT_UI_API void setX(F32 x);
    BOUNT_UI_API void setY(F32 y);
    BOUNT_UI_API void setWidth(F32 width);
    BOUNT_UI_API void setHeight(F32 height);
    
private:
    std::unordered_map<String, String> _updates;
    F32 _x, _y, _width, _height;
};
}
