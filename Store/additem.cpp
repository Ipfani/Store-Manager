#include "additem.h"

#include "books.h"
#include "magazine.h"
/*
 *  The purpose is to add stock
 */
AddItem::AddItem(QWidget *parent)
    : QDialog{parent}
{
    QDialog *window = new QDialog;
    window->setWindowIcon(QIcon(":/resource/Images/boxes_3638933.png"));
    window->setWindowTitle("Add Stock");

    stList = StockList::getInstance();

    lblitemName = new QLabel("Item type");
    lblItemType = new QLabel("Name of item");

    comboItemType = new QComboBox;
    comboItemType->addItem(tr("Books"));
    comboItemType->addItem(tr("Magazine"));

    txtnameOfItem = new QLineEdit("");

    btnAdd = new QPushButton("Add");
    btnAdd->setDisabled(true);

    QGridLayout *layout = new QGridLayout(window);

    layout->addWidget(lblitemName, 0, 0);
    layout->addWidget(comboItemType, 0, 1);
    layout->addWidget(lblItemType, 1, 0);
    layout->addWidget(txtnameOfItem, 1, 1);
    layout->addWidget(btnAdd, 2, 1);

    txtnameOfItem->setFocus();

    //Connect
    connect(btnAdd, SIGNAL(clicked(bool)), this, SLOT(addButton_Clicked()));
    connect(txtnameOfItem, SIGNAL(textChanged(QString)), this, SLOT(valueChanged()));

    window->setFixedSize(300,100);
    window->exec();

}

AddItem::~AddItem()
{

}

void AddItem::addButton_Clicked()
{

    if (!txtnameOfItem->text().isEmpty())
    {

        QString type;
        if (comboItemType->currentText() == "Magazine")
        {
            type = "Magazine";
        }else
        {
            type = "Books";
        }

        //Lets manufacture the Stock
        StockFactory* sf;
        Stock* stock = sf->createStock(type, txtnameOfItem->text());

        //Add stock to the list
        stList->addStock(stock);

        //Inform the user
        QMessageBox::information(0, "Stock added successfully.", QString("Stock %1 added to the list")
                                 .arg(stock->getName()), QMessageBox::Ok);

        //Clear and set focus on line edit
        txtnameOfItem->clear();
        txtnameOfItem->setFocus();
        btnAdd->setDisabled(true);

    }else
    {
        QMessageBox::warning(0,"ERROR", QString("Name of %1 can not be empty!").arg(comboItemType->currentText()));
    }
}

void AddItem::valueChanged()
{
    btnAdd->setDisabled(false);
}
