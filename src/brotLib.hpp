#pragma once
#include<complex>
#include<string>

//include the complexField functionality into here
//maybe mandelbrot contains a member class that stores state

class Mandelbrot
{
  private:
    int iterations = 1024;
    int imageWidth = 2560;
    int imageHeight = 1440;
    bool autoName = true;
    string name = "render";
    string path = "images/"
    int evaluate(complex<long double> c, int iterations);
    const char* makeName(string name);
    void parseArgs(int argc, const char **argv);
  public:
    void run();
}
