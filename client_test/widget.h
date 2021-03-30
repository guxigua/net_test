#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QByteArray>
#include <QLabel>
#include <QVBoxLayout>

#define PORT 5006

class Widget : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QLabel * label;
    QVBoxLayout * box;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
