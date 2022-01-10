#ifndef INFO_H
#define INFO_H


#include <QDialog>

namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();

private slots:
    void on_RequestButton_clicked();

private:
    Ui::Info *ui;
    QString node[14];        //结点数组下标对应表示的地点
    QString info[14];
    int searchIndex(QString str);
};

#endif // INFO_H
