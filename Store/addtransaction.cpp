#include "addtransaction.h"
#include "stock.h"
#include "store.h"

#include <QMessageBox>

AddTransaction::AddTransaction(QWidget *parent)
    : QDialog{parent}
{
    QDialog *window = new QDialog;

    window->setWindowIcon(QIcon(":/resource/Images/transaction.png"));
    window->setWindowTitle("Add Transaction");

    QGridLayout *layout = new QGridLayout(window);

    lblcustomer = new QLabel("Select customer:");
    lblitem = new QLabel("Select item:");
    lblDisplayType = new QLabel("");
    lblDisplayTypeText = new QLabel("Item type:");
    lblQuantity = new QLabel("Item quantity:");

    display = new QTextBrowser();

    spinQuantity = new QSpinBox();
    btnAdd = new QPushButton("Add");
    btnDone = new QPushButton("Done");

    comboCustomers = new QComboBox;
    comboItems = new QComboBox;

    //Lets add customers to combobox
    foreach (Customers* customer, CustomerList::getInstance()->getCutomersList()) {
        comboCustomers->addItem(customer->getName());
    }

    //Lets combo the items
    //......REMEMBER I am not receiving an instance of stocklist...FIX IT!!!!!
    foreach (Stock* stock, StockList::getInstance()->getBooksStock() + StockList::getInstance()->getMagazineStock()) {
        comboItems->addItem(stock->getName());
    }

    //Lets update
    updateCustomerType();

    layout->addWidget(lblcustomer, 0, 0);
    layout->addWidget(comboCustomers, 0, 1);
    layout->addWidget(lblitem, 1,0);
    layout->addWidget(comboItems, 1, 1);
    layout->addWidget(lblDisplayTypeText, 2, 0);
    layout->addWidget(lblDisplayType, 2, 1);
    layout->addWidget(lblQuantity, 3, 0);
    layout->addWidget(spinQuantity, 3, 1);
    layout->addWidget(btnAdd, 3, 2);
    layout->addWidget(display, 4, 0, 5, 3);
    layout->addWidget(btnDone, 9, 1);

    connect(btnAdd, SIGNAL(clicked(bool)), this, SLOT(btnAdd_Clicked()));
    connect(btnDone, SIGNAL(clicked(bool)), this, SLOT(btnDone_Clicked()));

    //Update the type when combo value changed
    connect(comboItems, SIGNAL(currentTextChanged(QString)), this, SLOT(updateCustomerType()));

    window->setFixedSize(500, 400);
    window->exec();
}

AddTransaction::~AddTransaction()
{

}

void AddTransaction::btnAdd_Clicked()
{
    if (spinQuantity->text().toInt() < 1 || comboItems->currentText().isEmpty() || comboCustomers->currentText().isEmpty())
    {
        QMessageBox::warning(0, "Input Error", "Required inputs are invalid");
    }else
    {
        custName = comboCustomers->currentText();
        name = comboItems->currentText();

        Customers *tempCustomer;

        Transaction* trans = new Transaction(QDateTime::currentDateTime(), spinQuantity->text().toInt(), name, type);

        int position;
        for (int x = 0; x < CustomerList::getInstance()->getCutomersList().size(); x++)
        {
            //Get position of a selected customer name from the gui
            if(custName == CustomerList::getInstance()->getCutomersList().at(x)->getName())
            {
                position = x;
                tempCustomer = CustomerList::getInstance()->getCutomersList().at(x);
                tempCustomer->addTransaction(trans);
            }
        }
        //Inform the user
        QMessageBox::information(0, "Transactions added successfully.", QString("Transaction for %1 added to the list."
                                                                                "Do not forget to click Done when you finished.")
                                 .arg(tempCustomer->getName()), QMessageBox::Ok);
        spinQuantity->setValue(0); //Reset to zero
    }
}

void AddTransaction::btnDone_Clicked()
{
    if (listEmpty)
    {
        QMessageBox::warning(0, "INPUT ERROR", "We can not display empty transactions");
    }else
    {
        //Lets display on the text browser
        QString bigMessage;

        foreach (Customers *customer, CustomerList::getInstance()->getCutomersList()) {
            bigMessage.append(customer->toString());
            bigMessage.append("\n");
        }
        display->setText(bigMessage);

        //It is the best way to avoid writting transactions while user did not click done.
        Store *st = new Store();
        //st->displayToMainGui();
        //That temporal method
        st->write();
        st->runthread();
    }
}

void AddTransaction::updateCustomerType()
{
    //Display itme type on the GUI
    foreach (Stock* stock, StockList::getInstance()->getBooksStock() + StockList::getInstance()->getMagazineStock()) {
        if (comboItems->currentText() == stock->getName())
        {
            if(dynamic_cast<Magazine *>(stock))
            {
                type = "Magazine";
            }else if (dynamic_cast<Books *>(stock))
            {
                type = "Books";
            }
        }
    }
    lblDisplayType->setText(type);
}

