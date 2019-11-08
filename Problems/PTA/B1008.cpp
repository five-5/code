#include <iostream>
#define maxn 101
int main()
{
    int n, m;
    int a[maxn];
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    m = m % n;
    if (m == 0) {
            std::cout << a[0];
        for (int i = 1; i < n; ++i) {
            std::cout << " " << a[i];
        }
    } else {
        int start = n - m;
        std::cout << a[start];
        for (int i = 1; i < n; ++i) {
            std::cout << " " << a[(start+i)%n];
        }
    }
    std::cout << std::endl;
    return 0;
}
