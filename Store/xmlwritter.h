#ifndef XMLWRITTER_H
#define XMLWRITTER_H

#include "pdfcreator.h"
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

private:
    PDFCREATOR *pdfCreator;
 };

#endif // XMLWRITTER_H
