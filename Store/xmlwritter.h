#ifndef XMLWRITTER_H
#define XMLWRITTER_H

#include "customerlist.h"
#include <QXmlStreamWriter>
#include <QList>
#include <QFile>

#include <QStandardItemModel>

class Xmlwritter
{
public:
    Xmlwritter();
    void writeCustomers(QList<Customers *> customers);
 };

#endif // XMLWRITTER_H
