#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    AddPortName();
    AddBaurate();
    AddDataBits();
    AddFlowControl();
    AddParity();
    AddStopBits();
}

Setting::~Setting()
{
    delete ui;
}
void Setting::AddPortName()
{
    for (int i = 0; i<MAX_PORT_LIST; i++)
        portname << "ttyUSB" + QString::number(i);
    ui->comboPortName->addItems(portname);
}
void Setting::AddBaurate()
{
    QList<QString> Baurate;
    Baurate << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "115200";
    baurate << QSerialPort::Baud1200 <<QSerialPort::Baud2400 << QSerialPort::Baud4800 << QSerialPort::Baud9600 << QSerialPort::Baud19200 << QSerialPort::Baud38400 <<QSerialPort::Baud57600 << QSerialPort::Baud115200;
    ui->comboBaurate->addItems(Baurate);
    ui->comboBaurate->setCurrentIndex(baurate.indexOf(QSerialPort::Baud115200));
}
void Setting::AddDataBits()
{
    QList<QString> DataBits;
    DataBits << "5" << "6" << "7" << "8";
    databits << QSerialPort::Data5 <<QSerialPort::Data6 << QSerialPort::Data7 <<QSerialPort::Data8;
    ui->comboDataBits->addItems(DataBits);
    ui->comboDataBits->setCurrentIndex(databits.indexOf(QSerialPort::Data8));
}
void Setting::AddFlowControl()
{
    QList<QString> FlowControl;
    FlowControl << "None" << "Hardware flow control" << "Software flow control";
    flowcontrol << QSerialPort::NoFlowControl << QSerialPort::HardwareControl << QSerialPort::SoftwareControl;
    ui->comboFlowControl->addItems(FlowControl);
    ui->comboFlowControl->setCurrentIndex(flowcontrol.indexOf(QSerialPort::NoFlowControl));
}
void Setting::AddParity()
{
    QList<QString> Parity;
    Parity << "None" << "Even" << "Odd" << "Space" << "Mark";
    parity << QSerialPort::NoParity << QSerialPort::EvenParity << QSerialPort::OddParity << QSerialPort::SpaceParity << QSerialPort::MarkParity;
    ui->comboParity->addItems(Parity);
    ui->comboParity->setCurrentIndex(parity.indexOf(QSerialPort::NoParity));
}
void Setting::AddStopBits()
{
    QList<QString> StopBits;
    StopBits << "1" << "1.5" << "2";
    stopbits << QSerialPort::OneStop << QSerialPort::OneAndHalfStop << QSerialPort::TwoStop,
    ui->comboStopBits->addItems(StopBits);
    ui->comboStopBits->setCurrentIndex(stopbits.indexOf(QSerialPort::OneStop));
}
QString Setting::GetPortName()
{
    return ui->comboPortName->itemText(ui->comboPortName->currentIndex());
}

QSerialPort::BaudRate Setting::GetBaurate()
{
    return baurate[ui->comboBaurate->currentIndex()];
}

QSerialPort::DataBits Setting::GetDataBits()
{
    return databits[ui->comboDataBits->currentIndex()];
}

QSerialPort::FlowControl Setting::GetFlowControl()
{
    return flowcontrol[ui->comboFlowControl->currentIndex()];
}

QSerialPort::Parity Setting::GetParity()
{
    return parity[ui->comboParity->currentIndex()];
}

QSerialPort::StopBits Setting::GetStopBits()
{
    return stopbits[ui->comboStopBits->currentIndex()];
}
