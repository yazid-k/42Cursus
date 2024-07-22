#include "Vector.cpp"

int main(void)
{
    std::vector<int> v, w;

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    w.push_back(2);
    w.push_back(2);
    w.push_back(2);
    w.push_back(2);
    w.push_back(2);
    w.push_back(2);

    Vector vec(v);
    Vector wec(w);

    std::cout << vec << std::endl;
    std::cout << wec << std::endl;

    vec.sub(wec);

    std::cout << vec << std::endl;

    vec.scl(9);

    std::cout << vec << std::endl;


    return 0;
}
