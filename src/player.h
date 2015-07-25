#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vlc/vlc.h>
#include <QString>

class Player{
    libvlc_instance_t *inst;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;


public:
    Player();
    ~Player();
    void playFile(QString file);
    void stopFile();
    void setAudio(int Volume);
    //void init();
};
#endif // PLAYER_H
