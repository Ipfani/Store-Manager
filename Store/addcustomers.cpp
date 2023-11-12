#include "addcustomers.h"
/*
 *  The purpose is to add customers to list
 */
AddCustomers::AddCustomers(QWidget *parent)
    : QDialog{parent}
{
    QDialog *window = new QDialog;
    window->setWindowIcon(QIcon(":/resource/Images/AddCustomer.png"));
    window->setWindowTitle("Add Customer");

    //Lets get the Customer instance
    //I made it singleton so that it will be global
    //I will need it back on the transaction widget
    //The client must first add customers so that the instance will exist
    myCustomersList = CustomerList::getInstance();

    lblName = new QLabel("Customer name");
    txtLineEdit = new QLineEdit("");
    btnAdd = new QPushButton("Add");

    QGridLayout *layout = new QGridLayout(window);

    layout->addWidget(lblName, 0, 0);
    layout->addWidget(txtLineEdit, 0, 1);
    layout->addWidget(btnAdd, 1, 1);

    connect(btnAdd, SIGNAL(clicked(bool)), this, SLOT(addButton_Clicked()));

    window->setFixedSize(250,100);
    window->exec();
}

AddCustomers::~AddCustomers()
{

}

void AddCustomers::addButton_Clicked()
{
    if (!txtLineEdit->text().isEmpty())
    {
        Customers *c = new Customers(txtLineEdit->text());
        myCustomersList->addCustomers(c);

        //Inform the user
        QMessageBox::information(0, "Customer added successfully.", QString("Customer %1 added to the list")
                                 .arg(c->getName()), QMessageBox::Ok);
        //Clear
        txtLineEdit->clear();
        txtLineEdit->setFocus();
    }
}
