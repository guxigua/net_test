#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    tcpSocketClient =   new QTcpSocket;
    labelIp            =  new  QLabel("IP & Port: ");
    labelport          =  new  QLabel("&");
    labelconnectStatus =  new  QLabel(":");
    labelRecv          =  new  QLabel;

    lineEditIP   =   new QLineEdit;
    lineEditPort =   new QLineEdit;
    lineEditSend =   new QLineEdit;

    buttonConnect   =   new QPushButton("Connect");
    buttonSend      =   new QPushButton("Send");
    buttonSend->setEnabled(false);

    connect(buttonConnect,&QPushButton::clicked,[=](){       //发起连接并检测连接状态
        qint16 port =   lineEditPort->text().toInt();
        tcpSocketClient->connectToHost(QHostAddress(lineEditIP->text()),port);
        connect(tcpSocketClient,&QTcpSocket::connected,[=](){
            labelconnectStatus->setText(" : <font color=green size=4>connect success</font>");
            buttonSend->setEnabled(true);
        });
    });
    connect(tcpSocketClient,&QTcpSocket::disconnected,[=](){
        labelconnectStatus->setText(" : <font color=red size=4>disconnect!</font>");
        buttonSend->setEnabled(false);
    });



    connect(buttonSend, &QPushButton::clicked, [=](){         //发送数据
        tcpSocketClient->write(lineEditSend->text().toUtf8().data());
    });

    connect(tcpSocketClient,&QTcpSocket::readyRead,[=](){  //接受数据
        QByteArray array=tcpSocketClient->readAll();
        QString str = QString("<font color=green>receve: </font>");
        str += array;
            labelRecv->setText(str);

    });

    hboxLayoutOne   =   new QHBoxLayout;     //第一行
    hboxLayoutOne->addWidget(labelIp);
    hboxLayoutOne->addWidget(lineEditIP);
    hboxLayoutOne->addWidget(labelport);
    hboxLayoutOne->addWidget(lineEditPort);

    hboxLayoutTwo   =   new QHBoxLayout;        //第二行
    hboxLayoutTwo->addWidget(buttonConnect);
    hboxLayoutTwo->addWidget(labelconnectStatus);

    hboxLayoutThree =   new QHBoxLayout;        //第三行
    hboxLayoutThree->addWidget(lineEditSend);
    hboxLayoutThree->addWidget(buttonSend);


    vboxLayoutMain  =   new QVBoxLayout;
    vboxLayoutMain->addLayout(hboxLayoutOne);
    vboxLayoutMain->addLayout(hboxLayoutTwo);
    vboxLayoutMain->addLayout(hboxLayoutThree);
    vboxLayoutMain->addWidget(labelRecv);
    setLayout(vboxLayoutMain);






}

Widget::~Widget()
{
}

