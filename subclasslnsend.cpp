#include "subclasslnsend.h"

SubClassLnSend::SubClassLnSend(QWidget *parent) : QLineEdit(parent)
{

}
void SubClassLnSend::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
    {
         emit KeyPressed_ArrowKey(event->key());
    }
    else
        QLineEdit::keyPressEvent(event);
}
