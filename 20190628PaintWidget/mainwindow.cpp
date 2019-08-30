#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //添加画板
    drawwidget=new DrawWidget();
    this->setCentralWidget(drawwidget);

    //修改window的图标
    QPixmap pix(20,20);
    pix.fill(Qt::red);
    setWindowIcon(pix);

    createToolBar();
    setMinimumSize(800,600);

    //初始化
    showStyle();
    drawwidget->setWidth(widthSpinbox->value());
    drawwidget->setColor(Qt::black);
//    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
//    delete ui;
}

void MainWindow::createToolBar()
{
    QToolBar *toolBar=this->addToolBar("tool");

    stylelabel=new QLabel();
    stylelabel->setText("LineStyle: ");

    styleComboBox=new QComboBox();
    styleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    connect(styleComboBox,SIGNAL(activated(int)),this,SLOT(showStyle()));


    widthlabel=new QLabel();
    widthlabel->setText("线宽: ");
    widthSpinbox=new QSpinBox();
    connect(widthSpinbox,SIGNAL(valueChanged(int)),drawwidget,SLOT(setWidth(int)));

    colorBtn=new QToolButton();
    QPixmap pix(20,20);
    pix.fill(Qt::black);
    colorBtn->setIcon(pix);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

    clearBtn=new QToolButton();
    clearBtn->setText("清除");
    connect(clearBtn,SIGNAL(clicked()),drawwidget,SLOT(clear()));

    saveBtn=new QToolButton();
    saveBtn->setText("保存");
    connect(saveBtn,SIGNAL(clicked()),drawwidget,SLOT(save()));

    toolBar->addWidget(stylelabel);
    toolBar->addWidget(styleComboBox);
    toolBar->addWidget(widthlabel);
    toolBar->addWidget(widthSpinbox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
    toolBar->addWidget(saveBtn);
}

void MainWindow::showStyle()
{
    drawwidget->setStyle(
                styleComboBox->itemData(styleComboBox->currentIndex(),Qt::UserRole).toInt()
                );
}

void MainWindow::showColor()
{
    QColor color=QColorDialog::getColor(static_cast<int>(Qt::black),this);//默认黑色
    if(color.isValid()){
        drawwidget->setColor(color);
        QPixmap pix(20,20);
        pix.fill(color);
        colorBtn->setIcon(pix);
    }
}

