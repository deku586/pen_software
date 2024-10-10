#pragma once

// SD - Screen Drawing

#if defined ( _WIN32 ) // Pode ser expandido de forma que, qualquer compilação compativel com win32 seja aceita, entao pode condicionar partes do codigo com base no valor definido SD_WIN32
  #define SD_WIN32
#else
  #error "Unsupported platform"
#endif

#if defined ( SD_DYNAMIC_LINKING ) // Assumindo que usaremos so windows por enquanto, será usado para compilar as DLL
  #if defined ( SD_WIN32 )
    #define SD_API __declspec(dllexport)
  #else
    #error "Unsupported platform"
  #endif
#else
  #define SD_API
#endif

#define SD_NORETURN    [[noreturn]]     // Indica que uma função não tem retorno ( uma função que pode dar throw exception )
#define SD_FALLTHROUGH [[fallthrough]]  // Evita avisos do compilador indicando que a queda no switch é intencional
#define SD_UNUSED      [[maybe_unused]] // Indica que um valor ( parametro, retorno de função...) pode ser descartado/ignorado
#define SD_NODISCARD   [[nodiscard]]    // Indica que um valor não deve ser ignorado ( retorno de função )

#define SD_APPLICATION_NAME "Screen Drawing"

#define SD_NAMESPACE sd

namespace SD_NAMESPACE
{
  #if defined ( NDEBUG ) // NDEBUG = Sem debug. Se a gente compilar em modo de debugging ( fase de desenvolvimento, teste, etc.. ) a gente pode usar essa variavel global como condição de algo ( por exemplo printar informacao na tela, executar partes de codigos diferentes como debug callbacks ).
    constexpr bool g_SDallowDebug = true;
  #else
    constexpr bool g_SDallowDebug = false;
  #endif
}