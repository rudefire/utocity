#include "util.hpp"
#include <string>
#include "LineGraph.hpp"

static void error_callback(int error, const char* description)
{
  fputs(description, stderr);
}

LineGraph test_graph;
void Initialize();
void Render();

int main(int argc, char** argv)
{ 
  glfwSetErrorCallback(error_callback);
  if(!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  gl3wInit();

  ImGui_ImplGlfwGL3_Init(window, true);

  ImVec4 clear_color = ImColor(114, 144, 154);

  Initialize();

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    ImGui_ImplGlfwGL3_NewFrame();

    Render();
  
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    glfwSwapBuffers(window);
  }

  ImGui_ImplGlfwGL3_Shutdown();  
  glfwTerminate();

  return 0;
}

void Initialize()
{
  std::string graph_label = "Test Graph";
  std::string x_label = "X Axis";
  std::string y_label = "Y Axis";
  float x_scale = 1.0f;
  float y_scale = 1.0f;
  std::vector<double> x_values;
  std::vector<double> y_values;

  test_graph.Build(graph_label, x_label, y_label, x_scale, y_scale, x_values, y_values);
}

void Render()
{
  test_graph.Render();
}
