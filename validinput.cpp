#include "validinput.h"

ValidInput::ValidInput(QObject *parent) : QObject(parent)
{

}

bool ValidInput::IsHex(QString inputstring)
{
    static QRegularExpressionMatch matchHEX;
    static QRegularExpression hexMatcher("^[0-9A-F]{1}$", QRegularExpression::CaseInsensitiveOption);
    QString FormatString;
    matchHEX = hexMatcher.match(inputstring);
    if (matchHEX.hasMatch())
        return true;
    return false;
}
bool ValidInput::IsDec(QString inputstring)
{
    static QRegularExpressionMatch matchDEC;
    static QRegularExpression decMatcher("^[0-9]{1}$", QRegularExpression::CaseInsensitiveOption);
    QString FormatString;
    matchDEC = decMatcher.match(inputstring);
    if (matchDEC.hasMatch())
        return true;
    return false;
}
