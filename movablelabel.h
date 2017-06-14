#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H

#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QString>

class MovableLabel : public QLabel
{
    Q_OBJECT

    QPoint offset;

public:
    bool mouseDragging;

    explicit MovableLabel(QWidget *parent);
    void mouseMoveEvent(QMouseEvent *ev);

    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *);

signals:
    void clicked();

};


#endif // MOVABLELABEL_H
