#ifndef VECTORDATA_H
#define VECTORDATA_H

#include "geometryvectorlib.h"
#include <QString>

class VectorData
{
    QString vector_name;
    Vector<double>* vec;
public:
    explicit VectorData(QString name, Vector<double>& vec);

    void setName(QString name);
    void setVector(Vector<double>& vec);
    QString getName() const;
    Vector<double>* getVector() const;
};

#endif // VECTORDATA_H
