#pragma once

// SD - Screen Drawing

#if defined ( __WIN32 ) || ( __WIN32__ ) || ( __MINGW32__ )
  #define SD_WIN32
#else
  #error "Unsupported platform"
#endif

#if defined ( SD_DYNAMIC_LINKING ) // Assumindo que usaremos so windows por enquanto
  #if defined ( SD_WIN32 )
    #define SD_API __declspec(dllexport)
  #else
    #error "Unsupported platform"
  #endif
#else
  #define SD_API
#endif

#define SD_NORETURN    [[noreturn]]
#define SD_FALLTHROUGH [[fallthrough]]
#define SD_UNUSED      [[maybe_unused]]
#define SD_NODISCARD   [[nodiscard]]

#define SD_APPLICATION_NAME "Screen Drawing"

#define SD_NAMESPACE sd

namespace SD_NAMESPACE
{
  #if defined ( NDEBUG )
    constexpr bool g_SDallowDebug = true;
  #else
    constexpr bool g_SDallowDebug = false;
  #endif
}