#pragma once
#include"RGB.hpp"
#include<cstdint>
#include<string>

/* 
 * this header represents a color map and it's functions. 
 * a user should be able to construct a color map from file
 * through the class the user should then be able to access information from that colormap
 */


RGB normalToRGB(double r, double g, double b);
uint8_t normalToChanel(double value);

class ColorMap
{
  private:
    RGB *colorsMap = nullptr; 
    int mapLength;
    RGB* buildMap(string fileName, int &length); //build a color map from file. 
  public:
    RGB getColor(int value); //get a color from the color map
    ColorMap(string fileName);
    ~ColorMap();
};
