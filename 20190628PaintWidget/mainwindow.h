#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QToolButton>
#include <QSpinBox>
#include "drawwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    DrawWidget *drawwidget;
    QLabel *stylelabel,*widthlabel;
    QComboBox *styleComboBox;
    QToolButton *colorBtn,*clearBtn,*saveBtn;
    QSpinBox *widthSpinbox;

public slots:
    void showColor();
    void showStyle();

private:
    Ui::MainWindow *ui;
    void createToolBar();
};

#endif // MAINWINDOW_H
