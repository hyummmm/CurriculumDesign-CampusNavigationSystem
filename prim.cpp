#include "prim.h"
//形成最小生成树
Prim::Prim()
{
    //对node数组赋值
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

    //对Matrix矩阵赋值
    //对自回路赋值
    for(int  i =0; i < 14; i++)
    {
        Matrix[i][i] = 0;
    }
    Matrix[13][12] = Matrix[12][13] = 30;
    Matrix[10][12] = Matrix[12][10] = 25;
    Matrix[]



}
