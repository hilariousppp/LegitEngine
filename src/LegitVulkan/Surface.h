#include <format>

namespace legit
{
//  struct WindowDesc
//  {
//    HINSTANCE hInstance;
//    HWND hWnd;
//  };

  static vk::UniqueSurfaceKHR CreateSurface(vk::Instance instance, GLFWwindow* window)
  {
	  VkSurfaceKHR surface;
	  VkResult err = glfwCreateWindowSurface(instance,window,nullptr,&surface);
      if ( err != VK_SUCCESS ) 
		  throw std::runtime_error( std::format("Failed to create surface! Error #{}", int64_t(err)) );
      vk::ObjectDestroy<vk::Instance, VULKAN_HPP_DEFAULT_DISPATCHER_TYPE> deleter(instance);
	  return vk::UniqueSurfaceKHR(surface,deleter);
  }
}
