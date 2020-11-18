#include<stdio.h>
#include<stdlib.h>
void merge(int *a, int *c, int L, int R)
{
    int mid = (L + R) >> 1;
    int i = L, j = mid + 1, k = L;
    while (i <= mid&&j <= R)    //将 a 数组分成左右两边，归并到 c 数组
    {
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i <= mid)       // 前半数组还有剩余的情况
        c[k++] = a[i++];
    while (j <= R)         // 后半数组还有剩余的情况
        c[k++] = a[j++];
    for (i = L; i <= R; i++)  // 放回去
        a[i] = c[i];
}
void mergeSort(int *a, int *c, int L, int R)
{
    if (L == R)
        return;
    int mid = (L + R) >> 1;
    mergeSort(a, c, L, mid);
    mergeSort(a, c, mid + 1, R);
    merge(a, c, L, R);
}
int main(void)
{
    const int N = 404;
    int n, a[N], c[N];
 
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
 
    mergeSort(a, c, 1, n);
 
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }puts("");
 
    system("pause");
    return 0;
}
