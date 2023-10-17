#pragma once
#include<complex>
#include<string>

//include the complexField functionality into here
//maybe mandelbrot contains a member class that stores state

class Mandelbrot
{
  private:

    int iterations = 1024; //max iterations of the mandelbrot

    int imageWidth = 2560;

    int imageHeight = 1440;

    bool autoName = true; //should the program automatically name the render

    std::string name = "render";

    std::string path = "images/";

    std::complex<long double> corner1; //the bottom left corner of our window into the imaginary plane

    std::complex<long double> corner2; //the top right corner of our window into hte imaginary plane

    long double widthImaginary;      //the length of our window into the imaginary plane

    long double heightImaginary;     //the height of our window into the imaginary plane

    //the real component of corner 1
    long double cornerReal;          

    //the imaginary component of corner 2
    long double cornerImaginary;

    //evaluates whether a point is in the mandelbrot set
    int evaluate(std::complex<long double> c, int iterations);
    
    std::complex<long double> getComplexValue(int x, int y);

    const char* makeName(std::string name);

    void parseArgs(int argc, const char **argv);

    Mandelbrot(int iterations, int imageWidth, int imageHeight);

  public:
    void run();
};
