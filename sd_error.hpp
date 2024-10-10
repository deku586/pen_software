#include "base_defs.hpp"

namespace SD_NAMESPACE
{
  enum Code
  {
    // Success
    eSuccess,
    
    // Errors
    eWindowCreationFail,
    eUnsupportedPixelSize,
    eUnsupportedScreenSize,
    eUnsupportedGPU,
    eUnsupportedFeature,
    eOutOfMemory,
    eUnknownError,

    // Placeholder
    ePlaceholder
  };

  char const * ErrorCodeToString ( Code code ) noexcept; // Noexcept indica ao compilador q a função não vai dar throw em nenhuma exception, cmo eu sei disso? a função vai retornar um ponteiro para uma string imutavel, que sera armazenada no executavel ou em uma dll, então n vai dar um ponteiro nulo ou outro tipo de erro que daria com uma std::tring caso não conseguisse alocar memoria

  // Isso deve ser mudado, ou usaremos exceptions ou cuidaremos do return baseados no Code.
  // Como já planejo usar o VulkanHPP, por padrão em pontos críticos ele dar exceptions, agora isso pode ser
  // desativado se nós quisermos usar a checagem do valor retornado
  #if defined ( SD_CHECK_RESULT_THROW )
  bool CheckResult ( Code code );
  #else
  SD_NORETURN bool CheckResult ( Code code ); // O noreturn vai quebrar o fluxo do programa, se um error acontecer, se não me engano o código para mesmo dando catch em exception, por causa desse atributo.
  #endif
}
