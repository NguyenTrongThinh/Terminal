#ifndef INFOSOUND_H
#define INFOSOUND_H

#include <QObject>
#include <QSound>


class InfoSound : public QObject
{
    Q_OBJECT
public:
    explicit InfoSound(QObject *parent = 0);
public:
    void PlaySoundConnect();
    void PlaySoundError();

signals:

public slots:
};

#endif // INFOSOUND_H
