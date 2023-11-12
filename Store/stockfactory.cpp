#include "stockfactory.h"
#include "magazine.h"
#include "books.h"

StockFactory::StockFactory()
{

}

Stock *StockFactory::createStock(QString type, QString n)
{
    if (type == "Magazine")
    {
        return new Magazine(n);
    }else if (type == "Books")
    {
        return new Books(n);
    }
    return nullptr;
}
