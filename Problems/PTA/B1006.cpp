#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int b = n / 100;
    int s = (n %100) / 10;
    int g = n %10;

    for(int i = 0; i < b; ++i) {
        printf("%c", 'B');
    }
    for(int i = 0; i < s; ++i) {
        printf("%c", 'S');
    }
    for (int i = 1; i <= g; ++i) {
        printf("%c", '0' + i);
    }

    return 0;
}
