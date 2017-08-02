#include "movablelabel.h"
#include "ui_gamewidget.h"
#include "gamewidget.h"

MovableLabel::MovableLabel(QWidget *parent): QLabel(parent) {
    setMouseTracking(true); // enable mouse move events
    mouseDragging = false;

    // Add sounds. Y'know, the whole point of the game.
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setVolume(50);
    player->setPlaylist(playlist);
}
void MovableLabel::mouseMoveEvent(QMouseEvent *ev) {
    int stageLeft = 0;
    int stageRight = 1024;
    int stageTop = (pos().x() * 25 / 256) + 385;
    int stageBottom = -((pos().x()-512)*(pos().x()-512)*0.0002) + 475; // Upwards parabola.
    stageBottom += pos().x() * 19 / 256; // Offset.
    if (mouseDragging) {
        this->move(mapToParent(ev->pos() - this->offset));

        // Add bounds checking for stage
        // If he's on the stage calculate normally.
        if (pos().x() < stageLeft)
            this->move(stageLeft, pos().y());
        if (pos().x() + rect().width() > stageRight)
            this->move(stageRight - rect().width(), pos().y());
        if (pos().y() + rect().height() < stageTop)
            this->move(pos().x(), stageTop - rect().height());
        if (pos().y() + rect().height() > stageBottom)
            this->move(pos().x(), stageBottom - rect().height());
    }
}
void MovableLabel::mousePressEvent(QMouseEvent *ev) {
    player->stop();
    mouseDragging = true;
    offset = ev->pos(); // location where mouse was clicked within the label

    this->raise();
}
void MovableLabel::mouseReleaseEvent(QMouseEvent *) {
    player->play();
    mouseDragging = false;
    emit clicked();
}
