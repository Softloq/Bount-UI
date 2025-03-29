#ifndef BOUNT_UI_SYSTEM_HPP
#define BOUNT_UI_SYSTEM_HPP

#include "Bount/UI/Lib-Macro.hpp"
#include <mutex>

namespace Bount::UI
{
class System
{
    static System* _instance;
    static std::once_flag _init;

public:
    BOUNT_UI_API System(const System&) = delete;
    BOUNT_UI_API System& operator=(const System&) = delete;
    
    BOUNT_UI_API static System& instance();
    
    BOUNT_UI_API bool initialize();
    BOUNT_UI_API void shutdown();

private:
    BOUNT_UI_API System();
    BOUNT_UI_API ~System();
};
}

#endif