# Store-Manager
![Add Transaction](https://github.com/Ipfani/Store-Manager/assets/150608520/a0e7dfb8-4d9d-4fc0-ac6f-47aeda524dbc)


**Concepts.**

* Design Patterns
  * Singleton
  * Factory
  * Composite
  * Agregate
* Model and View
  * QStandardItemModel
  * QTreeView 
* Inheritance (Abstract - Pure virtual)
* XML writter
* Threads (QThread)
* UDP Broadcast

* No drag and Drop GUI
* Store Application
  * Keeps track of customer names when an Item (Book or Magazine)
  * Composite
  * Agregate

* QT C++ (CMAKE)
  
* Challenges
  * Implementation of the Undo using the Memento Design Pattern


**Sample Code**
<br/>
* SingleTon
```
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

```

* Factory Design Pattern
```
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

```

* Broadcast XML
```
#ifndef BROADCASTTHREAD_H
#define BROADCASTTHREAD_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QFile>
#include <QMessageBox>

class BroadcastThread : public QObject
{
    Q_OBJECT
public:
    explicit BroadcastThread(QObject *parent = nullptr);
    ~BroadcastThread();

private slots:
    void broadcastXML();

private:
    //My socket
    QUdpSocket *socket = nullptr;

};

#endif // BROADCASTTHREAD_H
```
