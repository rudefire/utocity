#include "LineGraph.hpp"
#include "util.hpp"
#include "Colors.hpp"
#include <sstream>

ImVec2 origin;

LineGraph::LineGraph()
{

}

LineGraph::~LineGraph()
{
  
}

void LineGraph::Build(std::string graph_l, std::string x_l, std::string y_l,
        float y_s, std::vector<float> y_vals, int x_divs)
{
  graph_label = graph_l;
  x_label = x_l;
  y_label = y_l;
  y_scale = y_s;
  y_values = y_vals;
  x_divisions = x_divs;
  graph_width = window_width - 100.f;
  graph_height = window_width - 100.f;
}

void LineGraph::Rebuild()
{
  graph_width = window_width - 100.f;
  graph_height = window_width - 100.f;
}

void LineGraph::Render()
{
  bool opened;
  ImGui::Begin(graph_label.c_str(), &opened, {window_width, window_height}); 
  CalculateOrigin();
  ScaleRender();
  GraphRender();
  PointRender();
  TextRender();
  ImVec2 size = ImGui::GetWindowSize();
  if(window_width != size.x)
    Rebuild();
  ImGui::End();
}

void LineGraph::CalculateOrigin()
{
  ImVec2 offset{50, 30};
  ImVec2 cursor_position = ImGui::GetCursorScreenPos();
  origin = {cursor_position.x + offset.x, cursor_position.y + graph_height};
}

void LineGraph::TextRender()
{
  ImGui::SetCursorPos({10, window_height - 40});
  ImGui::BeginChild("Label Descriptions", {window_width-10, 40}, false);
  std::string label_temp = "Y: " + y_label + '\n' + "X: " + x_label;
  ImGui::Text(label_temp.c_str());
  ImGui::EndChild();
}

void LineGraph::PointRender()
{
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  float x_div = graph_width / x_granularity;
  float y_div = graph_height / y_granularity;
  int x_offset = 0;
  ImVec2 previous_point;
  for(size_t iter = 0; iter < y_values.size(); iter++)
  {
    ImVec2 offset({x_div * x_offset, y_div * y_values[iter]});
    ImVec2 point({origin.x + offset.x, origin.y - offset.y});
    draw_list->AddCircleFilled(point, 5.f, red);
    if(0 != iter)
      draw_list->AddLine(point, previous_point, red);
    x_offset++;
    previous_point = point;
  }
}

void LineGraph::GraphRender()
{
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  draw_list->AddLine({origin.x,origin.y}, {origin.x,origin.y-graph_height}, white);
  draw_list->AddLine({origin.x,origin.y}, 
      {origin.x+graph_width,origin.y}, white);
}

void LineGraph::ScaleRender()
{
  float x_div = graph_width / x_divisions;
  float y_div = graph_height / y_granularity;
  float x_dif_height = 10.f;
  float y_dif_width = 10.f;
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  float height = origin.y;
  int x_offset = 0;
  for(size_t iter = 0; iter <= y_granularity; iter++)
  {
    draw_list->AddLine({origin.x - y_dif_width, height}, 
        {origin.x, height}, white);
    char buffer[10];
    sprintf(buffer, "%.0f", y_scale * iter);
    ImVec2 text_size = ImGui::CalcTextSize(buffer);
    ImGui::SetCursorScreenPos({origin.x - text_size.x - 15.f, height});
    ImGui::Text(buffer);
    draw_list->AddLine({origin.x, height}, 
        {origin.x + graph_width, height}, light_grey);
    height -= y_div;
  }

  float width = origin.x;
  int time_scale = 0;
  for(size_t iter = 0; iter <= x_granularity; iter++)
  {
    draw_list->AddLine({width, origin.y},
        {width, origin.y + x_dif_height}, white);
    char buffer[10];
    sprintf(buffer, "%d", time_scale);
    ImVec2 text_size = ImGui::CalcTextSize(buffer);
    ImGui::SetCursorScreenPos({width, origin.y + text_size.y});
    ImGui::Text(buffer);
    width += x_div;
    time_scale++;
  }
}
