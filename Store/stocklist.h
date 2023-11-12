#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <QObject>
#include "stock.h"
#include "magazine.h"
#include "books.h"
#include <QList>
#include <QAction>

class StockList : public QObject
{
    Q_OBJECT
public:

    static StockList* getInstance();
    void addStock(Stock *s);
    QList<Stock *> getMagazineStock();
    QList<Stock *> getBooksStock();
    QString toString();
    ~StockList();

private:
    explicit StockList(QObject *parent = nullptr);

    static StockList* instance;
    QList<Stock *> magazineList;
    QList<Stock *> booksList;

};

#endif // STOCKLIST_H
