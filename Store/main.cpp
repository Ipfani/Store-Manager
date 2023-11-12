#include "store.h"
#include <QApplication>
/*
 Assignment no:3 COS3711

 STORE PROGRAM
 =============================================
 -operator should add customers
 -operator should add stock (Books, Magazine)
 -operator should add transactions

 By Mutavhatsindi Ipfani
  =============================================
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Store w;

    w.show();

    return a.exec();
}
