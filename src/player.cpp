#include "player.h"
#include "QMessageBox"
#include <vlc/vlc.h>
#include <unistd.h>
#include <iostream>
#include <string>
//#include <iostream>
Player::Player(){
    inst = libvlc_new(0, NULL);

};
/*
Player::init(){
    libvlc_audio_set_volume(mp,100);
}
*/
//desctructor
Player::~Player()
{
    // free the media_player
    libvlc_media_player_release(mp);

    libvlc_release(inst);
}

void Player::playFile(QString radio)
{

    m = libvlc_media_new_location(inst,radio.toStdString().c_str());

    mp = libvlc_media_player_new_from_media(m);

    libvlc_media_release(m);

    // play the media_player
    libvlc_media_player_play(mp);

}
void Player::stopFile()
{
    libvlc_media_player_stop(mp);

}
void Player::setAudio(int Volume)
{
    libvlc_audio_set_volume(mp,Volume);
}




