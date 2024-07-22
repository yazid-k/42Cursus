#include "Vector.hpp"

Vector::Vector(void) : size(0)
{
}

Vector    &Vector::operator = (const Vector &toCopy)
{
    if (this == &toCopy)
        return (*this);
    vec = toCopy.vec;
    size = toCopy.size;
    return (*this);
}

Vector::Vector(const Vector &toCopy)
{
    (*this) = toCopy;
}

Vector::~Vector(void)
{
}

Vector::Vector(std::vector<int> v) : vec(v), size(v.size())
{
}

std::vector<int> Vector::getVect(void) const
{
    return (vec);
}

int Vector::getSize(void) const
{
    return (size);
}

std::ostream	&operator << (std::ostream &output, const Vector &v)
{
    output << "[";
    for (int i = 0; i < v.getSize(); i++)
    {
        output << v.getVect()[i];
        if (i != v.getSize() - 1)
            output << ", ";
    }
	output << "]";
	return (output);
}


Vector  Vector::add(Vector &v)
{
    if (v.size != v.getSize())
        throw (Vector::DifferentSize());
    for (int i = 0; i < size; i++)
        vec[i] += v.getVect()[i];
    return (*this);
}

Vector  Vector::sub(Vector &v)
{
    if (v.size != v.getSize())
        throw (Vector::DifferentSize());
    for (int i = 0; i < size; i++)
        vec[i] -= v.getVect()[i];
    return (*this);
}

Vector  Vector::scl(int a)
{
    for (int i = 0; i < size; i++)
        vec[i] *= a;
    return (*this);
}

