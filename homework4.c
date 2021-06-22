#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right)
{
    int i, k;
    int* tmp = (int*)malloc((right - left + 1) * sizeof(int));
    int left1 = left;
    int left2 = mid;
    int right1 = mid + 1;
    int right2 = right;
    for (k = 0; left1 <= left2 && right1 <= right2; k++)
    {
        if (a[left1] <= a[right1])
        {
            tmp[k] = a[left1++];
        }
        else
        {
            tmp[k] = a[right1++];
        }
    }
    if (left1 <= left2)
    {
        for (i = left1; i <= left2; i++)
        {
            tmp[k++] = a[i];
        }
    }

    if (right1 <= right2)
    {
        for (i = right1; i <= right2; i++)
        {
            tmp[k++] = a[i];
        }
    }
    for (i = 0; i < right - left + 1; i++)
    {
        a[left + i] = tmp[i];
    }
    free(tmp);
    return;
}

void merge_sort(int a[], int left, int right)
{
    int mid = 0;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
    return;
}

int main()
{
    int n;
    printf("请输入数组大小：\n");
    scanf("%d", &n);
    int a[100];
    printf("请输入数据：\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    printf("二分归并排序结果：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}