/**********************************************************************
Title:          matrix.cc
Author:         Erin Williams
Date Created:   2/11/18
Class:          Spring 2018 - CS335
Purpose:        Assignment #1
Description:    Implementation file for a basic templated matrix class.
***********************************************************************/

#ifndef _CSCI335_MATRIX_CC
#define _CSCI335_MATRIX_CC

#include <iostream>
#include "matrix.h"

namespace linear_algebra_project {

template <typename Object>
Matrix<Object>::Matrix(size_t columns, size_t rows) : num_columns_{columns}, num_rows_{rows} {
  array_ = new Object *[num_rows_];
};
template <typename Object>
Matrix<Object>::~Matrix() {
  DeleteMatrix();
}

template <typename Object>
Matrix<Object>::Matrix(const Matrix<Object> &rhs) : num_columns_{rhs.num_columns_}, num_rows_{rhs.num_rows_} {
  array_ = new Object *[rhs.num_rows_];
  for(size_t i = 0; i < rhs.num_rows_; ++i) {
    array_[i] = new Object[rhs.num_columns_];
    for (size_t j = 0; j < rhs.num_columns_; ++j)
      array_[i][j] = rhs.array_[i][j];
  }
};
template <typename Object>
Matrix<Object>& Matrix<Object>::operator=(const Matrix<Object> &rhs) {
  if(this != &rhs) {
    DeleteMatrix();
    array_ = new Object *[rhs.num_rows_];
  }
  num_rows_ = rhs.num_rows_;
  num_columns_ = rhs.num_columns_;

  for(size_t i = 0; i < rhs.num_rows_; ++i) {
    array_[i] = new Object[rhs.num_columns_];
    for (size_t j = 0; j < rhs.num_columns_; ++j)
      array_[i][j] = rhs.array_[i][j];
  }
  return *this;
};

template <typename Object>
Matrix<Object>::Matrix(Matrix<Object> &&rhs) : num_columns_{rhs.num_columns_},
                         num_rows_{rhs.num_rows_},
                         array_{std::move(rhs.array_)} {
  rhs.num_columns_ = 0;
  rhs.num_rows_ = 0;
  rhs.array_ = nullptr;
};
template <typename Object>
Matrix<Object>& Matrix<Object>::operator=(Matrix<Object> &&rhs) {
  std::swap(array_, rhs.array_);
  return *this;
};

template <typename Object>
void Matrix<Object>::ReadMatrix() {
  DeleteMatrix();
  std::cin >> num_rows_ >> num_columns_;
  array_ = new Object *[num_rows_];
  for(size_t i = 0; i < num_rows_; ++i) {
    array_[i] = new Object[num_columns_];
    for(size_t j = 0; j < num_columns_; j++)
      std::cin >> array_[i][j];
  }
}

template <typename Object>
const std::vector<Object> Matrix<Object>::operator[](int row) const {
  row -=1;
  std::vector<Object> vec(array_[row], array_[row]+num_columns_);
  Object* p = vec.data();
  p = array_[row];
  return vec;
}
template <typename Object>
std::vector<Object> Matrix<Object>::operator[](int row) {
  row -=1;
  std::vector<Object> vec(array_[row], array_[row]+num_columns_);
  Object* p = vec.data();
  p = array_[row];
  return vec;
}

template <typename Object>
Matrix<Object> Matrix<Object>::operator+(const Matrix<Object> &b_matrix) {
  Matrix<Object> m{};
  if(num_rows_ == b_matrix.num_rows_ && num_columns_ == b_matrix.num_columns_) {
    m = *this;
    for(size_t i = 0; i < num_rows_; ++i) {
      for(size_t j = 0; j < num_columns_; j++)
        m.array_[i][j] += b_matrix.array_[i][j];
    }
  }
  return m;
}
template <typename Object>
Matrix<Object> Matrix<Object>::operator+(const Object &an_object) {
  Matrix<Object> m{};
  m = *this;
  m.array_[0][0] += an_object;
  return m;
 }

template <typename Object>
void Matrix<Object>::DeleteMatrix() {
 if(num_rows_ > 0) {
   for(size_t i = 0; i < num_rows_; ++i) {
     delete [] array_[i];
 }
  }
 delete [] array_;
};

}  // namespace linear_algebra_project

#endif // _CSCI335_MATRIX_CC
