#include <hpx/algorithm.hpp>
#include <hpx/execution.hpp>
#include <hpx/init.hpp>
#include <iostream>
#include <vector>

//////////////////Print Matrix//////////////////////////////
void print_matrix(std::vector<int> const& matrix, int n_rows, int n_cols)
{

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
            std::cout << matrix[i * n_cols + j] << " ";
        std::cout << "\n";
    }
}


/////////hpx main/////////////
int hpx_main(hpx::program_options::variables_map& vm)
{

    //  matrix sizes
    int matrix1_rows ;
    int matrix1_cols ;
    int matrix2_rows ;
    int matrix2_cols ;
    int Res_matrix_rows;
    int Res_matrix_cols;

    

    ////get matrix 1////
    std::cout << "Matrix 1 : \n";
    
    std::cout << "Enter the number of rows : ";
    std::cin >> matrix1_rows;
    std::cout << "Enter the number of columns : ";
    std::cin >> matrix1_cols;

    std::vector<int> matrix1(matrix1_rows * matrix1_cols);//initialize of matrix 1

    std::cout << "Enter the elements of matrix 1 : \n";
    for (int i = 0; i < matrix1_rows; i++)
        {
            for (int j = 0; j < matrix1_cols; j++)
                std::cin >> matrix1[i * matrix1_cols + j] ;
            std::cout << "\n";
        }


    ////////////////////

    ////get matrix 2////
    std::cout << "Matrix 2 : \n";
    
    std::cout << "Enter the number of rows : ";
    std::cin >> matrix2_rows;
    std::cout << "Enter the number of columns : ";
    std::cin >> matrix2_cols;

    std::vector<int> matrix2(matrix2_rows * matrix2_cols);//init matrix 2
    std::cout << "Enter the elements of matrix 2 : \n";
    for (int i = 0; i < matrix2_rows; i++)
        {
            for (int j = 0; j < matrix2_cols; j++)
                std::cin >> matrix2[i * matrix2_cols + j] ;
            std::cout << "\n";
        }


    ////////////////////
     Res_matrix_rows = matrix1_rows;
     Res_matrix_cols = matrix2_cols;
     
    // initialize matrices 
    std::vector<int> Res_matrix(Res_matrix_rows * matrix2_cols);

    ///////////////////////////Multiplication of two matrices//////////////
    hpx::experimental::for_loop(hpx::execution::par, 0, matrix1_rows, [&](auto i) {
        hpx::experimental::for_loop(0, matrix2_cols, [&](auto j) {
            Res_matrix[i * Res_matrix_cols + j] = 0;
            hpx::experimental::for_loop(0, matrix2_rows, [&](auto k) {
                Res_matrix[i * Res_matrix_cols + j] += ((matrix1[i * matrix1_cols + k] )*( matrix2[k * matrix2_cols + j]));
            });
        });
    });

    // Print the 3 matrices
    std::cout<<"Matrix 1 : \n";
    print_matrix(matrix1, matrix1_rows, matrix1_cols);
    std::cout<<"Matrix 2 : \n";
    print_matrix(matrix2, matrix2_rows, matrix2_cols);
    std::cout<<"The result of multiplication : \n";
    print_matrix(Res_matrix, Res_matrix_rows, Res_matrix_cols);

    return hpx::local::finalize();
}
//]

///////////////////////////////////////////////////////////////////////////////
//[mul_main
int main(int argc, char* argv[])
{
    using namespace hpx::program_options;
    options_description cmdline("usage: " HPX_APPLICATION_STRING " [options]");
    // clang-format off
    cmdline.add_options()
        ("n",
        hpx::program_options::value<std::size_t>()->default_value(2),
        "Number of rows of first matrix")
        ("m",
        hpx::program_options::value<std::size_t>()->default_value(3),
        "Number of columns of first matrix (equal to the number of rows of "
        "second matrix)")
        ("k",
        hpx::program_options::value<std::size_t>()->default_value(2),
        "Number of columns of second matrix")
        ("seed,s",
        hpx::program_options::value<unsigned int>(),
        "The random number generator seed to use for this run")
        ("l",
        hpx::program_options::value<int>()->default_value(0),
        "Lower limit of range of values")
        ("u",
        hpx::program_options::value<int>()->default_value(10),
        "Upper limit of range of values");
    // clang-format on
    hpx::local::init_params init_args;
    init_args.desc_cmdline = cmdline;

     return hpx::local::init(hpx_main, argc, argv, init_args);
}