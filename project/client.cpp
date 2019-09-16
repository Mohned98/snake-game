#include "client.h"

client::client(QObject *parent) : QObject(parent)
{
    host = "127.0.0.1";
    port= 8082;
    socket= new QTcpSocket(this);

    qDebug() <<"connecting...";
    socket->connectToHost(host,port);
    if(!socket->waitForConnected(3000))
    {
       qDebug() << "Errors" << socket->errorString();
    }
    connect(socket, SIGNAL(connected()),this, SLOT(slotconnected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(slotdisconnected()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(slotreadyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(slotbytesWritten(qint64)));

}

void client::writeMessage(QByteArray msg)
{
    socket->write(msg);
}

QByteArray client::readingIncomingMsg()
{
    return reading;
}


void client::slotconnected()
{
    qDebug() <<"connected!";
    socket->write("hello server");

}

void client::slotdisconnected()
{
    qDebug() <<"Disconnected!";
}

void client::slotbytesWritten(qint64 bytes)
{
    qDebug() <<"we wrote" << bytes;
}

void client::slotreadyRead()
{
    qDebug() <<"reading...." ;
    qDebug() << socket->readAll();
    reading=socket->readAll();
}
