#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    label = new  QLabel("TCP########################3");
    box = new QVBoxLayout;
    box->addWidget(label);
    setLayout(box);
    tcpServer   =   new QTcpServer(this);
    tcpSocket   =   new QTcpSocket(this);
    tcpServer->listen(QHostAddress::Any, PORT);

    connect(tcpServer, &QTcpServer::newConnection,[=]{
        tcpSocket   =   tcpServer->nextPendingConnection();
        connect(tcpSocket,&QTcpSocket::readyRead,[=]{
            QByteArray array=tcpSocket->readAll();
            QString temp = QString(array);
            label->setText(temp);
          tcpSocket->write(label->text().toUtf8().data());

        });



        });




}

Widget::~Widget()
{
}

