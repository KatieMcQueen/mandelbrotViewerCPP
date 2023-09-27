/* 
 * an implementation of a simple library. the field class holds some static variables that 
 * would be annoying to pass every time
 */
#include<complex>
#include"complexLib.hpp"
#include<iostream>

using namespace std;

ComplexField::ComplexField(int w, int h, complex<long double> c1, complex<long double> c2)
{
  width = w;
  height = h;
  corner1 = c1;
  corner2 = c2;
  //the width of the imaginary plane. this is the abs of the difference of the real components of the corners
  widthImaginary = abs(real(corner2) - real(corner1));
  //the height of the imaginary plane. this is the abs of the difference of the imaginary components of the corners
  heightImaginary = abs(imag(corner2) - imag(corner1));
  //the real component of corner 1
  cornerReal = real(corner1);
  //the imaginary component of corner 2
  cornerImaginary = imag(corner1);
}

//get the complex value of a pixel
complex<long double> ComplexField::getValue(int x, int y)
{
  //see complexScaling.png for a visual explanation of this algorithm.
  //we just need to pick a complex value closest to our given pixel
  long double scalerx = (float)x / (float)width;
  long double scalery = (float)y / (float)height;
  long double realComponent = widthImaginary * scalerx + cornerReal;
  long double imaginaryComponent = heightImaginary * scalery + cornerImaginary;
  complex<long double> complexPoint(realComponent, imaginaryComponent);
  return complexPoint;
}


