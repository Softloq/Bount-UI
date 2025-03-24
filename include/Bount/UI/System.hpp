#ifndef BOUNT_UI_SYSTEM_HPP
#define BOUNT_UI_SYSTEM_HPP

#include "Bount/UI/Lib-Macro.hpp"

#include <include/core/SkSurface.h>
#include <include/core/SkCanvas.h>

#include <mutex>

namespace Bount::UI
{
class System
{
    static System* _instance;
    static std::once_flag _init;

    sk_sp<GrDirectContext> _context;
    sk_sp<SkSurface> _surface;

public:
    BOUNT_UI_API System(const System&) = delete;
    BOUNT_UI_API System& operator=(const System&) = delete;
    
    BOUNT_UI_API static System& instance();
    
    BOUNT_UI_API bool initialize();
    BOUNT_UI_API void shutdown();

    BOUNT_UI_API SkCanvas* const getCanvas() const;
    BOUNT_UI_API void clear();

private:
    BOUNT_UI_API System();
    BOUNT_UI_API ~System();
};
}

#endif