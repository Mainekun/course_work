#ifndef GEOMETRYVECTORLIB_H
#define GEOMETRYVECTORLIB_H

#include <iostream>
#include <list>
#include "vectorexceptions.h"

template <typename T>
concept Numeric = std::convertible_to<T, int>;

template <Numeric ctype>
class Vector;
template <Numeric ctype>
class Vector3d;

template <Numeric ctype>
class Vector {
    ctype * const elements_array;
    std::size_t vector_size;

    using cptr = ctype*;
    using cref = ctype&;
    using stype = std::size_t;

    using vptr = Vector*;
    using vref = Vector&;

public:
    //
    //constructors & destructors
    //

    Vector(std::size_t vector_size, ctype * elements_array)
        : vector_size(vector_size), elements_array(new ctype[vector_size])
    {
        for (stype i = 0;
             i < vector_size;
             i++)
        {
            this->elements_array[i] = elements_array[i];
        }
    }
    Vector(std::size_t vector_size, ctype element_to_fill = 0)
        : vector_size(vector_size), elements_array(new ctype[vector_size])
    {
        for (cptr elem = elements_array;
             elem - elements_array != vector_size;
             elem++)
        {
            elem = element_to_fill;
        }
    }
    Vector() : vector_size(0), elements_array(nullptr) {}

    ~Vector() { delete[] elements_array; vector_size = 0; }


    stype size() { return vector_size; }

    Vector(Vector& a)
        : elements_array(new ctype[a.size()]),
        vector_size(a.size())
    {
        for (stype i = 0; i < vector_size; i++)
            elements_array[i] = a[i];
    }

    friend bool isSizesEqual(vref a, vref b) { return a.vector_size == b.vector_size; }
    friend bool isVectorsEqual(vref a, vref b)
    {
        if (!isSizesEqual(a,  b)) return false;

        for (stype i = 0; i < a.vector_size; i++)
            if (a.elements_array[i] != b.elements_array[i]) return false;

        return true;
    }
    bool isZeroSize() { return vector_size == 0; }

    cref operator[](stype index) {
        if (index >= vector_size) throw std::out_of_range("");
        return elements_array[index];
    }

    vref operator+(vref a)
    {
        Vector b(a.size());

        for (stype i = 0; i < a.size(); i++)
            b[i] = *this[i] + a[i];

        return b;
    }

    vref operator-(vref a)
    {
        Vector b(a.size());

        for (stype i = 0; i < a.size(); i++)
            b[i] = *this[i] - a[i];

        return b;
    }

    vref operator*(ctype k)
    {
        Vector b(vector_size);

        for (stype i = 0; i < vector_size; i++)
            b[i] = *this[i] * k;

        return b;
    }

    vref operator-(int)
    {
        Vector b(*this);

        for (stype i = 0; i < vector_size; i++)
            b[i] *= -1;

        return b;
    }

    ctype module()
    {
        ctype mod = 0;

        for (stype i = 0; i < vector_size; i++)
            mod += elements_array[i] * elements_array[i];

        return mod;
    }

    ctype sumOfElements()
    {
        ctype sum = 0;

        for (stype i = 0; i < vector_size; i++)
            sum += elements_array[i];

        return sum;
    }

    ctype productOfElements()
    {
        ctype product = 1;

        for (stype i = 0; i < vector_size; i++)
            product *= elements_array[i];

        return product;
    }

    std::list<stype> indexOfMax()
    {
        if (vector_size == 0) return std::list<stype>(0);

        ctype max_element = elements_array[0];

        for (stype i = 1; i < vector_size; i++)
            if (max_element < elements_array[i])
                max_element = elements_array[i];

        std::list<stype> indices;

        for (stype i = 0; i < vector_size; i++)
            if (max_element == elements_array[i])
                indices.push_back(i);

        return indices;
    }

    std::list<stype> indexOfMin()
    {
        if (vector_size == 0) return std::list<stype>(0);

        ctype min_element = elements_array[0];

        for (stype i = 1; i < vector_size; i++)
            if (min_element > elements_array[i])
                min_element = elements_array[i];

        std::list<stype> indices;

        for (stype i = 0; i < vector_size; i++)
            if (min_element == elements_array[i])
                indices.push_back(i);

        return indices;
    }

    friend ctype scalarProduct(vref a, vref b)
    {
        if (!isSizesEqual(a, b)) throw different_sizes((char*)"diff size"); // exception

        ctype product = 0;

        for (stype i = 0; i < a.size(); i++)
            product += a[i] * b[i];

        return product;
    }


};

template <Numeric ctype>
class Vector3d : public Vector<ctype> {
    using cref = ctype&;
    using cptr = ctype*;

    using stype = std::size_t;

    const std::size_t vector_size = 3;
    cptr const elements_array;
public:
    Vector3d(stype vector_size, cptr elements)
    {
        if (vector_size != 3)
            throw std::runtime_error("size doesnt equal 3");

        elements_array =
            new ctype[]{elements[0], elements[1], elements[2]};
    }

    Vector3d(ctype i) : elements_array(new ctype[]{i,i,i}) {};

    friend cref vectorProduct(cref a, cref b)
    {
        return Vector3d(3,
                        {
                            a[1]  *b[2] - a[2] * b[1],
                            a[0] * b[2] - a[2] * b[0],
                            a[0] * b[1] - a[1] * b[0]
                        });
    }
};

#endif // GEOMETRYVECTORLIB_H
