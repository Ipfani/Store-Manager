#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "customers.h"
#include <QList>
#include <QObject>

class CustomerList
{
public:
    static CustomerList* getInstance();
    void addCustomers(Customers *c);
    QList<Customers*> getCutomersList();
    ~CustomerList();

private:
    QList<Customers*> myCustomers;

    static CustomerList* instance;
    explicit CustomerList();
};

#endif // CUSTOMERLIST_H
