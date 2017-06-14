#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "movablelabel.h"

#include <QWidget>
#include <QMouseEvent>
#include <QList>
// TODO: Install Qt5.9 so that this works.
#include <QMediaPlayer>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

    Ui::GameWidget *getUi() {return ui;}

private slots:
    void on_buttonTrumpet_clicked();

    void on_buttonSax_clicked();

    void on_buttonDrums_clicked();

private:
    Ui::GameWidget *ui;
    QList<MovableLabel*> labelList;
    QMediaPlayer *player;
};

#endif // GAMEWIDGET_H
