#include <cstdio>
#include <algorithm>

const int N = 101;
int origin[N], tempOri[N], middle[N];
int n;

bool isSame(int A[], int B[])
{
    for (int i = 0; i < n; ++i)
    {
        if (A[i] != B[i]) return false;
    }

    return true;
}

bool showArray(int A[])
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d", A[i]);
        if (i < n-1) printf(" ");
    }
    printf("\n");
}

bool insertSort()
{
    bool flag = false;
    for (int i = 1; i < n; ++i)
    {
        if (i != 1 && isSame(tempOri, middle))
        {
            flag = true;
        }
        // 进行下一次排序
        int tmp = tempOri[i], j = i;
        // 从后往前找tmp放置的位置
        while (j > 0 && tempOri[j-1] > tmp)
        {
            tempOri[j] = tempOri[j-1];
            --j;
        }
        tempOri[j] = tmp;
        if (flag == true)
        {
            return true;
        }
    }

    return false;
}

void mergeSort()
{
    bool flag = false;
    for (int step = 2; step <= n; step *= 2)
    {
        if (step != 2 && isSame(tempOri, middle))
        {
            flag = true;
        }

        // 进行下一次归并排序
        for (int i = 0; i < n; i += step)
        {
            std::sort(tempOri + i, tempOri + std::min(i+step,n));
        }

        if ( flag == true)
        {
            showArray(tempOri);
            return;
        }

    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &origin[i]);
        tempOri[i] = origin[i];
    }

    for (int i = 0; i < n; ++i)
        scanf("%d", &middle[i]);

    if (insertSort())
    {
        printf("Insertion Sort\n");
        showArray(tempOri);
    }
    else
    {
        printf("Merge Sort\n");
        // 恢复
        for (int i = 0; i < n; ++i)
            tempOri[i] = origin[i];
        mergeSort();
    }
    return 0;
}
