#include "Matrix.h"
#include <stdio.h>


using namespace std;


Matrix::Matrix(unsigned int a, unsigned int b){
  
  rows = a;
  cols = b;
  
  
  for(unsigned int j =0; j < rows; ++j){
    arr[j] = new double[cols];

  }
   
  
}//Constructor for form Matrix(int, int)
Matrix::Matrix(const i_list & list){

  for(unsigned int j =0; j < rows; ++j){
    arr[j] = new double[cols];
  }
  
  int k = list.size();
  int r = list.begin()->size();

  for(int x = 0; x < k; x++)
  for(int c = 0; c < r; c++)
  {
    arr[x][c] = *((list.begin() + x)->begin() + c);
    
  }

}//Constructor used when given a list

Matrix::Matrix(const Matrix & m){ 
  
  for(unsigned int j =0; j < rows; ++j){
    arr[j] = new double[cols];
  }
  
  for(unsigned int b = 0; b < m.numRows(); b++)
  for(unsigned int c =0; c < m.numCols(); c++)
  {
    arr[b][c] = m.at(b,c);
  }
  
}//Constructor used when given another matrix

Matrix::~Matrix(){
  delete arr;
}//Destructor

Matrix Matrix::add(double s) const{
  Matrix add1(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    add1.at(p,r) = arr[p][r] + s;
  }
  
  return add1;
}//add function used to add a scalar to matrix

Matrix Matrix::add(const Matrix & m) const{
  Matrix add(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    add.at(p,r) = arr[p][r] + m.at(p,r);
  }
  
  return add;
}//add function used to add a matrix to a matrix

Matrix Matrix::subtract(double s) const{
  Matrix sub1(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    sub1.at(p,r) = arr[p][r] - s;
  }
  
  return sub1;
}//subtract function used to subtract a scalar from a matrix

Matrix Matrix::subtract(const Matrix & m) const{
  Matrix sub(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    sub.at(p,r) = arr[p][r] - m.at(p,r);
  }
  
  return sub;
}//subtract function used to subtract matrix from matrix

Matrix Matrix::multiply(double s) const{
  Matrix mult(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    mult.at(p,r) = arr[p][r] * s;
  }
  
  return mult;
}//multiply function used to multiply scalar to matrix

Matrix Matrix::multiply(const Matrix & m) const{
  
 
 Matrix mul(rows, m.numCols());
 
 for(unsigned int a = 0; a < rows; ++a)
 for(unsigned int b =0; b < m.numCols(); ++b)
 for(unsigned int c = 0; c < cols; ++c)
 {
   mul.at(a,b) += arr[a][c] * m.at(c,b);
   
 }

  return mul;
}//multiply function used to multiply two matrices

Matrix Matrix::divide(double s) const{
  Matrix div(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    div.at(p,r) = arr[p][r] / s;
  }
  
  return div;
}//divide function used to divide matrix by scalar

Matrix Matrix::t() const{
  Matrix tran(cols, rows);
  
  for(unsigned int c = 0; c < rows; ++c)
  for(unsigned int d = 0; d < cols; ++d)
  {
    tran.at(d,c) = arr[c][d];
  }
  
  return tran;
}//transpose function to find the transpose of a matrix

const uint Matrix::numRows() const{
  
  return rows;
}//returns the number of rows

const uint Matrix::numCols() const{
  
  return cols;
}//returns the number of columns

double & Matrix::at(uint row, uint col){
  
  
  return arr[row][col];
}//used to get/set at a certain point

const double & Matrix::at(uint row, uint col) const{

  return arr[row][col];
}//used to get the value at a point

Matrix operator+(const Matrix & left, const double & right){
  Matrix ano(left.numRows(), left.numCols());
  
  for(unsigned int p = 0; p < left.numRows(); ++p)
  for(unsigned int r = 0; r < left.numCols(); ++r)
  {
    ano.at(p,r) = left.at(p,r) + right;
  }
  
  return ano;
  

}//overload operator +

Matrix operator+(const double & left, const Matrix & right){
  Matrix lano(right.numRows(), right.numCols());
  
  for(unsigned int p = 0; p < right.numRows(); ++p)
  for(unsigned int r = 0; r < right.numCols(); ++r)
  {
    lano.at(p,r) = right.at(p,r) + left;
  }
  
  return lano;
  

}//overload operator +

