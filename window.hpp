#include "base_defs.hpp"
#include "sd_error.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#if defined ( SD_WIN32 )
  #define GLFW_EXPOSE_NATIVE_WIN32 // Expoe funções especificas do windows no GLFW, não sei se vamos usar mas deixa ai por enqunato qulauqer coisa remove
  #include <GLFW/glfw3native.h>
#else
  #error "Unsupported platform"
#endif

#include <string>

namespace SD_NAMESPACE
{
  void WindowErrorCallback ( int error, char const * message ); // Callback de Error ( caso algo aconteça uma info no terminal vai aparecer )

  void WindowLoad(); // Carregar a lib GLFW

  class Window
  {
    private: // Isso precisa ser privado? Considerar mover para public.
      GLFWwindow * m_windowPtr;

      std::string m_windowName;

    public:
      ~ Window ();
      Window ( std::string const & windowName = SD_APPLICATION_NAME ); // Default parameter, pode ser removido

      Code Create ( std::string const & windowName = SD_APPLICATION_NAME );
  };
}
