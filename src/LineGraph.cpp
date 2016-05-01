#include "LineGraph.hpp"
#include "util.hpp"

LineGraph::LineGraph()
{

}

LineGraph::~LineGraph()
{
  
}

void LineGraph::Build(std::string graph_l, std::string x_l, std::string y_l,
        float x_s, float y_s, std::vector<double> x_vals, std::vector<double> y_vals)
{
  graph_label = graph_l;
  x_label = x_l;
  y_label = y_l;
  x_scale = x_s;
  y_scale = y_s;
  x_values = x_vals;
  y_values = y_vals;
}

void LineGraph::Render()
{
  bool opened;
  ImVec4 col{1.0f, 1.0f, 1.0f, 1.0f};
  ImU32 col32 = ImColor(col);
  ImGui::Begin(graph_label.c_str(), &opened, {320, 240}); 
  ImGui::SetCursorPos({0,0});
  ImVec2 point = ImGui::GetCursorScreenPos();
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  draw_list->AddLine({point.x+20,point.y+30}, {point.x+20,point.y+200}, col32);
  draw_list->AddLine({point.x+20,point.y+200}, {point.x+200,point.y+200}, col32);
  ImGui::SetCursorPos({5, 100});
  ImGui::Text("X");
  ImGui::SetCursorPos({100,205});
  ImGui::Text("Y");
  ImGui::SetCursorPos({5, 225});
  std::string x_label_temp = "X: " + x_label;
  ImGui::Text(x_label_temp.c_str());
  ImGui::End();
}
