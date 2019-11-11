#include <iostream>

int main()
{
    int first = 1;
    long long e, n;
    while (std::cin >> e >> n) {
        if (n && e != 0) {
            e = n * e;
            n = n - 1;
            if (!first) {
                printf(" %d %d", e, n);
            } else {
                printf("%d %d", e, n);
            }
            first = 0;
        }
    }
    if (first) {
        printf("0 0");
    }
    printf("\n");
    return 0;
}
