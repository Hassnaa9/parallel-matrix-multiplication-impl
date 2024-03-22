#include "matrix_multiplication.h"


void print_matrix(Matrix matrix, int n_rows, int n_cols)
{

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
            std::cout << matrix[i * n_cols + j] << " ";
        std::cout << "\n";
    }
}
void set_matrix(Matrix matrix ,int& n_rows , int& n_cols)
{
    
    std::cout << "Enter the elements of matrix  : \n";
    for (int i = 0; i < n_rows; i++)
        {
            for (int j = 0; j < n_cols; j++)
                std::cin >> matrix1[i * n_cols + j] ;
            std::cout << "\n";
        }
}
void multiplication(Matrix matrix1, Matrix matrix2, Matrix Res_matrix ,int& Res_matrix_rows , int& Res_matrix_cols){

    hpx::experimental::for_loop(hpx::execution::par, 0, matrix1_rows, [&](auto i) {
        hpx::experimental::for_loop(0, matrix2_cols, [&](auto j) {
            Res_matrix[i * Res_matrix_cols + j] = 0;
            hpx::experimental::for_loop(0, matrix2_rows, [&](auto k) {
                Res_matrix[i * Res_matrix_cols + j] += ((matrix1[i * matrix1_cols + k] )*( matrix2[k * matrix2_cols + j]));
            });
        });
    });

}
