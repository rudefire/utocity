#include "LineGraph.hpp"
#include "util.hpp"

//Local helper functions

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
  graph_width = window_width / 2.f;
  graph_height = window_width / 2.f;
}

void LineGraph::Render()
{
  bool opened;
  ImGui::Begin(graph_label.c_str(), &opened, {window_width, window_height}); 
  GraphRender();
  TextRender();
  ScaleRender();
  ImGui::End();
}

void LineGraph::TextRender()
{
  ImGui::SetCursorPos({5, graph_height/2.f});
  ImGui::Text("Y");
  ImGui::SetCursorPos({graph_width/2.f,graph_height+5.f});
  ImGui::Text("X");
  ImGui::SetCursorPos({5, 225});
  std::string y_label_temp = "Y: " + y_label;
  ImGui::Text(y_label_temp.c_str());
  ImGui::SetCursorPos({5, 240});
  std::string x_label_temp = "X: " + x_label;
  ImGui::Text(x_label_temp.c_str());
}
void LineGraph::PointRender()
{

}

void LineGraph::GraphRender()
{
  ImGui::SetCursorPos({0,0});
  ImVec4 col{1.0f, 1.0f, 1.0f, 1.0f};
  ImU32 col32 = ImColor(col);
  ImVec2 point = ImGui::GetCursorScreenPos();
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  draw_list->AddLine({point.x+20,point.y+30}, {point.x+20,point.y+graph_height}, col32);
  draw_list->AddLine({point.x+20,point.y+graph_height}, 
      {point.x+graph_width,point.y+graph_height}, col32);
}

void LineGraph::ScaleRender()
{
  float x_div = graph_width / x_granularity;
  float y_div = graph_height / y_granularity;
  float x_dif_height = 3.f;
  float y_dif_width = 10.f;
  ImVec4 color{1.f, 1.f, 1.f, 1.f};
  ImU32 color32 = ImColor(color);
  ImGui::SetCursorPos({0,0});
  ImVec2 point = ImGui::GetCursorScreenPos();
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  float height = point.y;
  for(size_t iter = 0; iter < y_granularity; iter++)
  {
    draw_list->AddLine({point.x + 20 - y_dif_width/2.f, height}, 
        {point.x + 20 + y_dif_width/2.f, height}, color32);
    height += y_div;
  }
}
