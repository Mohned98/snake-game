#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QByteArray>
class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);

private:
    QString host;
    int port;
    QByteArray reading;
    QTcpSocket *socket;
public:
    void writeMessage(QByteArray);
    QByteArray readingIncomingMsg();


signals:

public slots:
    void slotconnected();
    void slotdisconnected();
    void slotbytesWritten(qint64 bytes);
    void slotreadyRead();
};

#endif // CLIENT_H
