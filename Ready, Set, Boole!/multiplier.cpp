#include "functions.hpp"

int multiplier(int a, int b)
{
    int result = 0;
    for (int i = 0; i < b; i++)
        result = adder(result, a);
    return result;
}

/* int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2>" << std::endl;
        return 1;
    }
    std::cout << multiplier(std::stoi(argv[1]), std::stoi(argv[2])) << std::endl;
    return 0;
} */
