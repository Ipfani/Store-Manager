#include "pdfcreator.h"

PDFCREATOR::PDFCREATOR(QString p)
    :filePath(p)
{
    document = new QTextDocument();
}

void PDFCREATOR::generateDocument( )
{

    QPrinter printer;
    QFile file(filePath);
    QXmlStreamReader reader(&file);

    if (file.open(QIODevice::ReadWrite))
    {
        xmlData = file.readAll();

        document->setPlainText(xmlData);

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("Store_data.pdf");
        printer.setPageMargins(QMarginsF(2, 2, 2, 2));
        document->print(&printer);
        QMessageBox::information(0,"Pdf Created!", "Store_data.pdf created successfully.");

    }else
    {
        QMessageBox::warning(0,"Error", "File could not be open");
    }
}
