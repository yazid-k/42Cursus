#include "functions.hpp"

int graycode(int n)
{
    return n ^ (n >> 1);
}

/* int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <num>" << std::endl;
        return 1;
    }
    std::cout << graycode(std::stoi(argv[1])) << std::endl;
    return 0;
} */
