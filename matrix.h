// A simple basic implementation of a Matrix class

#ifndef TEACH_CSCI335_MATRIX_H_
#define TEACH_CSCI335_MATRIX_H_

#include <iostream>


// Make it a habit to use namespaces for your code.
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
  Matrix() : num_columns_{0}, num_rows_{0} {
    array_ = new Object *[num_rows_];
  };
  ~Matrix() {
    DeleteMatrix();
  }
  Matrix(const Matrix &rhs) : num_columns_{rhs.num_columns_}, num_rows_{rhs.num_rows_} {
    array_ = new Object *[rhs.num_rows_];
    for(size_t i = 0; i < rhs.num_rows_; ++i) {
      array_[i] = new Object[rhs.num_columns_];
      for (size_t j = 0; j < rhs.num_columns_; ++j)
        array_[i][j] = rhs.array_[i][j];
    }
  };
  Matrix& operator=(const Matrix &rhs) {
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
  Matrix(Matrix &&rhs) : num_columns_{rhs.num_columns_},
                         num_rows_{rhs.num_rows_},
                         array_{std::move(rhs.array_)} {
    rhs.num_columns_ = 0;
    rhs.num_rows_ = 0;
    rhs.array_ = nullptr;
  };
  Matrix& operator=(Matrix &&rhs) {
    std::swap(array_, rhs.array_);
    return *this;
  };
/*  Matrix& operator=(Matrix &&rhs) {
      DeleteMatrix();
      array_ = rhs.array_;
      num_columns_ = rhs.num_columns_;
      num_rows_ = rhs.num_rows_;
      rhs.array_ = nullptr;
      rhs.num_rows_ = 0;
      rhs.num_columns_ = 0;
      return *this;
  };
  */


  void ReadMatrix() {
    DeleteMatrix();
    std::cin >> num_rows_ >> num_columns_;
    std::cout << "Rows: " << num_rows_ << " Columns: " << num_columns_ << std::endl;
    array_ = new Object *[num_rows_];
    for(size_t i = 0; i < num_rows_; ++i) {
      array_[i] = new Object[num_columns_];
      for(size_t j = 0; j < num_columns_; j++)
        std::cin >> array_[i][j];
    }
   }
  // @row: an index to a row of the matrix.
  // @returns the row as a vector of items. No error checking.
  // const version.
  const std::vector<Object> & operator[](int row) const
  {  }

 // @row: an index to a row of the matrix.
 // @returns the row as a vector of items. No error checking.
 // non-cost version.
  std::vector<Object> & operator[](int row)
   {  }

  Matrix operator+(const Matrix &b_matrix) { }
  Matrix operator+(const Object &an_object) { }

 // @returns number of rows.
  size_t NumRows() const { return num_rows_; }
  // @returns number of columns.
  size_t NumCols() const { return num_columns_; }

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
 void DeleteMatrix() {
   if(num_rows_ > 0) {
   for(size_t i = 0; i < num_rows_; ++i) {
     delete [] array_[i];
     //std::cout << "Deleting array at " << i << std::endl;
   }
 }
   std::cout << "Deleting array\n";
   delete [] array_;
 }
};

}  // namespace linear_algebra_project

#endif  // TEACH_CSCI335_MATRIX_H
