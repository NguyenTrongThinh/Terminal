#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDebug>


class History : public QObject
{
    Q_OBJECT
public:
    explicit History(QObject *parent = 0);
private:
    QList<QString> HistoryList;
    int Index;
public:
    void HistoryAddNew(QString hisstr);
    QString HistoryGetHistory();
    void HistoryIncreaseIndex();
    void HistoryDecreaseIndex();
    void HistoryResetIndex();

signals:

public slots:
};

#endif // HISTORY_H
