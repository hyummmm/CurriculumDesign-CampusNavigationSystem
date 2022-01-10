#include "info.h"
#include "ui_info.h"
#include <QPixmap>
#include <iostream>
#include <QMessageBox>
#include "string.h"

Info::Info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    setWindowTitle("查询景点信息");

    //node数组赋值
    node[0] = "教学楼A座";  info[0] = "学生上课的地方";
    node[1] = "教学楼B座";  info[1] = "学生上课的地方";
    node[2] = "教学楼C座";  info[2] = "学生上课的地方";
    node[3] = "教学楼D座";  info[3] = "学生上课的地方";
    node[4] = "天鹅湖";    info[4] = "这里饲养着一些黑天鹅";
    node[5] = "情人坡";    info[5] = "一块草坪，日光充足的时候经常有同学过来晒太阳";
    node[6] = "外语楼";    info[6] = "学生上英语课的地方";
    node[7] = "信息楼";    info[7] = "计算机院和自动化院的新院楼";
    node[8] = "图书馆";    info[8] = "学生自习的地方，每到期末一座难求";
    node[9] = "中南讲堂";   info[9] = "一个讲堂";
    node[10] = "体育场";   info[10] = "学生运动的地方，这个学期有很多同学来此健康打卡";
    node[11] = "综合实验楼"; info[11] = "学生进行电工实验等实验的地方";
    node[12] = "篮球场";   info[12] = "学生打篮球的地方";
    node[13] = "毓秀楼";   info[13] = "有很多老师办公室和学生组织的活动场地";


    QPixmap Pix(":/pic/images/MapWithNode.png");
    ui->label_2->setPixmap(Pix);
    ui->label_2->setScaledContents(true);
    ui->label_2->show();


}

Info::~Info()
{
    delete ui;
}

int Info::searchIndex(QString str)
{
    int index = -1;
    for(int i = 0; i < 14; i++)
    {
        if(node[i] == str)
        {
            index = i;
            break;
        }
    }
    return index;
}
void Info::on_RequestButton_clicked()
{
    QString str = ui->InformationRequest->currentText();
    int index = searchIndex(str);
    ui->Info_2->setText(node[index] + " : \n" + info[index]);
}

