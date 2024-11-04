#include "vectordata.h"

VectorData::VectorData(std::string name2, MathVector<double> vec2)
{
    this->name = name2;
    this->vec = new MathVector(vec2);
}

inline
std::string
VectorData::getName() { return this->name; }

inline
MathVector<double>
VectorData::getVec() { return *(this->vec); }

inline
void
VectorData::setName(std::string name2)
{ this->name = name2; }

inline
void
VectorData::setVec(MathVector<double> vec2)
{ this->vec = new MathVector<double>(vec2); }
