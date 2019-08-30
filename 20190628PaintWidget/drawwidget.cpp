#include "drawwidget.h"
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));

    pixmap=new QPixmap(size());
    pixmap->fill(Qt::white);

    setMinimumSize(800,600);
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.drawPixmap(QPoint(0,0),*pixmap);
}

void DrawWidget::setStyle(int s)
{
    style=s;
}
void DrawWidget::setWidth(int w)
{
    width=w;
}
void DrawWidget::setColor(QColor c)
{
    color=c;
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
    startPos=e->pos();
}
void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter paint(this);
    QPen pen;
    pen.setWidth(width);
    pen.setColor(color);
    pen.setStyle((Qt::PenStyle)style);

    paint.begin(pixmap);
    paint.setPen(pen);
    paint.drawLine(startPos,e->pos());
    paint.end();

    startPos=e->pos();
    this->update();
}

void DrawWidget::resizeEvent(QResizeEvent *e)
{
    if(height()>=pixmap->height()){
        QPixmap *newpix=new QPixmap(size());
        newpix->fill(Qt::white);

        QPainter paint(newpix);
        paint.drawPixmap(QPoint(0,0),*pixmap);
        pixmap=newpix;
    }

    QWidget::resizeEvent(e);
}

void DrawWidget::clear()
{
    QPixmap *newpix=new QPixmap(size());
    newpix->fill(Qt::white);
    pixmap=newpix;
    this->update();
}
void DrawWidget::save()
{
//    QMessageBox::about(this,"tip","erroe");
    QFileDialog file(this);
    file.setWindowModality(Qt::WindowModal);
    file.setAcceptMode(QFileDialog::AcceptSave);
    if(file.exec()==QDialog::Accepted){
        pixmap->save(file.selectedFiles().first());
    }
}
