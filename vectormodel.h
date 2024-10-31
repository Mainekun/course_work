#ifndef VECTORMODEL_H
#define VECTORMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include <geometryvectorlib.h>
#include "vectordata.h"


class VectorModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        NameRole = Qt::UserRole + 1,
        ElementsRole
    };

    explicit VectorModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

private:
    QVector<VectorData> vec_list;
};

#endif // VECTORMODEL_H
