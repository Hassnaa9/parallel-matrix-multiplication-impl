#ifndef matrix_multiplication
define matrix_multiplication

#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>
#include <hpx/init.hpp>
#include <iostream>
#include <vector>
#include "matrix_multiplication.h"


typedef Matrix  std::vector<int> const&

void print_matrix(Matrix matrix, int n_rows, int n_cols);
void set_matrix(Matrix matrix ,int& n_rows , int& n_cols);
void multiplication(Matrix matrix1, Matrix matrix2, Matrix Res_matrix ,int& Res_matrix_rows , int& Res_matrix_cols);

#endif