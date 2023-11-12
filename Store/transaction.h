#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDateTime>

class Transaction
{

public:
    Transaction(QDateTime d, int q, QString n, QString t);
    ~Transaction();
    Transaction();
    void setDate(QDateTime d);
    void setQuantity(int q);
    void setName(QString n);
    void setType(QString t);

    QDateTime getDate();
    int getQuantity();
    QString getName();
    QString getType();

    QString toString();

private:
    QDateTime date;
    int quantity;
    QString name;
    QString type;

};

#endif // TRANSACTION_H
