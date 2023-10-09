#pragma once
#include<cstdint>

struct RGB
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

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
