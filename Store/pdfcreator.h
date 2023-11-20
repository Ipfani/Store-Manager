#ifndef PDFCREATOR_H
#define PDFCREATOR_H
#include <QTextDocument>
#include <QPrinter>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>

//Aim of the file
//Is to create pdf from html string

class PDFCREATOR
{
public:
    PDFCREATOR(QString p);
    void generateDocument();

private:

    QString filePath;
    QString xmlData;
    QTextDocument *document;

};

#endif // PDFCREATOR_H
