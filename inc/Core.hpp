#pragma once

class GLFWwindow;

class Core
{
  public:
    Core();
    ~Core();

    bool Initialize();
    void Run();
    bool Shutdown();

  private:
    GLFWwindow* window = nullptr;

    void Render();
};
