#ifndef VALIDINPUT_H
#define VALIDINPUT_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class ValidInput : public QObject
{
    Q_OBJECT
public:
    explicit ValidInput(QObject *parent = 0);
private:

public:
    bool IsHex(QString inputstring);
    bool IsDec(QString inputstring);
signals:

public slots:
};

#endif // VALIDINPUT_H
