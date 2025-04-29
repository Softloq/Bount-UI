#include <Bount/Subsystem/Generic.hpp>

import Bount.UI.Subsystem;
import Bount.SVG.Rectangle;
import Bount.SVG.Ellipse;
import Bount.SVG.Circle;
import Bount.Window.Subsystem;
import Bount.Graphics.Subsystem;
import Bount.Graphics.Layer;
import Bount.Event.Base;

using namespace Bount;

class ShapeLayer : public Graphics::Layer
{
    std::unique_ptr<SVG::Rectangle> rectangle;

public:
    ShapeLayer()
    {
        rectangle = std::unique_ptr<SVG::Rectangle>(new SVG::Rectangle(SVG::File("SVG/Examples/Rectangle1.svg")));
    }
    void handleEvent(const Event::Base& event) override
    {

    }
    void draw() override
    {
        rectangle->draw();
    }
};

int main(int argc, char* argv[])
{
    Graphics::Subsystem::getInstance().startup();
    UI::Subsystem::getInstance().startup();

    auto myShapeLayer = new ShapeLayer;
    Window::Subsystem::getInstance().getLayers().append(std::shared_ptr<Graphics::Layer>(myShapeLayer));

    Graphics::Subsystem::getInstance().runGameLoop();
    UI::Subsystem::getInstance().shutdown();
    Graphics::Subsystem::getInstance().shutdown();

    return 0;
}
