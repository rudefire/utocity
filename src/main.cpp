#include "util.hpp"
#include <string>
#include "Core.hpp"

int main(int argc, char** argv)
{ 
  Core core;
  core.Initialize();
  core.Run();
  core.Shutdown();
  return 0;
}

