#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const int SIZE=10;
    const int Width=40;
    const int X=20;
    const int Y=20;
    enum BlankState{BLACK,WHITE,BLANK};
    BlankState Chess[10][10];
    bool isBegin,isEnd;
    BlankState currChess;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *);
    void init();
    void mousePressEvent(QMouseEvent *e);
    bool isWin(int row,int col);
};

#endif // MAINWINDOW_H
