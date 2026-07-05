#include "client.h"
#include "ui_client.h"
#include <QTcpSocket>
#include <QCoroNetwork>
#include <QMessageBox>
#include <QDebug>

client::client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}

void client::on_sendButton_clicked()
{
    QString host = "127.0.0.1";
    quint16 port = 54321;
    QString message = ui->messagelineEdit->text();

    if (!message.isEmpty()) {
        sendNetworkMessage(host, port, message);
    }
}

QCoro::Task<void> client::sendNetworkMessage(QString host, quint16 port, QString message)
{
    QTcpSocket socket;

co_await qCoro(socket).connectToHost(host, port);
    if (socket.isOpen()) {
        socket.write(message.toUtf8());
        ui->messagelineEdit->clear();
        QMessageBox::information(this, "Success", "Message sent to server!");
    } else {
        qDebug() << "Could not connect to server";
        QMessageBox::critical(this, "Error", "Make sure the server is running!");
    }
}