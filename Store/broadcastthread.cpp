#include "broadcastthread.h"
#include <QDebug>

BroadcastThread::BroadcastThread(QObject *parent)
    : QObject{parent}
{
    //Creating instance of UDP Socket
    socket = new QUdpSocket(this);
}

BroadcastThread::~BroadcastThread()
{
    socket->close();
    delete socket;
}

void BroadcastThread::broadcastXML()
{
    //The user have to input the data into the application first

    QFile file("Storecustomers.xml");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Thread for xml broadcast running.";

        QByteArray byte = file.readAll();

        socket->writeDatagram(byte, QHostAddress::Broadcast, 40000);

        file.close();
    }else
    {
        qDebug() << QString("Thread Failed to open xml document, ensure the file %1 exists").arg(file.fileName());
    }
    this->deleteLater();
}
