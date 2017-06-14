#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "movablelabel.h"

#include <QWidget>
#include <QMouseEvent>
#include <QList>

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

    void on_buttonTrumpetMute_clicked();

    void on_buttonSaxMute_clicked();

    void on_buttonDrumsMute_clicked();

    void on_sliderTrumpetVolume_sliderMoved(int position);

    void on_sliderSaxVolume_sliderMoved(int position);

    void on_sliderDrumsVolume_sliderMoved(int position);

private:
    Ui::GameWidget *ui;
    QList<MovableLabel*> labelList;

    int trumpetPastVolume, saxPastVolume, drumsPastVolume;
};

#endif // GAMEWIDGET_H
