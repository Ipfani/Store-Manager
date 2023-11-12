#ifndef STORE_H
#define STORE_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QActionGroup>
#include <QToolBar>
#include <QGridLayout>

#include <QStandardItemModel>
#include <QTreeView>

#include "additem.h"

//For receiving the Customerlist for XML
#include "customerlist.h"
//#include <QUdpSocket> //For broadcasting

//Testing output
#include <QMessageBox>
#include "xmlwritter.h"
#include "about.h"

//For the threading
#include <QThread>
#include "broadcastthread.h"

class Store : public QMainWindow
{
    Q_OBJECT

public:
    Store(QWidget *parent = nullptr);
    ~Store();
    void displayToMainGui();

    //Temporal methods that will be run from the addtransaction widget
    void write();
    void runthread();

private:
    QMenu* menuFile;
    QMenu* menuAdd;
    QMenu* menuRestore;
    QMenu* menuAbout;
    QActionGroup* addGroup;
    QActionGroup* aboutGroup;
    QActionGroup* restoreGroup;

    QStandardItemModel *model;
    QTreeView *treeView;

    //My socket
   // QUdpSocket *socket = nullptr;
    BroadcastThread *bdcastThread;
    QThread thread;

    Xmlwritter *writer;

private slots:
    void handleAction(QAction *a);
    void handleAbout();
   // void broadcastXML();

};

#endif // STORE_H
