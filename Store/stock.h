#ifndef STOCK_H
#define STOCK_H

#include <QObject>

class Stock : public QObject
{
    Q_OBJECT

public:
    Stock();
    Stock(QString n);

    QString getName();
    void setName(QString n);
    virtual QString toString() const = 0;

protected:
    QString name;
};

#endif // STOCK_H
