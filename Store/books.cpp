#include "books.h"

Books::Books()
{

}

Books::Books(QString n)
    :Stock(n)
{
    name = n;
}

QString Books::toString() const
{
    return QString("Book name: %1").arg(name);
}
