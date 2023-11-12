#include "store.h"
#include "addcustomers.h"
#include "addtransaction.h"

#include "additem.h"

#include <QToolBar>
#include <QXmlStreamWriter>
#include <QDebug>


Store::Store(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Mutavhatsindi Store");
    setWindowIcon(QIcon(":/resource/Images/Main.png"));
    setFixedSize(600, 600);

    //Creating instance of UDP Socket
    //socket = new QUdpSocket(this);
    bdcastThread = new BroadcastThread();
    thread.setObjectName("Broadcast thread");
    bdcastThread->moveToThread(&thread);

    //Writter
    writer = new Xmlwritter();

    addGroup = new QActionGroup(this);
    addGroup->addAction(new QAction(QIcon(":/resource/Images/AddCustomer.png"), tr("&Customer")));
    addGroup->addAction(new QAction(QIcon(":/resource/Images/boxes_3638933.png"), tr("&Stock")));
    addGroup->addAction(new QAction(QIcon(":/resource/Images/transaction.png"), tr("&Transaction")));

    aboutGroup = new QActionGroup(this);
    aboutGroup->addAction(new QAction(QIcon(":/resource/Images/gear.png"), tr("Developer")));

    restoreGroup = new QActionGroup(this);
    restoreGroup->addAction(new QAction("&Undo"));

    //QGridLayout *layout = new QGridLayout(this);
    model = new QStandardItemModel;
    treeView = new QTreeView;

    treeView->setModel(model);

    menuFile = menuBar()->addMenu("&File");

    menuAdd = menuBar()->addMenu("&Add");
    menuAdd->addActions(addGroup->actions());

    menuRestore = menuBar()->addMenu("&Restore");
    menuRestore->addActions(restoreGroup->actions());

    menuAbout = menuBar()->addMenu("&About");
    menuAbout->addActions(aboutGroup->actions());

    connect(addGroup, SIGNAL(triggered(QAction*)), this, SLOT(handleAction(QAction*)));
    connect(aboutGroup, SIGNAL(triggered(QAction*)), this, SLOT(handleAbout()));

    //Connect the thread
    connect(&thread, SIGNAL(started()), bdcastThread, SLOT(broadcastXML()));

    //this->layout()->addWidget(menuBar());
    treeView->setFixedWidth(this->width());
    treeView->setFixedHeight(this->height());

    //I will display on the main gui
    //After Adding transactions

    treeView->expandAll();
    setCentralWidget(treeView);

}

Store::~Store()
{
    //socket->close();
    //delete socket;
}

void Store::displayToMainGui()
{
    //Do not reprint
    //Clear the data
    model->clear();
    if (CustomerList::getInstance()->getCutomersList().size() > 0)
    {
        QModelIndex index;
        foreach (Customers *currentCustomer, CustomerList::getInstance()->getCutomersList())
        {
            //Add customer with transactions only
            if (currentCustomer->getTransactions().size() > 0)
            {
                QList<QStandardItem*> customers;

                //Customer name
                customers << new QStandardItem(QString(currentCustomer->getName()));
                model->invisibleRootItem()->appendRow(customers);

                int transactionSize = currentCustomer->getTransactions().size();
                for (int row = 0; row < transactionSize; row++)
                {
                    QList<QStandardItem*> transactionDate;
                    //Transaction Date
                    transactionDate << new QStandardItem(QString(currentCustomer->getTransactions().at(row)->getDate().toString()));
                    customers.constFirst()->appendRow(transactionDate);

                    //Add stock items
                    QList<QStandardItem*> item;
                    item << new QStandardItem(QString("Name: %1\t Type: %2 \tQuantity: %3").arg(currentCustomer->getTransactions().at(row)->getName())
                                              .arg(currentCustomer->getTransactions().at(row)->getType())
                                              .arg(currentCustomer->getTransactions().at(row)->getQuantity()));
                    transactionDate.constFirst()->appendRow(item);
                }
            }
        }

    }
}

void Store::write()
{
    //Write to XML TEST
    writer->writeCustomers(CustomerList::getInstance()->getCutomersList());
}

void Store::runthread()
{
    //Broadcast test
    //broadcastXML();
    //Start the thread
    //Here becuase at this point, the user have already being forced to input data to program
    thread.start();
}

void Store::handleAction(QAction* a)
{
    if (a->text() == "&Stock")
    {
        AddItem addItem;
    }else if (a->text() == "&Customer")
    {
        AddCustomers addcustomers;
    }else if (a->text() == "&Transaction")
    {
        //Lets not add transaction without having customers
        if (CustomerList::getInstance()->getCutomersList().size() < 1)
        {
            QMessageBox::warning(0, "Customers Input Error", "We canot add Transactions without customers.\n"
                                                             "Please add customers first.", QMessageBox::Ok);
        }else
        {
            AddTransaction addtransaction;
            displayToMainGui();
        }
    }
}

void Store::handleAbout()
{
    About abt;
}

/*
 * void Store::broadcastXML()
{
    QFile file("Storecustomers.xml");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray ba = file.readAll();

        socket->writeDatagram(ba, QHostAddress::Broadcast, 3400);

        file.close();
    }
}
*/
