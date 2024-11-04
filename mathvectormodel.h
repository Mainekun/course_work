#ifndef MATHVECTORMODEL_H
#define MATHVECTORMODEL_H

#include <QAbstractListModel>
#include "vectordata.h"

class MathVectorModel : public QAbstractListModel
{
public:
    explicit MathVectorModel(QObject *parent = nullptr);
};

#endif // MATHVECTORMODEL_H
