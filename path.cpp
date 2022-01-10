#include "path.h"
#include "ui_path.h"
#include<QStack>
#include<QVector>

Path::Path(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Path)
{
    //设置窗体信息
    ui->setupUi(this);
    setWindowTitle("查询路径信息");

    //显示图片
    QPixmap Pix(":/pic/images/MapWithPath.png");
    ui->MapLabel->setPixmap(Pix);
    ui->MapLabel->setScaledContents(true);
    ui->MapLabel->show();

    //给node数组赋值
    node[0] = "教学楼A座";
    node[1] = "教学楼B座";
    node[2] = "教学楼C座";
    node[3] = "教学楼D座";
    node[4] = "天鹅湖";
    node[5] = "情人坡";
    node[6] = "外语楼";
    node[7] = "信息楼";
    node[8] = "图书馆";
    node[9] = "中南讲堂";
    node[10] = "体育场";
    node[11] = "综合实验楼";
    node[12] = "篮球场";
    node[13] = "毓秀楼";

   //给Martix数组赋值
    for(int i = 0; i < Verticesnum; i++)
    {
        for(int j = 0; j < 14; j++)
        {
            Matrix[i][j] = INF;
        }
    }
    Matrix[12][13] = Matrix[13][12] = 46;
    Matrix[10][12] = Matrix[12][10] = 28;
    Matrix[6][10] = Matrix[10][6] = 78;
    Matrix[6][11] = Matrix[11][6] = 18;
    Matrix[1][11] = Matrix[11][1] = 24;
    Matrix[0][1] = Matrix[1][0] = 10;
    Matrix[1][2] = Matrix[2][1] = 10;
    Matrix[2][3] = Matrix[3][2] = 10;
    Matrix[3][5] = Matrix[5][3] = 18;
    Matrix[5][7]  =Matrix[7][5] = 30;
    Matrix[2][4] = Matrix[4][2] = 22;
    Matrix[4][9] = Matrix[9][4] = 18;
    Matrix[1][8] = Matrix[8][1] = 34;
    Matrix[8][9] = Matrix[9][8] = 12;
    Matrix[4][7] = Matrix[7][4] = 36;
    Matrix[7][9] = Matrix[9][7] = 32;

    //给d数组赋初始值
    for(int i = 0; i < Verticesnum; i++)
    {
        for(int j = 0; j < Verticesnum; j++)
        {
            d[i][j] = 0;
        }
    }

    //给p数组赋初始值
    for(int i = 0; i < Verticesnum; i++)
    {
        for(int j = 0; j < Verticesnum; j++)
        {
            p[i][j] = 0;
        }
    }


}

Path::~Path()
{
    delete ui;
}

//另一个算法，利用全部路径
void Path::showestpath(int u, int v)
{
    //类似DFS
    //初始点入栈并置为访问过
   visited[u] = true;
   singlepath.push_back(u);
   if(u == v)//判断已经到达终点
   {
        //输出路径
        for(int i = 0; i < singlepath.length(); i++)
        {
            if(i == 0)
            {
                path = node[singlepath[i]];
            }
            else
            {
                path = path + "--->" + node[singlepath[i]] ;
            }

        }
        path =  "（路径长度为" + QString::number(dis) + ")  " + path ;
        if(mindis > dis)
        {
            mindis = dis;
            minpath = path;
        }
        path = "";
   }
   for(int k = 0; k < Verticesnum ; k++)//遍历所有的子结点
   {
       if(!visited[k] && Matrix[u][k] != INF)//找子结点（权值不为INF的）并且要没有被访问过
       {
           dis += Matrix[u][k];//加上路径的长度
           showestpath(k,v);
           dis -= Matrix[u][k];//减去路径的长度
       }
   }
   singlepath.pop_back();//弹出路径中最后一个结点
   visited[u] = false;
   return;
}

