#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>
#include <QLabel>

class QDragEnterEvent;
class QDropEvent;

class Widget : public QFrame
{

public:
    Widget(QWidget *parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // WIDGET_H
