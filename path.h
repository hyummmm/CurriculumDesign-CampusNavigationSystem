#ifndef PATH_H
#define PATH_H
#define INF 10000
#define Verticesnum 14
#include <QDialog>
#include<QStack>
#include<QVector>


namespace Ui {
class Path;
}

class Path : public QDialog
{
    Q_OBJECT

public:
    explicit Path(QWidget *parent = nullptr);
    //求最短路径算法一：floyd
    int floyd(int d[Verticesnum][Verticesnum],int p[Verticesnum][Verticesnum]);
    void printpath(int p[Verticesnum][Verticesnum],int u, int v, QString& path);
    //求全部路径
    void Allpath(int u, int v);
    //补充求最短路径算法二：基本上同全部路径，记录最短的那个
    void showestpath(int u, int v);
    ~Path();

private slots:
    void on_ShortestButton_clicked();

    void on_AllButton_clicked();

    void on_ClearButton_clicked();

private:
    Ui::Path *ui;
    QString node[Verticesnum];//结点下标对应的地点名称
    int Matrix[Verticesnum][Verticesnum];//两个点之间的路径权值
    QString path;//普普通通用来存储一条路径 哪里用到搬到哪里~
    //求最短路径需要用到的参数
    int d[Verticesnum][Verticesnum];//存储出发地u到目的地v的路径长度
    int p[Verticesnum][Verticesnum];//表示从i到j，除i以外第一个走的点
    //求最短路径的另一个方法需要用到的参数
    int mindis;
    QString minpath;
    //求全部路径需要用到的参数
    int dis;
    QVector<int> singlepath;
    bool visited[Verticesnum];


};

#endif // PATH_H
