#include "floyd.h"
using namespace std;
int inf = 100000;

void floyd::InitGraph()
{
    for (int i = 0; i < vertexNum; i++)
    {
        graphInfo = new int *[vertexNum];
        distance = new int *[vertexNum];
        path = new int *[vertexNum];
        for (int j = 0; j < vertexNum; j++)
        {
            graphInfo[i][j] = inf;
            distance[i][j] = inf;
            path[i][j] = -1;
        }
    }
}

void floyd::InputData()
{
    cout << "请输入线的 起点 终点 距离:" << endl;
    for (int k = lineNum - 1; k >= 0; k--)
    {
        cout << "还需输入" << k + 1 << "组信息" << endl;
        int start, end, dist; // float distance
        cin >> start >> end >> dist;
        distance[start][end] = dist;
    }
}

void floyd::Calculate()
{
    for (int k = 0; k < vertexNum; k++)
    {
        for (int i = 0; i < vertexNum; i++)
        {
            for (int j = 0; k < vertexNum; j++)
            {
                if (distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}