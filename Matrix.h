#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <stdio.h>
#include <initializer_list>

using std::initializer_list;
using std::ostream;


typedef unsigned int uint;
typedef initializer_list<initializer_list<double>> i_list;

class Matrix {
  double** arr = new double*[rows];
  unsigned int rows;
  unsigned int cols;
  
  public:
    Matrix(uint rows, uint cols);                 // constructor (all elements initialized to 0)
    Matrix(const i_list & list);                  // constructor (using initializer list)
    Matrix(const Matrix & m);                     // copy constructor
    ~Matrix();                                    // destructor
    
    Matrix add(double s) const;                   // add scalar to this matrix
    Matrix add(const Matrix & m) const;           // add this matrix and another matrix
    
    Matrix subtract(double s) const;              // subtract scalar from this matrix
    Matrix subtract(const Matrix & m) const;      // subtract another matrix from this matrix
    
    Matrix multiply(double s) const;              // multiply this matrix by a scaler
    Matrix multiply(const Matrix & m) const;      // multiply this matrix by another matrix
    
    Matrix divide(double s) const;                // divide this matrix by a scaler
    Matrix t() const;                             // transpose of this matrix
    
    const uint numRows() const;                   // returns the number of rows
    const uint numCols() const;                   // returns the number of cols
    
    double & at(uint row, uint col);              // get/set element at row,col
    const double & at (uint row, uint col) const; // get element at row,col (when using a const object)
    
    double operator()(uint rows, uint cols);      // overload operator for (), returns the value at pos: rows, cols
    Matrix operator-();                           // overload operator for -, negates the whole matrix
    Matrix operator=(const i_list & hole);        // overload operator for =
    
    
}; // Matrix

    Matrix operator+(const Matrix & left, const double & right); //overload operator for +, used to add scalar to matrix
    Matrix operator+(const double & left, const Matrix & right); //overload operator for +, used to add matrix to scalar
    Matrix operator+(const Matrix & left, const Matrix & right); //overload operator for +, used to add two matrices
    Matrix operator-(const Matrix & left, const double & right); //overload operator for -, used to subtract scalar from matrix
    Matrix operator-(const double & left, const Matrix & right); //overload operator for -, used to subtract matrix from scalar
    Matrix operator-(const Matrix & left, const Matrix & right); //overload operator for -, used to subtract two matrices
    Matrix operator*(const Matrix & left, const double & right); //overload operator for *, used to multiply scalar to matrix
    Matrix operator*(const double & left, const Matrix & right); //overload operator for *, used to multiply matrix to scalar
    Matrix operator*(const Matrix & left, const Matrix & right); //overload operator for *, used to multiply two matrices
    Matrix operator/(const Matrix & left, const double & right); //overload operator for /, used to divide matrix by scalar
    Matrix operator/(const double & left, const Matrix & right); //overload operator for /, used to divide sclar by matrix
    
    ostream& operator<<(ostream& os, const Matrix & mat); //overload operator for <<, used to print out matrix in correct form
    
#endif