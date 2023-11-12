#ifndef BOOKS_H
#define BOOKS_H

#include "stock.h"

class Books: public Stock
{
public:
    Books();
    Books(QString n);
    QString toString() const;
};

#endif // BOOKS_H
