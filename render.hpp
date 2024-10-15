#include "base_defs.hpp"

#define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC
#include <vulkan/vulkan.hpp>

namespace SD_NAMESPACE
{
  class Engine
  {
    private:
      vk::Instance       m_vkInstance;
      
      vk::PhysicalDevice m_gpu;
      vk::Device         m_device;
    
    private:
      void findGraphicsDevice();

    private:
      void createInstance();

      void createDevice();
    
    public:
      void init();
  };
}
