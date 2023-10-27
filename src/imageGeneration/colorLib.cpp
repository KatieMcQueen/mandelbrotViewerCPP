#include"colorLib.hpp"

ColorMap::Colormap(string filename)
{
  colorMap = buildMap(filename, mapLength);
}


