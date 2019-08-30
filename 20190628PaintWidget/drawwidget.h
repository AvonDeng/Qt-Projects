#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);

signals:

public slots:
    void setStyle(int s);
    void setWidth(int w);
    void setColor(QColor c);
    void clear();
    void save();

private:
    QPixmap *pixmap;
    int style;
    int width;
    QColor color;

    QPoint startPos;
    QPoint endPos;
};

#endif // DRAWWIDGET_H
