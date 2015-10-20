#include "history.h"

History::History(QObject *parent) : QObject(parent)
{
    Index = 0;
    HistoryList.clear();
}
void History::HistoryAddNew(QString hisstr)
{
    HistoryList << hisstr;
}
QString History::HistoryGetHistory()
{
    if (Index == HistoryList.length())
        return "";
    return HistoryList.at(Index);
}
void History::HistoryIncreaseIndex()
{
     if (Index < (HistoryList.length()))
         Index++;
}
void History::HistoryDecreaseIndex()
{
    if (Index > 0)
        Index--;
}
void History::HistoryResetIndex()
{
    Index = HistoryList.length();
}
