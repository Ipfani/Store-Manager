#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

#include "stock.h"
#include "stocklist.h"
#include "books.h"
#include "magazine.h"
#include "stockfactory.h"

class AddItem : public QDialog
{
    Q_OBJECT
public:
    explicit AddItem(QWidget *parent = nullptr);
    ~AddItem();

private slots:
    void addButton_Clicked();
    void valueChanged();

private:

    QPushButton* btnAdd;
    QLabel* lblItemType;
    QLabel* lblitemName;
    QLineEdit* txtnameOfItem;
    QComboBox* comboItemType;

    StockList* stList;
};

#endif // ADDITEM_H
