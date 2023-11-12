#include "customerlist.h"
//#include <QObject> //For DeleteAll
#include <QDebug>

CustomerList* CustomerList::instance = NULL;

CustomerList* CustomerList::getInstance()
{
    if (instance == NULL)
    {
        instance = new CustomerList;
    }return instance;
}

void CustomerList::addCustomers(Customers* c)
{
    myCustomers.append(c);
}

QList<Customers *> CustomerList::getCutomersList()
{
    return myCustomers;
}

CustomerList::~CustomerList()
{
    qDeleteAll(myCustomers);
}

CustomerList::CustomerList()
{
}
