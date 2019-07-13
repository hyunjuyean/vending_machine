#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resetMoney()
{
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
}

void Widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::checkMoney()
{
    if (money >= 100){
            ui->pbCoffee->setEnabled(true);}
    else{
            ui->pbCoffee->setEnabled(false);}
    if (money >= 150)
    {
        ui->pbTea->setEnabled(true);
    }
    else{
        ui->pbTea->setEnabled(false);
    }
    if (money >= 200)
    {
        ui->pbCoke->setEnabled(true);
    }
    else{
        ui->pbCoke->setEnabled(false);
    }
}

void Widget::reset_message()
{
    int rest=0;
    QString won = "$ ";
    int m[4] = {500, 100, 50, 10};
    for (int i = 0; i < 4; i++)
    {
        rest = 0;
        while (money >= m[i]) {
            rest = money / m[i];
            money = money - (rest*m[i]);
        }
        won.append(QString::number(m[i]));
        won.append(" : ");
        won.append(QString::number(rest));
        won.append("\n");
    }
    QMessageBox msg;
    ui->lcdNumber->display("0");
    msg.information(nullptr, "change", won);
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

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreset_clicked()
{
    reset_message();
}
