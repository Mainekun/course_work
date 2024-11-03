#ifndef VECLIB_H
#define VECLIB_H

#include "vecexceptions.h"
#include <iostream>
#include <list>
#include <cmath>

template <class T>
concept Numeric =
    (std::is_integral<T>::value ||
     std::is_floating_point<T>::value) &&
    std::is_signed<T>::value;


using st = std::size_t;

template <Numeric CoordType>
class MathVector {
    CoordType * const _elementsArray;
    st _vecSize;

public:
    friend void sizeScan(MathVector<CoordType>& a, MathVector<CoordType>& b)
    {
        if (!isSizesEqual(a, b))
            throw sizesAreNotEqualException("");
    }

    MathVector(st size, CoordType* elements) :
        _vecSize(size),
        _elementsArray(new CoordType[size])
    {
        for (st i = 0; i < size; i++)
            _elementsArray[i] = elements[i];
    }

    MathVector(st size, CoordType filler) :
        _vecSize(size),
        _elementsArray(new CoordType[size])
    {
        for (st i = 0; i < size; i++)
            _elementsArray[i] = filler;
    }

    MathVector() :
        _vecSize(0),
        _elementsArray(nullptr)
    {

    }

    ~MathVector()
    {
        delete[] _elementsArray;
    }

    MathVector(MathVector<CoordType>& a) :
        _vecSize(a._vecSize),
        _elementsArray(new CoordType[a._vecSize])
    {
        for (st i = 0; i < _vecSize; i++)
            _elementsArray[i] = a._elementsArray[i];
    }

    st size() { return _vecSize; }
    bool isZeroSize(){ return !_vecSize; }

    friend bool isSizesEqual(MathVector<CoordType>& a, MathVector<CoordType>& b)
    { return !(a._vecSize - b._vecSize); }

    friend bool isVectorsEqual(MathVector<CoordType>& a, MathVector<CoordType>& b)
    {
        if (!isSizesEqual(a, b)) return false;

        for (st i = 0; i < a._vecSize; i++)
            if (a._elementsArray[i] != b._elementsArray[i])
                return false;

        return true;
    }

    CoordType& at(st index)
    {
        if (index >= _vecSize) std::out_of_range("");

        return _elementsArray[index];
    }

    MathVector<CoordType> operator+(MathVector<CoordType> a)
    {
        sizeScan(*this, a);

        MathVector<CoordType> b = MathVector(_vecSize, (double)0);

        for (st i = 0; i < _vecSize; i++)
            b.at(i) = this->at(i) + a.at(i);

        return b;
    }

    MathVector<CoordType> operator-(MathVector<CoordType> a)
    {
        sizeScan(*this, a);

        MathVector<CoordType> b = MathVector(_vecSize, (double)0);

        for (st i = 0; i < _vecSize; i++)
            b.at(i) = this->at(i) - a.at(i);

        return b;
    }

    MathVector<CoordType> operator*(CoordType k)
    {
        MathVector<CoordType> b(*this);

        for (st i = 0; i < _vecSize; i++)
            b.at(i) *= k;

        return b;
    }

    MathVector<CoordType> operator-()
    {
        MathVector<CoordType> b(*this);

        for (st i = 0; i < _vecSize; i++)
            b.at(i) *= -1;

        return b;
    }


    CoordType mod()
    {
        CoordType vecModule = 0;

        for (st i = 0; i < _vecSize; i++)
            vecModule += this->at(i) * this->at(i);

        return std::sqrt((double)vecModule);
    }

    CoordType sumElements()
    {
        CoordType sum = 0;

        for (st i = 0; i < _vecSize; i++)
            sum += this->at(i);

        return sum;
    }

    CoordType prodElements()
    {
        CoordType prod = 1;

        for (st i = 0; i < _vecSize; i++)
            prod *= this->at(i);

        return prod;
    }

    std::list<st> MaxsIndices()
    {
        if (_vecSize == 0) return std::list<st>();

        CoordType maxElem = _elementsArray[0];

        for (st i = 0; i < _vecSize; i++)
            if (maxElem < this->at(i))
                maxElem = this->at(i);

        std::list<st> indices;

        for (st i = 0; i < _vecSize; i++)
            if (this->at(i) == maxElem)
                indices.push_back(i);

        return indices;
    }

    std::list<st> MinsIndices()
    {
        if (_vecSize == 0) return std::list<st>();

        CoordType minElem = _elementsArray[0];

        for (st i = 0; i < _vecSize; i++)
            if (minElem > this->at(i))
                minElem = this->at(i);

        std::list<st> indices;

        for (st i = 0; i < _vecSize; i++)
            if (this->at(i) == minElem)
                indices.push_back(i);

        return indices;
    }

    CoordType scalarProd(MathVector<CoordType> a)
    {
        sizeScan(a, *this);

        CoordType scalarResult = 0;

        for (st i = 0; i < a.size(); i++)
            scalarResult += a.at(i) * this->at(i);

        return scalarResult;
    }

    MathVector<CoordType> vectorProd(MathVector<CoordType> a)
    {
        sizeScan(a, *this);
        if (a.size() != 3) throw notA3DVectorException("");

        MathVector<CoordType> c = MathVector<CoordType>((st)3, (double)0);

        c.at(0) = this->at(1) * a.at(2) - this->at(2) * a.at(1);
        c.at(1) = - this->at(0) * a.at(2) + this->at(2) * a.at(0);
        c.at(2) = this->at(0) * a.at(1) - this->at(1) * a.at(0);

        return c;
    }

};

#endif