Matrix operator+(const Matrix & left, const Matrix & right){
  Matrix plus(left.numRows(), left.numCols());
  
  for(unsigned int p = 0; p < left.numRows(); ++p)
  for(unsigned int r = 0; r < left.numCols(); ++r)
  {
    plus.at(p,r) = left.at(p,r) + right.at(p,r);
  }
  
  return plus;
  
}//overload operator +

Matrix operator-(const Matrix & left, const double & right){
  Matrix min(left.numRows(), left.numCols());
  
  for(unsigned int p = 0; p < left.numRows(); ++p)
  for(unsigned int r = 0; r < left.numCols(); ++r)
  {
    min.at(p,r) = left.at(p,r) - right;
  }
  
  return min;
  

}//overload operator -

Matrix operator-(const double & left, const Matrix & right){
  Matrix lmin(right.numRows(), right.numCols());
  
  for(unsigned int p = 0; p < right.numRows(); ++p)
  for(unsigned int r = 0; r < right.numCols(); ++r)
  {
    lmin.at(p,r) = right.at(p,r) - left;
  }
  
  return lmin;
  

}//overload operator -

Matrix operator-(const Matrix & left, const Matrix & right){
  Matrix minus(left.numRows(), left.numCols());
  
  for(unsigned int p = 0; p < left.numRows(); ++p)
  for(unsigned int r = 0; r < left.numCols(); ++r)
  {
    minus.at(p,r) = left.at(p,r) - right.at(p,r);
  }
  
  return minus;
  
}//overload operator -

Matrix operator*(const Matrix & left, const double & right){
  Matrix tim(left.numRows(), left.numCols());
  
  for(unsigned int p = 0; p < left.numRows(); ++p)
  for(unsigned int r = 0; r < left.numCols(); ++r)
  {
    tim.at(p,r) = left.at(p,r) * right;
  }
  
  return tim;
  

}//overload operator *

Matrix operator*(const double & left, const Matrix & right){
  Matrix ltim(right.numRows(), right.numCols());
  
  for(unsigned int p = 0; p < right.numRows(); ++p)
  for(unsigned int r = 0; r < right.numCols(); ++r)
  {
    ltim.at(p,r) = right.at(p,r) * left;
  }
  
  return ltim;
  

}//overload operator *

Matrix operator*(const Matrix & left, const Matrix & right){
  Matrix prod(left.numRows(), right.numCols());
  
  for(unsigned int a = 0; a < left.numRows(); ++a)
  for(unsigned int b =0; b < right.numCols(); ++b)
  for(unsigned int c = 0; c < left.numCols(); ++c)
   {
     prod.at(a,b) += left.at(a, c) * right.at(c,b);
   
   }

  return prod;
  
}//overload operator *

Matrix operator/(const Matrix & left, const double & right){
  Matrix quo(left.numRows(), left.numCols());
  
  for(unsigned int p = 0; p < left.numRows(); ++p)
  for(unsigned int r = 0; r < left.numCols(); ++r)
  {
    quo.at(p,r) = left.at(p,r) / right;
  }
  
  return quo;
  
}//overload operator /

Matrix operator/(const double & left, const Matrix & right){
  Matrix lquo(right.numRows(), right.numCols());
  
  for(unsigned int p = 0; p < right.numRows(); ++p)
  for(unsigned int r = 0; r < right.numCols(); ++r)
  {
    lquo.at(p,r) = right.at(p,r) / left;
  }
  
  return lquo;
  
}//overload operator /

double Matrix::operator()(uint row, uint col){
  
  return arr[row][col];
  
}//overload operator ()

Matrix Matrix:: operator-(){
  Matrix neg(rows, cols);
  
  for(unsigned int p = 0; p < rows; ++p)
  for(unsigned int r = 0; r < cols; ++r)
  {
    neg.at(p,r) = arr[p][r] * -1;
  }
  
  return neg;
  
}//overload operator -

Matrix Matrix:: operator=(const i_list & hole){
  Matrix change(rows, cols);
  
  int s = hole.size();
  int t = hole.begin()->size();

  for(int x = 0; x < s; x++)
  for(int c = 0; c < t; c++)
  {
    change.at(x, c) = *((hole.begin() + x)->begin() + c);
    
  }
  
  return change;
  
}//overload operator =

ostream& operator<<(ostream& os, const Matrix & mat){

  string str;

  for(unsigned int z = 0; z < mat.numRows(); z++){
  os << "[ ";
  for(unsigned int x = 0; x < mat.numCols(); x++)
  {
    os << mat.at(z,x); 
    if(x != mat.numCols()-1){
      os << ", ";
    }
  }
  os << " ]" << "\n";
 }
  return os;
}//overload operator <<


