#ifndef SUBCLASSLNSEND_H
#define SUBCLASSLNSEND_H

#include <QObject>
#include <QLineEdit>
#include <QDebug>
#include <QKeyEvent>

class SubClassLnSend : public QLineEdit
{
    Q_OBJECT
public:
    explicit SubClassLnSend(QWidget *parent = 0);
protected:
    virtual void keyPressEvent(QKeyEvent *event);
signals:
    void KeyPressed_ArrowKey(int KeyCode);
public slots:
};

#endif // SUBCLASSLNSEND_H
