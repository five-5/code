#include <cstdio>

int num[10];
int main()
{
    int min_num = 10;
    for (int i = 0; i <= 9; ++i) {
        scanf("%d", &num[i]);
        if (num[i] > 0 && i!= 0 && min_num > i) min_num = i;
    }
    // 输出第一个数字
    printf("%d",min_num);
    --num[min_num];
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j < num[i]; ++j) {
            printf("%d", i);
        }
    }
    return 0;
}
