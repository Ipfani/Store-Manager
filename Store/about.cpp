#include "about.h"

About::About(QWidget *parent)
    : QWidget{parent}
{
    QDialog *window = new QDialog;
    showData = new QLabel();

    QString msg = "Assignment no: 3 COS3711"
                  "\nMutavhatsindi Ipfani"
                  "\n"
                  "\nEmail: 62356445@mylife.unisa.ac.za"
                  "\n"
                  "\nLisence: Free ware (Lawless)"
                  "\n";

    showData->setStyleSheet("font: bold; font-family: Arial; font-size:15px;"
                            "background-color:#A9C7F9; border: 1px solid black;");
    window->setStyleSheet("background-color:#BE7318");
    showData->setText(msg);


    QGridLayout *layout = new QGridLayout(window);

    layout->addWidget(showData, 0, 0);

    window->setWindowTitle("Developers!");
    window->setFixedSize(400,200);
    window->exec();
}

About::~About()
{

}
