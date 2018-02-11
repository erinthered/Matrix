/**********************************************************************
Title:          matrix.h
Author:         Erin Williams
Date Created:   2/11/18
Class:          Spring 2018 - CS335
Purpose:        Assignment #1
Description:    Header file for a basic templated matrix class.
***********************************************************************/

#ifndef _CSCI335_MATRIX_H_
#define _CSCI335_MATRIX_H_

#include <iostream>

namespace linear_algebra_project {

// Templated implementation of Matrix
// Sample usage:
//   Matrix<int> a;
//   a.ReadMatrix();
//   cout << a_matrix.NumRows() << endl;
//   cout << a_matrix.NumCols() << endl;
//   cout << a;
//   Matrix<int> b;
//   b.ReadMatrix();
//   cout << a + b;
template <typename Object>
class Matrix {
 public:
  Matrix(size_t columns = 0, size_t rows = 0);
  ~Matrix();
  Matrix(const Matrix &rhs);
  Matrix& operator=(const Matrix &rhs);
  Matrix(Matrix &&rhs);
  Matrix& operator=(Matrix &&rhs);

  // populate matrix based on standard input stream input
  // Precondition: First two items input must be integers and will
  // determine the number of rows and columns in the matrix.
  // Remaining input will fill matrix row by row.
  // Ex: input 3 = matrix[0][0], input 4 = matrix[0][1], etc.
  // No error checking for correct number of inputs to fill matrix.
  // Postcondition: Matrix is of specified size
  // and contains input entered by user in order of entry.
  void ReadMatrix();

  // @row: an index to a row of the matrix.
  // @returns the row as a vector of items. No error checking.
  // const version.
  const std::vector<Object> operator[](int row) const;
 // @row: an index to a row of the matrix.
 // @returns the row as a vector of items. No error checking.
 // non-cost version.
  std::vector<Object> operator[](int row);

  // @b_matrix: rhs matrix to add in operator
  // Precondition: Matrices to be added must be of the same size and of types
  // that can be added.
  // Class Objects to be added must have existing + operator.
  // Postcondition: returns new matrix containing added values of two Matrices
  // using built in + operators of the Object classes stored in the Matrices.
  Matrix operator+(const Matrix &b_matrix);
  // @an_object: Object to be added to Matrix at position [0][0]
  // Precondition: Obect must be of a type that can be added to the matrix
  // and must have an existing + operator.
  // Postcondition: array_[0][0] contains original value + an_object
  Matrix operator+(const Object &an_object);

 // @returns number of rows.
  inline size_t NumRows() const { return num_rows_; }
  // @returns number of columns.
  inline size_t NumCols() const { return num_columns_; }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Matrix &a_matrix) {
   for(size_t i = 0; i < a_matrix.num_rows_; i++) {
     for(size_t j = 0; j < a_matrix.num_columns_; j++)
        std::cout << a_matrix.array_[i][j] << "  ";
     std::cout << std::endl;
   }
   return out;
 }

 private:
 size_t num_columns_;
 size_t num_rows_;
 Object **array_;
 // helper function to delete matrix
 void DeleteMatrix();

};

}  // namespace linear_algebra_project

#include "matrix.cc"

#endif  // _CSCI335_MATRIX_H
