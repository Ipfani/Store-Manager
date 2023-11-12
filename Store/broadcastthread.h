#ifndef BROADCASTTHREAD_H
#define BROADCASTTHREAD_H

#include <QObject>
#include <QThread>
#include <QUdpSocket>
#include <QFile>
#include <QMessageBox>

class BroadcastThread : public QObject
{
    Q_OBJECT
public:
    explicit BroadcastThread(QObject *parent = nullptr);
    ~BroadcastThread();

private slots:
    void broadcastXML();

private:
    //My socket
    QUdpSocket *socket = nullptr;

};

#endif // BROADCASTTHREAD_H
