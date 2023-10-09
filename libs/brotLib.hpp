#pragma once
#include<complex>
#include<string>

class Runner
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
    int getIterations();
    {return iterations;}
    int getWitdth();
    {return imageWidth;}

