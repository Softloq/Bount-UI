#include "Bount/UI/Precompiled.hpp"
#include "Bount/UI/System.hpp"

namespace Bount::UI
{
System* System::_instance = nullptr;
std::once_flag System::_init;
BOUNT_UI_API System& System::instance()
{
    std::call_once(_init, []()
    {
        _instance = new System;
    });
    return *_instance;
}
BOUNT_UI_API System::System()
{
}
BOUNT_UI_API System::~System()
{
}
BOUNT_UI_API bool System::initialize()
{
    return true;
}
BOUNT_UI_API void System::shutdown()
{

}
}