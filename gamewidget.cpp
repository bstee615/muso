#include "gamewidget.h"
#include "ui_gamewidget.h"

#include <QDebug>

// TODO: Spruce up the UI.
// TODO: Add options to:
// 		1. Clear the stage.
// 		2. Add custom sounds and images.
// TODO: Make the curtains come first.

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    labelList(QList<MovableLabel*>())
{
    ui->setupUi(this);

    this->setWindowTitle("Muso Theatre");
    trumpetPastVolume = ui->sliderTrumpetVolume->value();
    saxPastVolume = ui->sliderSaxVolume->value();
    drumsPastVolume = ui->sliderDrumsVolume->value();
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_buttonTrumpet_clicked()
{
    MovableLabel* label = new MovableLabel(this);
    label->resize(105,242);
    label->move(QPoint(200,225));
    label->setPixmap(QPixmap("://images/trumpet.png"));
    label->setScaledContents(true);
    label->raise();
    label->show();
    labelList.push_back(label);

    label->type = QString("trumpet");
    label->playlist->addMedia(QMediaContent(QUrl("://images/trumpet-jazzy.wav")));
    label->player->play();
}

void GameWidget::on_buttonSax_clicked()
{
    MovableLabel* label = new MovableLabel(this);
    label->resize(130,235);
    label->move(QPoint(450,250));
    label->setPixmap(QPixmap("://images/sax.PNG"));
    label->setScaledContents(true);
    label->raise();
    label->show();
    labelList.push_back(label);

    label->type = QString("sax");
    label->playlist->addMedia(QMediaContent(QUrl("://images/sax-light.wav")));
    label->player->play();
}

void GameWidget::on_buttonDrums_clicked()
{
    MovableLabel* label = new MovableLabel(this);
    label->resize(235,285);
    label->move(QPoint(650,250));
    label->setPixmap(QPixmap("://images/drums.PNG"));
    label->setScaledContents(true);
    label->raise();
    label->show();
    labelList.push_back(label);

    label->type = QString("drums");
    label->playlist->addMedia(QMediaContent(QUrl("://images/drums-crazy.wav")));
    label->player->play();
}

void GameWidget::on_buttonTrumpetMute_clicked()
{
    if (ui->buttonTrumpetMute->isChecked()) {
        trumpetPastVolume = labelList.at(0)->player->volume();
        for (auto item: labelList) {
            if (item->type == QString("trumpet")) {
                trumpetPastVolume = item->player->volume();
                item->player->setVolume(0);
            }
        }
    }
    else {
        for (auto item: labelList) {
            if (item->type == QString("trumpet"))
                item->player->setVolume(trumpetPastVolume);
        }
    }
}

void GameWidget::on_buttonSaxMute_clicked()
{
    if (ui->buttonSaxMute->isChecked()) {
        for (auto item: labelList) {
            if (item->type == QString("sax")) {
                saxPastVolume = item->player->volume();
                item->player->setVolume(0);
            }
        }
    }
    else {
        for (auto item: labelList) {
            if (item->type == QString("sax"))
                item->player->setVolume(saxPastVolume);
        }
    }
}

void GameWidget::on_buttonDrumsMute_clicked()
{
    if (ui->buttonDrumsMute->isChecked()) {
        drumsPastVolume = labelList.at(0)->player->volume();
        for (auto item: labelList) {
            if (item->type == QString("drums"))
                drumsPastVolume = item->player->volume();
                item->player->setVolume(0);
        }
    }
    else {
        for (auto item: labelList) {
            if (item->type == QString("drums"))
                item->player->setVolume(drumsPastVolume);
        }
    }
}

void GameWidget::on_sliderTrumpetVolume_sliderMoved(int position)
{
    for (auto item: labelList) {
        if (item->type == QString("trumpet"))
            item->player->setVolume(position);
    }
}

void GameWidget::on_sliderSaxVolume_sliderMoved(int position)
{
    for (auto item: labelList) {
        if (item->type == QString("sax"))
            item->player->setVolume(position);
    }
}

void GameWidget::on_sliderDrumsVolume_sliderMoved(int position)
{
    for (auto item: labelList) {
        if (item->type == QString("drums"))
            item->player->setVolume(position);
    }
}
