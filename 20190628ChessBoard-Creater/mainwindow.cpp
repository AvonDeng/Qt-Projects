#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init()
{
    isBegin=false;
    isEnd=true;
    currChess=BLANK;
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE;j++) {
            Chess[i][j]=BLANK;
        }
    }
    Chess[4][4]=Chess[5][5]=WHITE;
    Chess[4][5]=Chess[5][4]=BLACK;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.setPen(QPen(Qt::gray,2,Qt::SolidLine));

    for (int i=0;i<SIZE+1;i++) {
        for (int j=0;j<SIZE+1;j++) {
            paint.drawLine(X,Y+i*Width,X+SIZE*Width,Y+i*Width);
            paint.drawLine(X+i*Width,Y,X+i*Width,Y+SIZE*Width);
        }
    }
    paint.setBrush(QBrush(Qt::black,Qt::SolidPattern));
//    paint.drawEllipse(X+4*Width+3,Y+5*Width+3,Width-5,Width-5);//左下
//    paint.drawEllipse(X+5*Width+3,Y+4*Width+3,Width-5,Width-5);//右上
//    paint.setBrush(Qt::white);
//    paint.drawEllipse(X+4*Width+3,Y+4*Width+3,Width-6,Width-6);//左上
//    paint.drawEllipse(X+5*Width+3,Y+5*Width+3,Width-6,Width-6);//右下

    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE;j++) {
            if(Chess[i][j]==BLANK){
                continue;
            }
            else if (Chess[i][j]==BLACK) {
                paint.setBrush(Qt::black);
                paint.drawEllipse(X+j*Width+3,Y+i*Width+3,Width-5,Width-5);
            }
            else if (Chess[i][j]==WHITE) {
                paint.setBrush(Qt::white);
                paint.drawEllipse(X+j*Width+3,Y+i*Width+3,Width-6,Width-6);
            }
        }
    }
}

bool MainWindow::isWin(int row,int col)
{
    int count=1;
    //horizon
    for (int i=1;col-i>=0;i++) {
        if(Chess[row][col-i]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    for (int i=1;col+i<SIZE;i++) {
        if(Chess[row][col+i]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    if(count==5){
        return true;
    }
    else {
        count=1;
    }
    //vertical
    for (int i=1;row-i>=0;i++) {
        if(Chess[row-i][col]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    for (int i=1;row+i<SIZE;i++) {
        if(Chess[row+i][col]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    if(count==5){
        return true;
    }
    else {
        count=1;
    }
    //left up,right down
    for (int i=1;row-i>=0&&col-i>=0;i++) {
        if(Chess[row-i][col-i]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    for (int i=1;row+i<SIZE && col+i<SIZE;i++) {
        if(Chess[row+i][col+i]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    if(count==5){
        return true;
    }
    else {
        count=1;
    }
    //left down,right up
    for (int i=1;row+i<SIZE &&col-i>=0;i++) {
        if(Chess[row+i][col-i]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    for (int i=1;row-i>=0 && col+i<SIZE;i++) {
        if(Chess[row-i][col+i]==currChess){
            count++;
        }
        else {
            break;
        }
    }
    if(count==5){
        return true;
    }
    else {
        count=1;
    }
    return false;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    int row=(e->pos().y()-Y)/Width;
    int col=(e->pos().x()-X)/Width;
    if(row>=0&&row<SIZE&&col>=0&&col<SIZE){
        if(isBegin){
            if(Chess[row][col]==BLANK){
                Chess[row][col]=currChess;
                if(currChess==BLACK){
                    if(isWin(row,col)){
                        QMessageBox::about(this,"Tips:",tr("Black Win!"));
                        isBegin=false;
                    }
                    else {
                        ui->lineEdit->setText("Now: white");
                        currChess=WHITE;
                    }
                }
                else if(currChess==WHITE){
                    if(isWin(row,col)){
                        QMessageBox::about(this,"Tips:",tr("White Win!"));
                        isBegin=false;
                    }
                    else{
                        ui->lineEdit->setText("Now: black");
                        currChess=BLACK;
                    }
                }
                update();
            }
            else {
                QMessageBox::about(this,"Tips:",tr("已有棋子!"));
            }
        }
        else {
            QMessageBox::about(this,"Tips:",tr("还未Begin!"));
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(isEnd){
        isEnd=false;
        isBegin=true;
        currChess=WHITE;
        ui->lineEdit->setText("白棋先手!");
        update();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    init();
    ui->lineEdit->setText("Not Begin!");
    update();
}
