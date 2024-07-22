#include "functions.hpp"

bool    eval_formula(std::string str)
{
    if (str.empty())
    {
        std::cout << "Error: empty formula" << std::endl;
        return false;
    }

    int a,b;
    std::stack<bool> stack;

    for (char symbol : str)
    {
        switch (symbol)
        {
            case '0':
                stack.push(false);
                break;
            case '1':
                stack.push(true);
                break;
            case '!':
                if (stack.empty())
                {
                    std::cout << "Error: stack is empty" << std::endl;
                    return false;
                }
                stack.top() = !stack.top();
                break;
            case '&':
                if (stack.size() < 2)
                {
                    std::cout << "Error: stack is too small" << std::endl;
                    return false;
                }
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a & b);
                break;
            case '|':
                if (stack.size() < 2)
                {
                    std::cout << "Error: stack is too small" << std::endl;
                    return false;
                }
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a | b);
                break;
            case '^':
                if (stack.size() < 2)
                {
                    std::cout << "Error: stack is too small" << std::endl;
                    return false;
                }
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a ^ b);
                break;
            case '>':
                if (stack.size() < 2)
                {
                    std::cout << "Error: stack is too small" << std::endl;
                    return false;
                }
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(!b | a);
                break;
            case '=':
                if (stack.size() < 2)
                {
                    std::cout << "Error: stack is too small" << std::endl;
                    return false;
                }
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a == b);
                break;
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "Error: stack is not empty" << std::endl;
        return false;
    }
    return stack.top();
}


/* int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <formula>" << std::endl;
        return 1;
    }
    std::cout << eval_formula(argv[1]) << std::endl;
    return 0;
}
 */
