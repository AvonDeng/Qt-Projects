#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();    
//    void mousePressEvent(QMouseEvent *e);
    void setWidget();
    void init();
    void caculate();

private slots:
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_button_plus_clicked();
    void on_button_left_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_minus_clicked();
    void on_button_right_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_multiply_clicked();
    void on_button_del_clicked();
    void on_button_0_clicked();
    void on_button_dot_clicked();
    void on_button_equal_clicked();
    void on_button_devide_clicked();
    void on_button_clearall_clicked();


private:
    Ui::Dialog *ui;
    //显示界面
    const int Col=5,Row=4;
    const int Width=40;
    const int Space=10;
    const char btnText[4][5]={
        {'7','8','9','+','('},
        {'4','5','6','-',')'},
        {'1','2','3','*','<'},
        {'0','.','=','/','C',}
    };
    QPushButton *b[4][5];

    //计算变量
    float num1,num2,result;
    QString S;//存lineEdit里面的字符串
    char sign;//保存运算符
    bool isNum2;//默认flase，点过加减乘除true
    bool isFirst;//是否是首位
};

#endif // DIALOG_H
