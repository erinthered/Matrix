/**********************************************************************
Title:          test_matrix1.cc
Author:         Erin Williams
Date Created:   2/11/18
Class:          Spring 2018 - CS335
Purpose:        Assignment #1
Description:    Test file for matrix class.
***********************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "matrix.h"

// It is fine to use namespaces in .cc files.
using namespace std;
using namespace linear_algebra_project;

namespace {

// Prints values in a vector of Objects
template <typename Object>
void PrintVec(const vector<Object> &a_vector) {
  for(const auto & x: a_vector)
    cout << x << " ";
  cout << endl;
}

void TestPart1() {
  Matrix<int> a, b;
  cout << a.NumRows() << " " << a.NumCols() << endl;

  a.ReadMatrix();

  cout << a << endl;

  b.ReadMatrix();
  cout << b << endl;

  a = b;
  cout << a << endl;

  Matrix<int> c = b;
  cout << c << endl;

  Matrix<int> d = std::move(c);
  cout << d << endl;

  a = std::move(d);
  cout << a << endl;

}

void TestPart2() {
  Matrix<string> a, b;
  a.ReadMatrix();
  cout << a << endl;
  b.ReadMatrix();
  cout << b << endl;
  cout << a + b << endl; // Matrices should have same size.
                         // The default + operator for strings
                         // will be used.

  Matrix<string> d = a + b;
  cout << d <<endl;

  const string a_string{"hi_there"};
  cout << d + a_string << endl;

  PrintVec(a[1]);  // Should print the first row of a.
  PrintVec(b[2]);  // Should be print the second row of b.
                   // Note, that the [] operator should return
                   // a vector object.
                   // PrintVec() is a templated function that
                   // couts the elements of a vector.
}
}  // namespace

int main() {

  TestPart1();
  TestPart2();
  return 0;
}
