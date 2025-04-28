#include "Bount/UI/Precompiled.hpp"
#include "Bount/Subsystem/Generic.hpp"

import Bount.UI.Subsystem;
import Bount.Subsystem;

using namespace Bount;

BOUNT_UI_API UI::Subsystem& Singleton::Generic<UI::Subsystem>::getInstance() noexcept { BOUNT_SINGLETON_GET_INSTANCE_IMPL(UI::Subsystem); }

namespace Bount::UI
{
Subsystem::Subsystem() noexcept
{
}

Subsystem::~Subsystem() noexcept
{
}
    
void Subsystem::onStartup()
{
}
void Subsystem::onShutdown() noexcept
{
}
}
