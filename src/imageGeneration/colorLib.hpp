#pragma once
#include"RGB.hpp"
#include<cstdint>

/* 
 * this header represents a color map and it's functions. 
 * a user should be able to construct a color map from file
 * through the class the user should then be able to access information from that colormap
 */

class ColorMap
{
  private:
    double *colors = nullptr;
    int length;
    bool normalized;
    double* buildMap(string fileName); //build a color map from file. 
    RGB normalToRGB(double *value);
    uint8_t normalToChanel(double value);
  public:
    RGB getColor(int value);
}
