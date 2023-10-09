#include<iostream>
#include"stb_image_write.h"

using namespace std;

int main()
{
  int width = 200;
  int height = 100;

  const int CHANNEL_NUM = 3;


  uint8_t *pixels = new uint8_t[width * height * CHANNEL_NUM];

  int index = 0;
  for(int j = height - 1; j >= 0; --j)
  {
    for(int i = 0; i < width; ++i)
    {
      float r = (float)i / (float)width;
      float g = (float)j / (float)height;
      float b = 0.2f;

      int ir = int(255.9 * r);
      int ig = int(255.9 * g);
      int ib = int(255.9 * b);
  
      pixels[index++] = ir;
      pixels[index++] = ig;
      pixels[index++] = ib;
    }
  }

  stbi_write_png("stbTest.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);

  delete[] pixels;

  return 0;
}
