#include "Core.hpp"
#include "util.hpp"
#include "Colors.hpp"
#include <vector>
#include "LineGraph.hpp"

//temp
LineGraph temp_graph;

static void error_callback(int error, const char* description)
{
  fputs(description, stderr);
}

Core::Core()
{

}

Core::~Core()
{

}

bool Core::Initialize()
{
  glfwSetErrorCallback(error_callback);
  if(!glfwInit())
    return false;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(1280, 720, "Simple example", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window);
  gl3wInit();

  ImGui_ImplGlfwGL3_Init(window, true);

  std::vector<float> temp{1,2,3,4,5};
  
  temp_graph.Build("graph", "X", "Y", 10, temp, 20);

  return true;
}

void Core::Run()
{
  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    Render();
  }
}

bool Core::Shutdown()
{
  bool success = true;
 
  ImGui_ImplGlfwGL3_Shutdown();  
  glfwTerminate();
  
  return success;
}

void Core::Render()
{
  ImGui_ImplGlfwGL3_NewFrame();

  ImVec4 clear_color = ImColor(light_grey);
  int display_w, display_h;
  glfwGetFramebufferSize(window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);

  RunMenuBar();
  //temp
  temp_graph.Render();

  ImGui::Render();
  glfwSwapBuffers(window);
}

void Core::InitMenuBar()
{
  
}

void Core::RunMenuBar()
{
  ImGui::BeginMainMenuBar();
  if (ImGui::BeginMenu("File"))
  {
    if(ImGui::MenuItem("New")){}
    if(ImGui::BeginMenu("Open"))
    {
      ImGui::MenuItem("Latest file");
      ImGui::EndMenu();
    }
    ImGui::EndMenu();
  }
  ImGui::EndMainMenuBar();
}
