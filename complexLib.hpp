/*
 * this header is an evolutionary dead end, I realized the process would be faster and less error prone if I don't have to manage two giant arrays
 */
#pragma once
#include<complex>


class ComplexField
{
  private:
    int width;
    int height;
    std::complex<long double> corner1;
    std::complex<long double> corner2;
    long double widthImaginary;      //the length of our window into the imaginary plane
    long double heightImaginary;     //the height of our window into the imaginary plane
    long double cornerReal;          //the real component of corner 1
    long double cornerImaginary;     //the imaginary component of corner 2
    
  public:
    ComplexField(int w, int h, std::complex<long double> c1, std::complex<long double> c2);
    std::complex<long double> getValue(int x, int y);

    int getHeight()
    {return height;}

    int getWidth()
    {return width;}

    std::complex<long double> getCorner1()
    {return corner1;}

    std::complex<long double> getCorner2()
    {return corner2;}
};


