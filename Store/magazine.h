#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "stock.h"

class Magazine: public Stock
{
public:
    Magazine();
    Magazine(QString n);
    QString toString() const;
};

#endif // MAGAZINE_H
