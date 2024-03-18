# CMakeList.txt : CMake project for clothsimulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (clothsimulation "main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET clothsimulation PROPERTY CXX_STANDARD 20)
endif()

if(NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "VCPKG not found. Set the VCPKG_ROOT environment variable.")
endif()

set(VCPKG_DIR "$ENV{VCPKG_ROOT}")

message(STATUS "$ENV{VCPKG_ROOT}=${$ENV{VCPKG_ROOT}}")

set(CMAKE_TOOLCHAIN_FILE VCPKG_DIR/scripts/buildsystems/vcpkg.cmake)

set(Eigen3_DIR vendors/packages/eigen3_x64-windows/share/eigen3)
set(glm_DIR vendors/packages/glm_x64-windows/share/glm)
set(GLEW_DIR vendors/packages/glew_x64-windows/share/glew)
set(glfw3_DIR vendors/packages/glfw3_x64-windows/share/glfw3)
set(imgui_DIR vendors/packages/imgui_x64-windows/share/imgui)

# TODO: Add tests and install targets if needed.
  find_package(glm CONFIG REQUIRED)
  target_link_libraries(clothsimulation PRIVATE glm::glm)
  find_package(GLEW REQUIRED)
  target_link_libraries(clothsimulation PRIVATE GLEW::GLEW)
  find_package(glfw3 CONFIG REQUIRED)
  target_link_libraries(clothsimulation PRIVATE glfw)
  find_package(imgui CONFIG REQUIRED)
  target_link_libraries(clothsimulation PRIVATE imgui::imgui)
  find_package(Eigen3 CONFIG REQUIRED)
  target_link_libraries(clothsimulation PRIVATE Eigen3::Eigen)

  # Adds vendors, textures, shaders
	target_include_directories(clothsimulation PRIVATE vendors)
	target_include_directories(clothsimulation PRIVATE textures)
	target_include_directories(clothsimulation PRIVATE shaders)

   target_sources(clothsimulation PRIVATE
   Camera.cpp
   Camera.h
   Cloth.cpp
   Cloth.h
   VBuffer.cpp
   VBuffer.h
   IBuffer.cpp
   IBuffer.h
   Renderer.cpp
   Renderer.h
   Shader.cpp
   Shader.h
   Texture.cpp
   Texture.h
   VArray.cpp
   VArray.h
   VBuffer.cpp
   VBuffer.h
   VBufferLayout.cpp
   VBufferLayout.h
   vendors/stb_image.cpp
   vendors/stb_image.h
   textures/basketball.png
   textures/cloth.png
   shaders/Basic.shader
)