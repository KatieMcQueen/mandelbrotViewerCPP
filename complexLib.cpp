/* 
 * the imlementation for the complexLib header. I decided not to use this, for reasons explained in that header's comment
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
  field = new complex<long double>[w * h];
}

ComplexField::~ComplexField()
{
  delete [] field;
}

//get the complex value of a particular pixel
complex<long double> ComplexField::getValue(int x, int y)
{
  //this converts the 2d coordinates into the 1d address of the location in the list
  int addr = width * y + x;
  return field[addr];
}

void setValue(int x, int y, complex<long double> value)
{
  int addr = width * y + x;
  field[addr] = val;
}

void printField()
{
  int size = width * height;
  for(i = 0; i < size; i++)
  {
    int y = i / width;
    int x = i - (y * width);
    complex<long double> value = field[i];
    cout << "The complex value at (" << x << ',' << y << ") is: " << value << endl;
  }
}


