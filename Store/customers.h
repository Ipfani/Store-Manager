#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QString>
#include "transaction.h"

class Customers
{
private:
    QString name;

    //Customer have a list of transaction under their name
    //When they purchase something
    //I will not be creating a TransactionList class
    QList <Transaction*> customerTransactions;

public:
    QString getName();
    void setName(QString n);
    QList <Transaction *>getTransactions();
    void addTransaction(Transaction *t);
    QString toString();
    Customers();
    Customers(QString n);
    ~Customers();
};
#endif // CUSTOMERS_H
