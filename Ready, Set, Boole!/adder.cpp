#include <iostream>
#include <string>

int adder(int a, int b)
{
    int carry = a & b;
    int sum = a ^ b;
    while (carry != 0)
    {
        int shifted_carry = carry << 1;
        carry = sum & shifted_carry;
        sum = sum ^ shifted_carry;
    }
    return sum;
}

/* int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2>" << std::endl;
        return 1;
    }
    std::cout << adder(std::stoi(argv[1]), std::stoi(argv[2])) << std::endl;
    return 0;
} */

