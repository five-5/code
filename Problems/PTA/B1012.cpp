#include <iostream>
#define maxn 1001

int num[maxn];

int main()
{
    int n;
    int a[5] = {0};
    int count[5] = {0};

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> num[i];
    }

    int flag = 1;
    for (int i = 0; i < n; ++i) {
        int left = num[i] % 5;
        switch(left) {
        case 0:
            if (num[i] % 2 == 0) {
                ++count[0];
                a[0] += num[i];
            }
            break;

        case 1:
            ++count[1];
            a[1] += flag * num[i];
            flag = -flag;
            break;

        case 2:
            ++count[2];
            ++a[2];
            break;

        case 3:
            ++count[3];
            a[3] += num[i];
            break;

        case 4:
            ++count[4];
            if (num[i] > a[4])
                a[4] = num[i];
            break;

        }
    }
    for (int i = 0; i < 4; ++i) {
        if (count[i]) {
            if (i != 3)
                printf("%d ", a[i]);
            else
                printf("%.1f ", (double)a[i]/count[3]);
        } else {
            printf("%c ", 'N');
        }
    }
    if (count[4]) {
        printf("%d\n", a[4]);
    } else {
        printf("%c\n", 'N');
    }
    return 0;
}
