#include "matrix_multiplication.h"
#include  "matrix_multiplication.cpp"


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

/////Get the data of matrices///////
    std::cout << "Matrix 1 : \n";
    std::cout << "Enter the number of rows : ";
    std::cin >> matrix1_rows;
    std::cout << "Enter the number of columns : ";
    std::cin >> matrix1_cols;

    std::cout << "Matrix 2 : \n";
    std::cout << "Enter the number of rows : ";
    std::cin >> matrix2_rows;
    std::cout << "Enter the number of columns : ";
    std::cin >> matrix2_cols;

    Res_matrix_rows = matrix1_rows;
    Res_matrix_cols = matrix2_cols;

    // initialize matrices 
    Matrix Res_matrix(Res_matrix_rows * matrix2_cols);
    Matrix matrix1(matrix1_rows * matrix1_cols);
    Matrix matrix2(matrix2_rows * matrix2_cols);

    //////set matrices/////
    set_matrix(matrix1, matrix1_rows, matrix1_cols);
    set_matrix(matrix2, matrix2_rows, matrix2_cols);


    // Print the 3 matrices
    std::cout<<"Matrix 1 : \n";
    print_matrix(matrix1, matrix1_rows, matrix1_cols);
    std::cout<<"Matrix 2 : \n";
    print_matrix(matrix2, matrix2_rows, matrix2_cols);

    // multiplication//
     multiplication( matrix1, matrix2, Res_matrix ,
                     matrix1_rows, matrix1_cols, matrix2_rows, matrix2_cols);
    std::cout<<"The result of multiplication : \n";
    print_matrix(Res_matrix, Res_matrix_rows, Res_matrix_cols);

    return hpx::local::finalize();
}


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