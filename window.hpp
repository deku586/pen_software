#include "base_defs.hpp"
#include "sd_error.hpp"

#include <string>

namespace SD_NAMESPACE
{
  class Window
  {
    private:
      std::string m_windowName;

    public:
      ~ Window ();
      Window ( std::string const & windowName = SD_APPLICATION_NAME );

      ErrorCode Start ( std::string const & windowName = SD_APPLICATION_NAME );
  };
}
