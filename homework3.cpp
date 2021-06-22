#include<iostream>
using namespace std;
int SequenceSearch(int a[], int value, int n)//顺序查找
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == value)
            return i+1;
    return -1;
}
int BinarySearch(int a[], int value, int n)//二分查找
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == value)
            return mid;
        if (a[mid] > value)
            high = mid - 1;
        if (a[mid] < value)
            low = mid + 1;
    }
    return -1;
}

int main() {
    int a[100], value, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> value;
    int s=SequenceSearch(a, value, n);
    int b=BinarySearch(a, value, n);
    cout << s<<"  "<<b;
}