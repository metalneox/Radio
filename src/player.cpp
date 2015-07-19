#include "player.h"
#include "QMessageBox"
#include <vlc/vlc.h>
#include <unistd.h>

//#include <iostream>
Player::Player(){

};

//desctructor
Player::~Player()
{
    //libvlc_release(*inst);
    //inst = libvlc_new(0, NULL);
}

void Player::playFile(QString radio)
{
    //QMessageBox::information(0, "error", radio);
    //std::cout << "aaaa";

    inst = libvlc_new(0, NULL);

    m = libvlc_media_new_location(inst,radio.toStdString().c_str());

    mp = libvlc_media_player_new_from_media(m);

    libvlc_media_release(m);

    // play the media_player
    libvlc_media_player_play(mp);

    //sleep(10);
    sleep(10000);

    // stop playing
    libvlc_media_player_stop(mp);

    // free the media_player
    libvlc_media_player_release(mp);

    libvlc_release(inst);

}






