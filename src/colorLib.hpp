#pragma once
#include"RGB.hpp"

class ColorMap
{
  private:
    double *colors = nullptr;
    int length;
    bool normalized;
    double* buildMap(string fileName);
  public:
    RGB getColor(int value);
    RGB normalToRGB(double *value);
}
