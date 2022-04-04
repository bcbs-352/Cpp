#include <iostream>
#include <string>
#include <vector>

using namespace std;
//#define inf 1000000//1e6
int inf = 1000000;

int **graphInfo; //存储图的基本数据，graphInfo[i][j]表示点i->点j之间的距离//也许要用float
bool *visited;
int *Distance;
int *Parent;

void initGraph(int VertexNum)
{
    visited = new bool[VertexNum];
    Distance = new int[VertexNum];
    Parent = new int[VertexNum];
    graphInfo = new int *[VertexNum];
    for (int i = VertexNum - 1; i >= 0; i--)
    {
        visited[i] = false;
        Distance[i] = inf;
        Parent[i] = -1;
        graphInfo[i] = new int[VertexNum];
        for (int j = VertexNum - 1; j >= 0; j--)
            graphInfo[i][j] = inf;
    }
}

void printGraph(int VertexNum)
{
    for (int i = 0; i < VertexNum; i++)
    {
        for (int j = 0; j < VertexNum; j++)
        {
            string str = "inf";
            if (graphInfo[i][j] < 1e5)
                str = to_string(graphInfo[i][j]);
            cout << str << "\t";
        }
        cout << endl;
    }
}

void recentTable(int VertexNum)
{
    cout << "\nNode\t";
    for (int i = 0; i < VertexNum; i++)
        cout << i << "\t";
    cout << "\nVist\t";
    for (int i = 0; i < VertexNum; i++)
    {
        string str = visited[i] == true ? "T" : "F";
        cout << str << "\t";
    }
    cout << "\nDist\t";
    for (int i = 0; i < VertexNum; i++)
    {
        string str = "inf";
        if (Distance[i] < 1e5)
            str = to_string(Distance[i]);
        cout << str << "\t";
    }
    cout << "\nPare\t";
    for (int i = 0; i < VertexNum; i++)
    {
        cout << Parent[i] << "\t";
    }
}

/*
1、更新距离信息
    每加入一个新的结点，更新未选结点列表中与该结点邻近结点的距离信息；
2、扫描距离信息
    找到所有未选结点中Distance最小的值
3、找到的结点变为已选结点
*/
void dijkstra(int start, int end, int VertexNum)
{
    Distance[start] = 0;
    visited[start] = true;
    Parent[start] = start; //初始结点的父结点

    vector<int> searchVertex;
    searchVertex.push_back(start);
    int times = 0;

    while (!visited[end])
    {
        vector<int>::iterator it;
        // int edgeVertex = searchVertex.back();  //边缘顶点(全部边缘结点都要往前探)
        int confirmVisited = 0; //一边更新，一边不断记录距离最小的结点位置(将要变为Visited)
        int minDistance = inf;  //记录的最小距离

        for (it = searchVertex.begin(); it != searchVertex.end();)
        { //要遍历searchVertex，即相邻结点不全已被visited的结点
            int edgeVertex = *it;
            bool borderVertex = false; //是否有未visited的相邻结点
            for (int i = 0; i < VertexNum; i++)
            {
                // minDistance = inf;
                if (visited[i] == true)
                    continue;
                borderVertex = true;

                if (graphInfo[edgeVertex][i] < inf) //边缘顶点和该顶点距离不为inf
                {
                    if (graphInfo[edgeVertex][i] + Distance[edgeVertex] < Distance[i])
                    { //若边缘结点到该结点距离小于先前记录的Distance信息，则更新Distance、父结点为边缘结点
                        Distance[i] = graphInfo[edgeVertex][i] + Distance[edgeVertex];
                        Parent[i] = edgeVertex;
                    }
                    if (Distance[i] < minDistance)
                    { //比较多个被查结点的Distance，找到minDistance最小的结点，记录为confirmVisited
                        minDistance = Distance[i];
                        confirmVisited = i;
                        // visited[i] = true;
                    }
                }
            }
            if (!borderVertex)
            {
                searchVertex.erase(it);
            }
            else
            {
                it++;
            }
        }
        cout << "\n第" << times++ << "轮，边缘顶点更新为：" << confirmVisited;
        visited[confirmVisited] = true;
        recentTable(VertexNum);
        searchVertex.push_back(confirmVisited);
    }
    cout << "done!\n"
         << end;
    for (int i = end; Parent[i] != start;)
    {
        cout << "->" << Parent[i];
        i = Parent[i];
    }
    cout << "->" << start << "\n最短距离为：" << Distance[end] << endl;
}

int main()
{
    int VertexNum, EdgeNum;
    cout << "input num of Vertex & EdgeLine:";
    cin >> VertexNum >> EdgeNum;

    initGraph(VertexNum);

    cout << "\n输入线的 起点 终点 距离:\n";
    for (int k = EdgeNum - 1; k >= 0; k--)
    {
        cout << "还需输入" << k + 1 << "组信息" << endl;
        int start, end, distance; // float distance
        cin >> start >> end >> distance;
        graphInfo[start][end] = distance;
        //若是无向图
        graphInfo[end][start] = distance;
    }
    // printGraph(VertexNum);
    int start, end;
    cout << "输入 起始点 终点[0,VertexNum-1]：";
    cin >> start >> end;
    dijkstra(start, end, VertexNum);
}