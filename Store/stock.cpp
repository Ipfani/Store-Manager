#include "stock.h"
#include <QDebug>

Stock::Stock()
{

}

Stock::Stock(QString n)
{
    name = n;
}

QString Stock::getName()
{
    return name;
}

void Stock::setName(QString n)
{
    name = n;
}
