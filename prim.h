#ifndef PRIM_H
#define PRIM_H

#include<iostream>
using namespace std;
class Prim
{
    private:
        string node[14];        //结点数组下标对应表示的地点
        int Matrix[14][14];     //邻接矩阵 内容代表权值
    public:
        Prim();
};


#endif // PRIM_H
