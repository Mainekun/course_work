#include "vectordata.h"

VectorData::VectorData(QString name, Vector<double>& vec)
    : vector_name(name), vec(new Vector(vec)) {}

void
VectorData::setName(QString name)
{ vector_name = name; }

void
VectorData::setVector(Vector<double>& vec)
{ this->vec = new Vector<double>(vec); }

QString
VectorData::getName() const
{ return vector_name; }

Vector<double>*
VectorData::getVector() const
{ return vec; }
