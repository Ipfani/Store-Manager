#include "magazine.h"

Magazine::Magazine()
{

}

Magazine::Magazine(QString n)
    : Stock(n)
{
    name = n;
}

QString Magazine::toString() const
{
    return QString("Magazine name: %1").arg(name);
}
