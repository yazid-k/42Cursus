#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>

class Vector
{
private:
    std::vector<int>  vec;
    int size;

public:
    Vector(void);
    Vector(const Vector &toCopy);
    Vector  &operator = (const Vector &toCopy);
    ~Vector(void);

    Vector(std::vector<int> v);

    std::vector<int> getVect(void) const;
    int getSize(void) const;

    class DifferentSize : public std::exception
    {
    public :
        const char * what () const throw ()
        {
            return ("Vectors of different size");
        }
    };

    Vector  add(Vector &v);
    Vector  sub(Vector &v);
    Vector  scl(int a);
};

std::ostream    &operator << (std::ostream &output, const Vector &f);

#endif
