#include "movablelabel.h"
#include "ui_gamewidget.h"
#include "gamewidget.h"

MovableLabel::MovableLabel(QWidget *parent): QLabel(parent) {
    setMouseTracking(true); // enable mouse move events
    mouseDragging = false;

    // TODO: Add sounds. Y'know, the whole point of the game.
    player = new QMediaPlayer(this);
    player->setVolume(50);
}
void MovableLabel::mouseMoveEvent(QMouseEvent *ev) {
    int stageLeft = (pos().y() / 1.75 - 365) * -1; // Second quadrant
    int stageRight = pos().y() / 1.75 + 675; // First quadrant
    int stageTop = 225;
    int stageBottom = -((pos().x()-512)*(pos().x()-512)*0.0002) + 500; // Upwards parabola starting from 620 and going 35 points up. Centered on 512, goes 388 points right.
    if (mouseDragging) {
        this->move(mapToParent(ev->pos() - this->offset));

        // Add bounds checking for stage
        // If he's on the stage calculate normally.
        if (pos().x() < stageLeft)
            this->move(stageLeft, pos().y());
        if (pos().x() + rect().width() > stageRight)
            this->move(stageRight - rect().width(), pos().y());
        if (pos().y() < stageTop)
            this->move(pos().x(), stageTop);
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
