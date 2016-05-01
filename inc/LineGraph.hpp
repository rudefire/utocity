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

  private:
    std::string graph_label, x_label, y_label;    
    float x_scale, y_scale;
    std::vector<double> x_values;
    std::vector<double> y_values;
};
