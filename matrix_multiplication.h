#ifndef matrix_multiplication
#define matrix_multiplication

#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>
#include <hpx/init.hpp>
#include <iostream>
#include <vector>


typedef std::vector<int>     Matrix ;

void print_matrix(Matrix matrix, int n_rows, int n_cols);
void set_matrix(Matrix& matrix ,int n_rows , int n_cols);
void multiplication(Matrix matrix1, Matrix matrix2, Matrix& Res_matrix ,
                    int matrix1_rows, int matrix1_cols, int matrix2_rows, int matrix2_cols);

#endif