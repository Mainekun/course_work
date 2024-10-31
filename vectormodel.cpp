#include "vectormodel.h"

VectorModel::VectorModel(QObject *parent)
    : QAbstractListModel{parent}
{
    Vector<double> avec = Vector<double>(2, new double[]{1, 2});
    VectorData a = VectorData("a", avec);
    vec_list.append(a);
}


int VectorModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return vec_list.size();
}


QVariant VectorModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(Qt::DisplayRole == role)
        return vec_list.at(index.row()).getName();

    return QVariant();

}


QHash<int, QByteArray> VectorModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();

    roles[NameRole] = "name";
    roles[ElementsRole] = "vector";

    return roles;
}


