#include "terminal.h"
#include "ui_terminal.h"

Terminal::Terminal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Terminal)
{
    ui->setupUi(this);
    Toolbar_Init();
    MainMenu_Init();
    StatusBar_Init();
    ErrorList_Init();
    ui->radioString->setChecked(true);
    Port = new QSerialPort();
    infosound = new InfoSound();
    settingForm = new Setting();
    connect(settingForm, SIGNAL(accepted()), this, SLOT(Open_Port()));
    connect(Port, SIGNAL(readyRead()), this, SLOT(SerialPort_DataReceive()));
}

Terminal::~Terminal()
{
    delete ui;
}
void Terminal::MainMenu_Init()
{
    ui->actionOpen->setChecked(false);
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(MenuOpen_Port()));
    connect(ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(MenuClose_Port()));
    connect(ui->actionSetting, SIGNAL(triggered(bool)), this, SLOT(MenuSetting()));

}
void Terminal::Toolbar_Init()
{
    ui->mainToolBar->addAction(ui->actionOpen);
    ui->mainToolBar->addAction(ui->actionClose);
    ui->mainToolBar->addAction(ui->actionSetting);
}
void Terminal::StatusBar_Init()
{
    statusPortname = new QLabel();
    statusBaurate = new QLabel();
    statusPortname->setAlignment(Qt::AlignCenter);
    statusBaurate->setAlignment(Qt::AlignCenter);
    statusPortname->setMinimumSize(statusPortname->sizeHint());
    statusBaurate->setMinimumSize(statusBaurate->sizeHint());
    statusPortname->setText("NULL");
    statusBaurate->setText("NULL");
    statusBar()->addWidget(statusPortname);
    statusBar()->addWidget(statusBaurate);

}
void Terminal::MenuOpen_Port()
{
    settingForm->show();
    settingForm->activateWindow();
    settingForm->raise();
}
void Terminal::ErrorList_Init()
{
    SerialError << "No Error" << "Device Not Found" << "Permission Deny" << "Open Error" << "Parity Error" << "Framing Error"
                << "Break Condition Error" << "Write Error" << "Read Error" << "Resource Error" << "Unsupported Operation Error" << "Unknown Error"
                << "Timeout Error" << "No port was opened";
}

void Terminal::Open_Port()
{
    Port->setPortName(settingForm->GetPortName());
    Port->setBaudRate(settingForm->GetBaurate(), QSerialPort::AllDirections);
    Port->setDataBits(settingForm->GetDataBits());
    Port->setFlowControl(settingForm->GetFlowControl());
    Port->setParity(settingForm->GetParity());
    Port->setStopBits(settingForm->GetStopBits());
    if (!Port->open(QIODevice::ReadWrite))
    {
        infosound->PlaySoundError();
        msg.setText("Error");
        msg.setInformativeText(SerialError[Port->error()]);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
        Port->clearError();
        ui->actionOpen->setChecked(false);
    }
    else
    {
        infosound->PlaySoundConnect();
        ui->actionOpen->setChecked(true);
        statusPortname->setText(Port->portName());
        statusBaurate->setText(QString::number(Port->baudRate()));
    }
}
void Terminal::MenuClose_Port()
{
    Port->close();
    if (Port->error() != QSerialPort::NoError)
    {
        infosound->PlaySoundError();
        msg.setText("Error");
        msg.setInformativeText(SerialError[Port->error()]);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
        Port->clearError();
    }
    else
    {
        ui->actionOpen->setChecked(false);
        statusPortname->setText("Port is Close");
        statusBaurate->setText("NULL");
    }
}
void Terminal::MenuSetting()
{
    if (Port->isOpen())
    {
        MenuClose_Port();
        MenuOpen_Port();
    }
    else
        MenuOpen_Port();
}

void Terminal::on_buttonSend_clicked()
{
   static QByteArray DataToSend;
    if (Port->isOpen())
    {
        if (ui->lnSend->text() != "")
        {
            DataToSend=ui->lnSend->text().toLatin1();
            SendHistory << DataToSend;
            if (ui->radioString->isChecked())
            {
                Port->write(DataToSend);
                ui->lnSend->clear();
            }
        }
    }
    else
    {
        msg.setText("Error");
        msg.setInformativeText("Please Open Serial Port First");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}
void Terminal::SerialPort_DataReceive()
{
    ReceiveHistory << Port->readAll();
    ReceiveHistory.size();
    ViewData += ReceiveHistory[ReceiveHistory.length() -1];
    ui->TxtReceive->setText(ViewData);
    ui->TxtReceive->verticalScrollBar()->setValue(ui->TxtReceive->verticalScrollBar()->maximum());
}

void Terminal::on_lnSend_textEdited(const QString &arg1)
{
    if (ui->radioHex->isChecked())
    {

    }
}
