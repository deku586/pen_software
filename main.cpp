#include "app.hpp"

#include <stdexcept>
#include <iostream>

int main ( int argc, char const ** argv )
{
  SD_NAMESPACE::Application app;

  try
  {
    app.Run():
  }
  catch ( std::exception const & e )
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}