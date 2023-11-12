#include "transaction.h"

Transaction::Transaction(QDateTime d, int q, QString n, QString t)
    :date(d), quantity(q), name(n), type(t)
{

}

Transaction::~Transaction()
{

}

Transaction::Transaction()
{

}

void Transaction::setDate(QDateTime d)
{
    date = d;
}

void Transaction::setName(QString n)
{
    name = n;
}

void Transaction::setQuantity(int q)
{
    quantity = q;
}

void Transaction::setType(QString t)
{
    type = t;
}

QDateTime Transaction::getDate()
{
    return date;
}

int Transaction::getQuantity()
{
    return quantity;
}

QString Transaction::getName()
{
    return name;
}

QString Transaction::getType()
{
    return type;
}

QString Transaction::toString()
{
    return (QString("Item: %1 , Quantity: %2 , Purchased date: %3 ").arg(name)
            .arg(quantity).arg(date.toString("yyyy-MM-dd HH:mm:ss")));
}
