#include "infosound.h"

InfoSound::InfoSound(QObject *parent) : QObject(parent)
{
}
void InfoSound::PlaySoundConnect()
{
    QSound::play(":/Sound/Windows Classic and XP Sounds/classic chimes.wav");
}
void InfoSound::PlaySoundError()
{
    QSound::play(":/Sound/Windows Classic and XP Sounds/Windows XP Critical Stop.wav");
}
