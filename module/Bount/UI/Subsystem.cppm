module;

#include "Bount/UI/StandardMacros.hpp"
#include "Bount/Subsystem/Generic.hpp"

export module Bount.UI.Subsystem;

import Bount.Subsystem;
export namespace Bount::UI
{
/** @brief
 * Standard UI Subsystem. 
 * Manages UI-based resources and global operations.
 */
class Subsystem final : public Bount::Subsystem::Generic<UI::Subsystem>
{
    BOUNT_UI_API Subsystem() noexcept;
    BOUNT_UI_API ~Subsystem() noexcept;

public:
    friend class Bount::Subsystem::Generic<UI::Subsystem>;
    friend class Bount::Singleton::Generic<UI::Subsystem>;

    BOUNT_UI_API void onStartup() override;
    BOUNT_UI_API void onShutdown() noexcept override;
};
}
