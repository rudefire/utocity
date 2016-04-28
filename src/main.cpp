#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw_gl3.h"
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
  fputs(description, stderr);
}

void ImGuiFunc();

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

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    ImGui_ImplGlfwGL3_NewFrame();

    ImGuiFunc();
  
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

void ImGuiFunc()
{
  float progress = .5f;
  ImGui::SetNextWindowSize({(float)(640/2), (float)(480/2)});
  ImGui::Begin("Test Area", NULL);
  ImGui::ProgressBar(progress);
  ImGui::End();
}
