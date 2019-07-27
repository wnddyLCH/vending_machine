#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbTea->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n)
{
    money+=n;
    ui->lcdNumber->display(money);

    if(money>=100)
    {
        ui->pbCoffee->setEnabled(true);
    }
    else if(money<100)
    {
        ui->pbCoffee->setEnabled(false);
    }
    if(money>=200)
    {
        ui->pbMilk->setEnabled(true);
    }
    else if(money<200)
    {
        ui->pbMilk->setEnabled(false);
    }
    if(money>=300)
    {
        ui->pbTea->setEnabled(true);
    }
    else if(money<300)
    {
        ui->pbTea->setEnabled(false);
    }


}

void Widget::Change(void)
{
    QMessageBox msg;
    QString ten;
    QString fifty;
    QString one_hundred;
    QString five_hundred;
    int result=0;

    five_hundred=five_hundred.setNum(money/500);
    money-=(money/500)*500;
    one_hundred=one_hundred.setNum(money/100);
    money-=(money/100)*100;
    fifty=fifty.setNum(money/50);
    money-=(money/50)*50;
    ten=ten.setNum(money/10);
    money-=(money/10)*10;

    msg.information(nullptr, "title", "500 : " + five_hundred + "\n" + "100 : " + one_hundred + "\n" +
                    "50 : " +fifty + "\n" + "10 : " + ten);

    money=0;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-300);
}

void Widget::on_pbChange_clicked()
{
    Change();
    ui->lcdNumber->display(money);
}
