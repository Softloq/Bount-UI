#include <Bount/GL/Subsystem.hpp>
#include <Bount/GL/Layer.hpp>
#include <Bount/Window/Subsystem.hpp>
#include <Bount/UI/System.hpp>

#include <Bount/SVG/Ellipse.hpp>
#include <Bount/SVG/Circle.hpp>
#include <Bount/SVG/Rectangle.hpp>
#include <Bount/SVG/Text.hpp>

using namespace Bount;

class ShapeLayer : public GL::Layer
{
    std::unique_ptr<SVG::Rectangle> rectangle;

public:
    ShapeLayer()
    {
        rectangle = std::unique_ptr<SVG::Rectangle>(new SVG::Rectangle(SVG::File("SVG/Examples/Text1.svg")));
    }
    void handleEvent(const GL::Event& event) override
    {

    }
    void draw() override
    {
        rectangle->draw();
    }
};

int main(int argc, char* argv[])
{
    Window::Subsystem::getInstance();
    GL::Subsystem::getInstance();

    // Initialization
    GL::Subsystem::getInstance().startup();
    UI::System::instance().initialize();

    // Setup
    auto myShapeLayer = new ShapeLayer;
    Window::Subsystem::getInstance().getLayers().append(std::shared_ptr<GL::Layer>(myShapeLayer));

    // Run
    GL::Subsystem::getInstance().runGameLoop();

    // Cleanup
    UI::System::instance().shutdown();
    GL::Subsystem::getInstance().shutdown();
    
    return 0;
}
