#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QByteArray>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHostAddress>
#include <QAbstractSocket>
#include <cstdlib>

class Widget : public QWidget
{
    Q_OBJECT
    private:
    QLabel    *labelIp;
    QLabel    *labelport;
    QLabel    *labelconnectStatus;
    QLabel    *labelRecv;

    QLineEdit *lineEditIP;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditSend;

    QPushButton *buttonConnect;
    QPushButton *buttonSend;

    QHBoxLayout *hboxLayoutOne;
    QHBoxLayout *hboxLayoutTwo;
    QHBoxLayout *hboxLayoutThree;
    QVBoxLayout *vboxLayoutMain;

    QTcpSocket  *tcpSocketClient;




public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
