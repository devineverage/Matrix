#include "Matrix.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

   
  Matrix sam = {{ 1, 2,},{3,4},{4,3}};
  //cout << sam.at(0,0) << " " << sam.at(0,1) << " " << sam.at(1,0) << " " << sam.at(1,1);
  
  Matrix a(2, 2);
  a.at(0, 0) = 1; // [ 1, 2 ]
  a.at(0, 1) = 2; // [ 1, 3 ]
  a.at(1, 0) = 1;
  a.at(1, 1) = 3;
  cout << a;
  Matrix x(a);
  //cout << x.at(0,0) << " " << x.at(0,1) << " " << x.at(1,0) << " " << x.at(1,1);
  
  Matrix c0 = a / 5;
  //cout << c0.at(0,0) << " " << c0.at(0,1) << " " << c0.at(1,0) << " " << c0.at(1,1);
  
  Matrix c1 = 5 / a;
  //cout << c1.at(0,0) << " " << c1.at(0,1) << " " << c1.at(1,0) << " " << c1.at(1,1);
  
  Matrix b(2, 1);
  b.at(0, 0) = 3; // [ 3 ]
  b.at(1, 0) = 2; // [ 2 ]
  //cout << b;
  
  Matrix d = a.t();
  //cout << d.at(0,0) << " " << d.at(0,1) << " " << d.at(1,0) << " " << d.at(1,1);
  
  Matrix y(2,2);
  y.at(0,0) = 5;
  y.at(0,1) = 4;
  y.at(1,0) = 3;
  y.at(1,1) = 2;
  
  Matrix s = a * b;
  Matrix l = -s;
  
  //cout << "[ " << l.at(0, 0) << " ]" << endl;  // [ 7 ]
  //cout << "[ " << l.at(1, 0) << " ]" << endl; // [ 9 ]
  
  Matrix c = a.multiply(b);
  //cout << "[ " << c.at(0, 0) << " ]" << endl;  // [ 7 ]
  //cout << "[ " << c.at(1, 0) << " ]" << endl; // [ 9 ]

  

  return 0;
}