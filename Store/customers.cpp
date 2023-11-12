#include "customers.h"

#include <QMessageBox>

Customers::Customers()
{

}

Customers::Customers(QString n)
    : name(n)
{
    name = n;
}

Customers::~Customers()
{
    qDeleteAll(customerTransactions);
    customerTransactions.clear();
}
QString Customers::getName()
{
    return name;
}

void Customers::setName(QString n)
{
    name = n;
}

QList<Transaction *> Customers::getTransactions()
{
    return customerTransactions;
}

void Customers::addTransaction(Transaction *t)
{
    customerTransactions.append(t);
}

QString Customers::toString()
{
    QString message;
    //I will only display customer that have transactions
    if (customerTransactions.size() > 0)
    {
        message.append(QString("Customer name: %1 \n").arg(name));
        foreach (Transaction *trans, customerTransactions) {
            message.append(trans->toString());
            message.append("\n");
        }
    }
    return message;
}
