#ifndef STOCKFACTORY_H
#define STOCKFACTORY_H

#include "stock.h"

class StockFactory
{
public:
    StockFactory();
    Stock* createStock(QString type, QString n);
};

#endif // STOCKFACTORY_H
