#include "stocklist.h"

#include <QMessageBox>

//Should never be creation of the instance
StockList* StockList::instance = NULL;

//Lets get the instance or create if NULL
StockList* StockList::getInstance()
{
    if (instance == NULL)
    {
        instance = new StockList;
    }
    //else
    return instance;
}

//Getters for my lists
QList<Stock *> StockList::getMagazineStock()
{
    return magazineList;
}

QList<Stock *> StockList::getBooksStock()
{
    return booksList;
}

QString StockList::toString()
{
    QString data;
    for(int x = 0; x < booksList.size(); x++)
    {
        data.append(QString(booksList.at(x)->toString() + "\n"));
    }
    for(int x = 0; x < magazineList.size(); x++)
    {
        data.append(QString(magazineList.at(x)->toString() + "\n"));
    }
    return data;
}

//Lets add stocks...Book, Magazine
void StockList::addStock(Stock *s)
{
    if(dynamic_cast<Magazine *>(s))
    {
        magazineList.append(s);
    }else if (dynamic_cast<Books *>(s))
    {
        booksList.append(s);
    }
}
StockList::~StockList()
{
    qDeleteAll(magazineList);
    qDeleteAll(booksList);
}
StockList::StockList(QObject *parent)
    : QObject{parent}
{

}
