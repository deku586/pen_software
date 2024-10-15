#include "window.hpp"

#include <iostream>
#include <cstdlib>
#include <stdexcept>

namespace SD_NAMESPACE
{
  void WindowErrorCallback ( int error, char const * message )
  {
    std::cerr << "[GLFW ERROR]: " << "Code " << error << " - Message: " << message << "\n";
  }


  void WindowLoad()
  {
    glfwSetErrorCallback ( WindowErrorCallback );

    if ( glfwInit() == GLFW_FALSE )
    {
      std::exit ( EXIT_FAILURE ); // exit finaliza o programa de forma natural ( diferente de assert e exception )
    }

    std::atexit ( glfwTerminate ); // atexit chama a função chamada por parametro no final do programa. fazendo assim essa função ter um sistema "parecido" com o RAII, terminando o GLFW automaticamente.
  }


  void Window::create ( std::string const & windowName )
  {
    GLFWmonitor * primaryMonitor = glfwGetPrimaryMonitor(); // pega o monitor principal
  
    if ( primaryMonitor == nullptr )
    {
      throw std::runtime_error ( "Could get information about the main display" );
    }

    GLFWvidmode const * videoMode = glfwGetVideoMode ( primaryMonitor ); // pega a resolucao

    if ( videoMode == nullptr )
    {
      throw std::runtime_error ( "Could get information about the main display" );
    }

    glfwWindowHint ( GLFW_CLIENT_API, GLFW_NO_API ); // indica que a gente nao vai usar OpenGL
    glfwWindowHint ( GLFW_RESIZABLE , GLFW_TRUE   ); // a janela poderá mudar de resolucao e tamanho

    m_windowPtr = glfwCreateWindow ( videoMode->width, videoMode->height, windowName.c_str(), nullptr, nullptr );

    if ( m_windowPtr == nullptr )
    {
      throw std::runtime_error ( "Window creation has failed" );
    }

    return Code::eSuccess;
  }
}