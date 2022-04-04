#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class quickSort
{
    quickSort() {}
    ~quickSort() {}
    vector<int> MySort(vector<int> &arr)
    {
        Sort(arr, 0, arr.size() - 1);
        return arr;
    }

    void Sort(vector<int> &arr, int begin, int end)
    {
        if (begin >= end)
            return;
        int front = begin, back = end, mid = ((begin + back) >> 1);
        while (front <= back)
        {
            while (arr[front] < arr[mid])
                front++;
            while (arr[back] > arr[mid])
                back--;
            if (front <= back)
            {
                swap(arr[front], arr[back]);
                ++front;
                --back;
            }
        }
        Sort(arr, begin, back);
        Sort(arr, front, end);
        return;
    }
};

class HeapSort
{
public:
    HeapSort() {}
    ~HeapSort() {}
    void showHeap(vector<int> &arr)
    {
        int i = 0, temp = 1;
        while (i < arr.size())
        {
            int j = temp;
            while (j-- > 0 && i < arr.size())
            {
                cout << arr[i];
                ++i;
            }
            temp *= 2;
            cout << endl;
        }
        cout << endl;
    }
    void heapify(vector<int> &arr, int n, int i)
    { //序号越小(堆越上面)，数值越大
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        //若左/右子节点大于自己，准备交换，交换到哪边无所谓
        if (left < n && arr[left] > arr[max])
            max = left;
        if (right < n && arr[right] > arr[max])
            max = right;
        if (max != i)
        {
            swap(arr[max], arr[i]);
            heapify(arr, n, max);
        }
    }
    void buildHeap(vector<int> &arr, int n)
    { //从n-1,n-2...开始往前,交换到0,1,2...上,然后判断是否符合堆规则，循环(n-1)/2次，
        int last = n - 1;
        int parent = (last - 1) >> 1;
        for (int i = parent; i >= 0; --i)
        {
            heapify(arr, n, i);
            // showHeap(arr);
        }
    }
    void heapSort(vector<int> &arr, int n)
    {
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; --i)
        { //从后往前，逐个放到堆顶
            showHeap(arr);
            swap(arr[i], arr[0]); //把第n大的拿到倒数第n位，然后
            heapify(arr, i, 0);
        }
    }
    vector<int> RetSort(vector<int> &arr)
    {
        heapSort(arr, arr.size());
        showHeap(arr);
        return arr;
    }
};

class mergeSort
{
public:
    mergeSort() {}
    ~mergeSort() {}

    void merge(vector<int> &arr, int begin, int end)
    {
        if (begin >= end)
            return;
        int mid = (begin + end) >> 1;
        merge(arr, begin, mid);
        merge(arr, mid + 1, end);
        merge_(arr, begin, mid, end);
    }
    //左右两边合并
    void merge_(vector<int> &arr, int begin, int mid, int end)
    {
        vector<int> tmp(end - begin + 1);
        int t = 0;
        int p1 = begin, p2 = mid + 1;
        while (p1 <= mid && p2 <= end)
        {
            if (arr[p1] < arr[p2])
                tmp[t++] = arr[p1++];
            else
                tmp[t++] = arr[p2++];
        }
        while (p1 <= mid)
            tmp[t++] = arr[p1++];
        while (p2 <= end)
            tmp[t++] = arr[p2++];
        for (int i = 0; i < t; i++)
        {
            arr[begin + i] = tmp[i];
        }
    }
};

int main()
{
    vector<int> v = {2, 4, 5, 7, 9, 3, 5, 1, 6};
    HeapSort runHeapSort;
    vector<int> v2 = runHeapSort.RetSort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v2[i] << " ";
    }
    return 0;
}