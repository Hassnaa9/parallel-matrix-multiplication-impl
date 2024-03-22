#include "matrix_multiplication.h"

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
