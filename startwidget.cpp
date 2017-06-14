#include "startwidget.h"
#include "ui_startwidget.h"
#include "gamewidget.h"

#include "movablelabel.h"

StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWidget)
{
    ui->setupUi(this);
}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::on_buttonStart_clicked()
{
    GameWidget *gWidget = new GameWidget();
    gWidget->show();
}
