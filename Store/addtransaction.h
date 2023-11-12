#ifndef ADDTRANSACTION_H
#define ADDTRANSACTION_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QTextBrowser>

#include "customerlist.h"
#include "addcustomers.h"
#include "stock.h"
#include "magazine.h"
#include "books.h"
#include "stocklist.h"
#include "transaction.h"

class AddTransaction : public QDialog
{
    Q_OBJECT

public:
    explicit  AddTransaction(QWidget *parent = nullptr);
    ~ AddTransaction();

private:

    QSpinBox *spinQuantity;
    QLabel *lblDisplayType;
    QLabel *lblDisplayTypeText;
    QLabel *lblcustomer;
    QLabel *lblitem;
    QLabel *lblQuantity;
    QPushButton *btnAdd;
    QPushButton *btnDone;
    QComboBox *comboCustomers;
    QComboBox *comboItems;

    //FOR MY TRANSACTIONS
    QString name, type, custName;

    QTextBrowser *display;

    bool listEmpty = false;

private slots:
    void btnAdd_Clicked();
    void btnDone_Clicked();
    void updateCustomerType();

};

#endif // ADDTRANSACTION_H
