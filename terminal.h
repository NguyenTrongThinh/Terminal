#ifndef TERMINAL_H
#define TERMINAL_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QSerialPort>
#include <QMessageBox>
#include <setting.h>
#include <QList>
#include <QByteArray>
#include <QScrollBar>
#include <infosound.h>
#include <validinput.h>
#include <subclasslnsend.h>
#include <QKeyEvent>
#include <history.h>

namespace Ui {
class Terminal;
}

class Terminal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Terminal(QWidget *parent = 0);
    ~Terminal();
private:
    Setting *settingForm;
    QSerialPort *Port;
    QMessageBox msg;
    QList<QString> SerialError;
    QList<QByteArray> ReceiveHistory;
    QLabel *statusPortname;
    QLabel *statusBaurate;
    QString ViewData;
    InfoSound *infosound;
    ValidInput *checkvalid;
    SubClassLnSend *cLnSend;
    History *SendHistory;

private:
    void MainMenu_Init();
    void StatusBar_Init();
    void Toolbar_Init();
    void ErrorList_Init();

private slots:
    void MenuOpen_Port();
    void Open_Port();
    void MenuClose_Port();
    void MenuSetting();
    void SerialPort_DataReceive();
    void on_buttonSend_clicked();
    void on_lnSend_textEdited(const QString &arg1);
    void on_ArrowKeyPressed(int KeyCode);
    void MenuExit();

private:
    Ui::Terminal *ui;
};

#endif // TERMINAL_H
