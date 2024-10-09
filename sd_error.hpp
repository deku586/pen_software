#include "base_defs.hpp"

namespace SD_NAMESPACE
{
  enum ErrorCode
  {
    eNoError,
    eUnsupportedPixelSize,
    eUnsupportedScreenSize,
    eUnsupportedGPU,
    eUnsupportedFeature,
    eOutOfMemory,
    eUnknownError
  };

  char const * ErrorCodeToString ( ErrorCode code ) noexcept;

  bool CheckResult ( ErrorCode code );
}
