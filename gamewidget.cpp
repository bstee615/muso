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
    label->resize(93,140);
    label->move(QPoint(250,300));
    label->setPixmap(QPixmap("://images/trumpet.png"));
    label->setScaledContents(true);
    label->raise();
    label->show();
    labelList.push_back(label);

    label->type = QString("trumpet");
    label->getPlayer()->setMedia(QUrl::fromLocalFile("C:/code/Muso/images/trumpet.wav"));
    label->getPlayer()->play();
}

void GameWidget::on_buttonSax_clicked()
{
    MovableLabel* label = new MovableLabel(this);
    label->resize(65,135);
    label->move(QPoint(450,300));
    label->setPixmap(QPixmap("://images/sax.PNG"));
    label->setScaledContents(true);
    label->raise();
    label->show();
    labelList.push_back(label);

    label->type = QString("sax");
    label->getPlayer()->setMedia(QUrl::fromLocalFile("C:/code/Muso/images/sax.wav"));
    label->getPlayer()->play();
}

void GameWidget::on_buttonDrums_clicked()
{
    MovableLabel* label = new MovableLabel(this);
    label->resize(140,165);
    label->move(QPoint(650,300));
    label->setPixmap(QPixmap("://images/drums.png"));
    label->setScaledContents(true);
    label->raise();
    label->show();
    labelList.push_back(label);

    label->type = QString("drums");
    label->getPlayer()->setMedia(QUrl::fromLocalFile("C:/code/Muso/images/drums.wav"));
    label->getPlayer()->play();
}

void GameWidget::on_buttonTrumpetMute_clicked()
{
    if (ui->buttonTrumpetMute->isChecked()) {
        trumpetPastVolume = labelList.at(0)->getPlayer()->volume();
        for (auto item: labelList) {
            if (item->type == QString("trumpet")) {
                trumpetPastVolume = item->getPlayer()->volume();
                item->getPlayer()->setVolume(0);
            }
        }
    }
    else {
        for (auto item: labelList) {
            if (item->type == QString("trumpet"))
                item->getPlayer()->setVolume(trumpetPastVolume);
        }
    }
}

void GameWidget::on_buttonSaxMute_clicked()
{
    if (ui->buttonSaxMute->isChecked()) {
        for (auto item: labelList) {
            if (item->type == QString("sax")) {
                saxPastVolume = item->getPlayer()->volume();
                item->getPlayer()->setVolume(0);
            }
        }
    }
    else {
        for (auto item: labelList) {
            if (item->type == QString("sax"))
                item->getPlayer()->setVolume(saxPastVolume);
        }
    }
}

void GameWidget::on_buttonDrumsMute_clicked()
{
    if (ui->buttonDrumsMute->isChecked()) {
        drumsPastVolume = labelList.at(0)->getPlayer()->volume();
        for (auto item: labelList) {
            if (item->type == QString("drums"))
                drumsPastVolume = item->getPlayer()->volume();
                item->getPlayer()->setVolume(0);
        }
    }
    else {
        for (auto item: labelList) {
            if (item->type == QString("drums"))
                item->getPlayer()->setVolume(drumsPastVolume);
        }
    }
}

void GameWidget::on_sliderTrumpetVolume_sliderMoved(int position)
{
    for (auto item: labelList) {
        if (item->type == QString("trumpet"))
            item->getPlayer()->setVolume(position);
    }
}

void GameWidget::on_sliderSaxVolume_sliderMoved(int position)
{
    for (auto item: labelList) {
        if (item->type == QString("sax"))
            item->getPlayer()->setVolume(position);
    }
}

void GameWidget::on_sliderDrumsVolume_sliderMoved(int position)
{
    for (auto item: labelList) {
        if (item->type == QString("drums"))
            item->getPlayer()->setVolume(position);
    }
}
