#pragma once

#include <iostream>
#include <string>

class floyd
{
private:
    int **graphInfo;
    int **distance;
    int **path;
    int vertexNum;
    int lineNum;

public:
    floyd(int VertexNum, int LineNum) : vertexNum(VertexNum), lineNum(lineNum)
    {
        InitGraph();
    };
    void InitGraph();
    void InputData();
    void PrintGraph();
    void PrintPath(int start, int end);

    void Calculate();
};
