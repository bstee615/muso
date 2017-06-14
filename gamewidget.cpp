#include "gamewidget.h"
#include "ui_gamewidget.h"

#include <QDebug>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    labelList(QList<MovableLabel*>())
{
    ui->setupUi(this);

    this->setWindowTitle("Muso Theatre");

    // TODO: Add sounds. Y'know, the whole point of the game.
    player = new QMediaPlayer(this);
    // ...
    player->setMedia(QUrl::fromLocalFile("/Users/me/Music/coolsong.mp3"));
    player->setVolume(50);
    player->play();
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
}
