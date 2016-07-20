#pragma once

#include <string>
#include <vector>

class LineGraph
{
  public:
    LineGraph();
    ~LineGraph();

    void Build(std::string graph_l, std::string x_l, std::string y_l,
        float y_s, std::vector<float> y_vals, int x_divs);
    void Rebuild();
    void Render();
    void CalculateOrigin();
    void TextRender();
    void PointRender();
    void GraphRender();
    void ScaleRender();


  private:
    std::string graph_label, x_label, y_label;    
    float y_scale;
    std::vector<float> y_values;
    int x_divisions = 0;
    float window_width = 500, window_height = 500;
    float graph_height, graph_width;
    float x_granularity = 10.f, y_granularity = 10.f;
};
