#ifndef VECTORDATA_H
#define VECTORDATA_H

#include <string>
#include <geometryvectorlib.h>

class VectorData
{
    std::string name;
    MathVector<double>* vec;
public:
    VectorData() = delete;
    VectorData(std::string, MathVector<double>);
    std::string getName();
    MathVector<double> getVec();
    void setName(std::string);
    void setVec(MathVector<double>);
};

#endif // VECTORDATA_H
