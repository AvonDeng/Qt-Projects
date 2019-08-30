#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QMessageBox>
#include <QMouseEvent>
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
    setWidget();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setWidget()
{
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit->setText("0");
    for(int i=0;i<Row;i++)
        for (int j=0;j<Col;j++) {
            b[i][j]=new QPushButton(this);//表示在this上创建
            b[i][j]->resize(Width,Width);
            b[i][j]->move(Space+j*(Width+Space),60+i*(Width+Space));
            b[i][j]->setText(static_cast<QString>(btnText[i][j]));
        }
    this->show();
    connect(b[0][0],SIGNAL(clicked()),this,SLOT(on_button_7_clicked()));
    connect(b[0][1],SIGNAL(clicked()),this,SLOT(on_button_8_clicked()));
    connect(b[0][2],SIGNAL(clicked()),this,SLOT(on_button_9_clicked()));
    connect(b[0][3],SIGNAL(clicked()),this,SLOT(on_button_plus_clicked()));
    connect(b[0][4],SIGNAL(clicked()),this,SLOT(on_button_left_clicked()));
    connect(b[1][0],SIGNAL(clicked()),this,SLOT(on_button_4_clicked()));
    connect(b[1][1],SIGNAL(clicked()),this,SLOT(on_button_5_clicked()));
    connect(b[1][2],SIGNAL(clicked()),this,SLOT(on_button_6_clicked()));
    connect(b[1][3],SIGNAL(clicked()),this,SLOT(on_button_minus_clicked()));
    connect(b[1][4],SIGNAL(clicked()),this,SLOT(on_button_right_clicked()));
    connect(b[2][0],SIGNAL(clicked()),this,SLOT(on_button_1_clicked()));
    connect(b[2][1],SIGNAL(clicked()),this,SLOT(on_button_2_clicked()));
    connect(b[2][2],SIGNAL(clicked()),this,SLOT(on_button_3_clicked()));
    connect(b[2][3],SIGNAL(clicked()),this,SLOT(on_button_multiply_clicked()));
    connect(b[2][4],SIGNAL(clicked()),this,SLOT(on_button_del_clicked()));
    connect(b[3][0],SIGNAL(clicked()),this,SLOT(on_button_0_clicked()));
    connect(b[3][1],SIGNAL(clicked()),this,SLOT(on_button_dot_clicked()));
    connect(b[3][2],SIGNAL(clicked()),this,SLOT(on_button_equal_clicked()));
    connect(b[3][3],SIGNAL(clicked()),this,SLOT(on_button_devide_clicked()));
    connect(b[3][4],SIGNAL(clicked()),this,SLOT(on_button_clearall_clicked()));


}
void Dialog::init()
{
    num1=0;
    num2=0;
    result=0;
    isNum2=false;
    isFirst=true;
    S="0";
    sign=' ';
    ui->lineEdit->setText("0");
}
//void Dialog::mousePressEvent(QMouseEvent *e)
//{
//    int x=(e->pos().y()-60)/(Width+Space);
//    int y=(e->pos().x())/(Width+Space);

//    if(x>=0&&x<=Row&&y>=0&&y<=Row)
//    {
//        QMessageBox::about(this,"tips",QString::number(y));
//    }

//}
void Dialog::caculate()
{
    switch (sign) {
    case '+':
        result=num1+num2;break;
    case '-':
        result=num1-num2;break;
    case '*':
        result=num1*num2;break;
    case '/':
        result=num1/num2;break;
    default:
        break;
    }
    S=QString::number(result);
    isFirst=true;
    num1=result;
    num2=0;
}

void Dialog::on_button_7_clicked()
{
    if(isFirst){
        S='7';
        isFirst=false;
    }
    else {
        S+='7';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_8_clicked()
{
    if(isFirst){
        S='8';
        isFirst=false;
    }
    else {
        S+='8';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_9_clicked(){
    if(isFirst){
        S='9';
        isFirst=false;
    }
    else {
        S+='9';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_plus_clicked(){
    if(isNum2){
        caculate();
        sign='+';
    }
    else {
        sign='+';
        isNum2=true;
        isFirst=true;
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_left_clicked(){

}
void Dialog::on_button_4_clicked(){
    if(isFirst){
        S='4';
        isFirst=false;
    }
    else {
        S+='4';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_5_clicked(){
    if(isFirst){
        S='5';
        isFirst=false;
    }
    else {
        S+='5';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_6_clicked(){
    if(isFirst){
        S='6';
        isFirst=false;
    }
    else {
        S+='6';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_minus_clicked(){
    if(isNum2){
        caculate();
        sign='-';
    }
    else {
        sign='-';
        isNum2=true;
        isFirst=true;
    }
    ui->lineEdit->setText(S);
}

void Dialog::on_button_right_clicked(){
}

void Dialog::on_button_1_clicked(){
    if(isFirst){
        S='1';
        isFirst=false;
    }
    else {
        S+='1';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_2_clicked(){
    if(isFirst){
        S='2';
        isFirst=false;
    }
    else {
        S+='2';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_3_clicked(){
    if(isFirst){
        S='3';
        isFirst=false;
    }
    else {
        S+='3';
    }
    if(isNum2){
        num2=S.toFloat();
    }
    else {
        num1=S.toFloat();
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_multiply_clicked(){
    if(isNum2){
        caculate();
        sign='*';
    }
    else {
        sign='*';
        isNum2=true;
        isFirst=true;
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_del_clicked(){
    QString s;
    if(S!=""){
        for (int i=0;i<S.length()-1;i++) {
            s+=S[i];
        }
        S=s;
        if(isNum2)
            num2=S.toFloat();
        else {
            num1=S.toFloat();
        }
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_0_clicked(){

}
void Dialog::on_button_dot_clicked(){

}
void Dialog::on_button_equal_clicked(){
    if(isNum2){
        caculate();
        isFirst=true;
        sign='=';
        isNum2=false;
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_devide_clicked(){
    if(isNum2){
        caculate();
        sign='/';
    }
    else {
        sign='/';
        isNum2=true;
        isFirst=true;
    }
    ui->lineEdit->setText(S);
}
void Dialog::on_button_clearall_clicked(){
    init();
    ui->lineEdit->setText(S);
}
