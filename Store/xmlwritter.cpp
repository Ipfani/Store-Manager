#include "xmlwritter.h"
#include <QMessageBox>
#include <QString>

#include <QDebug>

Xmlwritter::Xmlwritter()
{

}

void Xmlwritter::writeCustomers(QList<Customers*> customers)
{
    QString fileName("Storecustomers.xml");
    QFile myfile(fileName);

    QXmlStreamWriter xmlWriter(&myfile);

    if (myfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("_______________ Mutavhatsindi corner store _______________");

        foreach (Customers *currentCustomer, customers)
        {
            if (currentCustomer->getTransactions().size() > 0)
            {
                xmlWriter.writeStartElement("customer");
                xmlWriter.writeAttribute("name", currentCustomer->getName());

                foreach (Transaction *t, currentCustomer->getTransactions())
                {
                    //Transaction Date
                    xmlWriter.writeStartElement("transaction");
                    xmlWriter.writeAttribute("date", (t->getDate().toString("yyyy-MM-dd HH:mm:ss")));
                    xmlWriter.writeStartElement("item");
                    xmlWriter.writeAttribute("name", t->getName());
                    xmlWriter.writeAttribute("type", t->getType());
                    xmlWriter.writeAttribute("quantity", QString::number((t->getQuantity())));
                    xmlWriter.writeEndElement();
                    xmlWriter.writeEndElement();
                }
                xmlWriter.writeEndElement(); //End of store
            }
        }
        xmlWriter.writeEndElement(); //End of store
        xmlWriter.writeEndDocument();

        myfile.close();

        //Create pdf Creator and send it file
        PDFCREATOR mypdf(fileName);
        mypdf.generateDocument();

    }else
    {
        QMessageBox::information(0, "ERROR", "Failed to open file.");
    }
}
