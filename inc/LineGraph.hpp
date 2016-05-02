#pragma once

#include <string>
#include <vector>

class LineGraph
{
  public:
    LineGraph();
    ~LineGraph();

    void Build(std::string graph_l, std::string x_l, std::string y_l,
        float x_s, float y_s, std::vector<double> x_vals, std::vector<double> y_vals);
    void Render();
    void TextRender();
    void PointRender();
    void GraphRender();
    void ScaleRender();


  private:
    std::string graph_label, x_label, y_label;    
    float x_scale, y_scale;
    std::vector<double> x_values;
    std::vector<double> y_values;
    float window_width = 320, window_height = 240;
    float graph_height, graph_width;
    float x_granularity = 10.f, y_granularity = 10.f;
};