//和下面的print配合实现寻找最短路径  floyd算法
int Path::floyd(int d[14][14],int p[14][14])
{
    int i,j,k;
    //初始化
    for(i = 0; i < Verticesnum; i++)
    {
        for(j = 0; j < Verticesnum; j++)
        {
            d[i][j] = Matrix[i][j];
            p[i][j]  = -1;
        }
    }
    //算法开始
    for(k = 0; k < Verticesnum; k++)
    {
        for(i = 0; i < Verticesnum; i++)
        {
            for(j = 0; j < Verticesnum; j++)
            {
                //对于每一对顶点i和j，看看是否存在一个顶点k使得从i到k再到j比己知的路径更短，如果是就更新它。
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];//长度更新
                    p[i][j] = k;//从i到j时 从i出发的除j的下一个顶点置为k
                }
            }
        }
    }
    return 0;
}

void Path::printpath(int p[Verticesnum][Verticesnum],int u, int v, QString& path)
{
    int k;
    if(p[u][v] == -1){
        path = path + node[u] + "---->";
        return;
    }
    k = p[u][v];
    printpath(p,u,k,path);
    printpath(p,k,v,path);
}

//求最短路径的按钮
void Path::on_ShortestButton_clicked()
{
    //弗洛伊德算法-最短路径
    //读到出发地和目的地的结点下标
     QString departure = ui->DepartureCombo->currentText();
     QString destination = ui->DestinationCombo->currentText();
     //将文字转为结点的下标
     int departNode, destinaNode;
     for(int i = 0; i < Verticesnum; i++)
     {
         if(departure == node[i])
         {
             departNode = i;
             break;
         }
     }
     for(int i = 0; i < Verticesnum; i++)
     {
         if(destination == node[i])
         {
             destinaNode = i;
             break;
         }
     }

     path = "";
     //求最短路径算法一：floyd
     floyd(d,p);
     printpath(p,departNode,destinaNode,path);
     path += node[destinaNode];
     path =  "（路径长度为" + QString::number(d[departNode][destinaNode]) + ")  " + path ;
     ui->showShortest->setText(path);
     //求最短路径算法二：遍历所有路径标记最短的那条
//     minpath = "";
//     mindis = INF;
//     showestpath(departNode,destinaNode);
//     ui->showShortest->setText(minpath);
//     minpath = "";
//     mindis = INF;
}

//求全部路径：类似DFS
void Path::Allpath(int u, int v)
{
    //类似DFS
    //初始点入栈并置为访问过
   visited[u] = true;
   singlepath.push_back(u);
   if(u == v)//判断已经到达终点
   {
        //输出路径
        for(int i = 0; i < singlepath.length(); i++)
        {
            if(i == 0)
            {
                path = node[singlepath[i]];
            }
            else
            {
                path = path + "--->" + node[singlepath[i]] ;
            }

        }
        path =  "（路径长度为" + QString::number(dis) + ")  " + path ;
        ui->AllPath->addItem(path);
        path = "";
   }
   for(int k = 0; k < Verticesnum ; k++)//遍历所有的子结点
   {
       if(!visited[k] && Matrix[u][k] != INF)//找子结点（权值不为INF的）并且要没有被访问过
       {
           dis += Matrix[u][k];//加上路径的长度
           Allpath(k,v);
           dis -= Matrix[u][k];//减去路径的长度
       }
   }
   singlepath.pop_back();//弹出路径中最后一个结点
   visited[u] = false;
   return;
}

//求全部路径的按钮
void Path::on_AllButton_clicked()
{
    //求全部路径
    //读到出发地和目的地的结点下标
     QString departure = ui->DepartureCombo->currentText();
     QString destination = ui->DestinationCombo->currentText();
     //将文字转为结点的下标
     int departNode, destinaNode;
     for(int i = 0; i < Verticesnum; i++)
     {
         if(departure == node[i])
         {
             departNode = i;
             break;
         }
     }
     for(int i = 0; i < Verticesnum; i++)
     {
         if(destination == node[i])
         {
             destinaNode = i;
             break;
         }
     }
     for(int i = 0; i < Verticesnum; i++)
     {
         visited[i] = false;
     }
     //事前清空防止接上前面的路径
     path = "";
     dis = 0;
     Allpath(departNode,destinaNode);
     //事后清空方便其他调用
     path = "";
     dis = 0;
}

//清除按钮
void Path::on_ClearButton_clicked()
{
    ui->showShortest->setText("");
    ui->AllPath->clear();
}

