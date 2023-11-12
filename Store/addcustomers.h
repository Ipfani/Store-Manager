#ifndef ADDCUSTOMERS_H
#define ADDCUSTOMERS_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

#include "customers.h"
#include "customerlist.h"

class AddCustomers : public QDialog
{
    Q_OBJECT

private:
    QPushButton* btnAdd;
    QLabel* lblName;
    QLineEdit* txtLineEdit;

    CustomerList* myCustomersList;

public:
    explicit AddCustomers(QWidget *parent = nullptr);
    ~AddCustomers();

private slots:
    void addButton_Clicked();
};

#endif // ADDCUSTOMERS_H
