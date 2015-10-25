#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QList>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>

#define MAX_PORT_LIST 20
namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();
private:
    QList<QString> portname;
    QList<QSerialPort::BaudRate> baurate;
    QList<QSerialPort::DataBits> databits;
    QList<QSerialPort::FlowControl> flowcontrol;
    QList<QSerialPort::Parity> parity;
    QList<QSerialPort::StopBits> stopbits;


public:
    QString GetPortName();
    QSerialPort::BaudRate GetBaurate();
    QSerialPort::DataBits GetDataBits();
    QSerialPort::FlowControl GetFlowControl();
    QSerialPort::Parity GetParity();
    QSerialPort::StopBits GetStopBits();

private:
    void AddPortName();
    void AddBaurate();
    void AddDataBits();
    void AddFlowControl();
    void AddParity();
    void AddStopBits();
public:
    void Refesh_Port();
private:
    Ui::Setting *ui;
};

#endif // SETTING_H
