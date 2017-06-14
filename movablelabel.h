#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H

#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QString>
#include <QMediaPlayer>

class MovableLabel : public QLabel
{
    Q_OBJECT

    QPoint offset;

    QMediaPlayer *player;
public:
    QString type;

    bool mouseDragging;

    explicit MovableLabel(QWidget *parent);
    void mouseMoveEvent(QMouseEvent *ev);

    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *);

    QMediaPlayer *getPlayer() {return player;}

signals:
    void clicked();

};


#endif // MOVABLELABEL_H
