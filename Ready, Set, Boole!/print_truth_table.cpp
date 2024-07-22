#include "functions.hpp"

void    print_truth_table(std::string str)
{
    if (str.empty())
    {
        std::cout << "Error: empty formula" << std::endl;
        return;
    }

    std::string     variables;
    std::string     formula;

    for (char symbol : str)
    {
        if (isalpha(symbol))
            variables.push_back(symbol);
    }

    for (char c : variables)
        std::cout << "| " << c << " ";
    std::cout << "| = |" << std::endl;

    for (size_t i = 0; i < variables.size(); i++)
        std::cout << "|---";
    std::cout << "|---|" << std::endl;


    for (size_t i = 0; i < pow(2, variables.size()); i++)
    {
        for (size_t j = variables.size(); j > 0; j--)
        {
            std::cout << "| " << (i >> (j-1) & 1) << " ";
        }
        std::string    temp = str;
        std::cout << temp << std::endl;
        for (size_t j = 0; j < variables.size(); j++)
        {
            for (size_t k = 0; k < temp.size(); k++)
            {
                if (temp[k] == variables[j])
                    temp[k] = (i >> (j-1) & 1);
            }
        }
        std::cout << temp << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <formula>" << std::endl;
        return 1;
    }
    print_truth_table(argv[1]);
    return 0;
}
