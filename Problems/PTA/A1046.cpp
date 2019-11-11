#include <iostream>
#include <algorithm>

#define maxn 100005
int dis[maxn], a[maxn];

int main()
{
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        sum += a[i];
        dis[i] = sum;
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int left, right;
        std::cin >> left >> right;
        if (left > right) std::swap(left, right);
        std::cout << std::min(sum-dis[right-1]+dis[left-1],dis[right-1]-dis[left-1]) << std::endl;
    }
    return 0;
}

/*
TLE
#include <iostream>

#define maxn 100005
int dis[maxn];

int shortdistance(int start, int end, int n) {
    if (start > end) {
        int tmp = start;
        start = end;
        end = tmp;
    }
    int first = 0;
    int second = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= start - 1 && i <= end - 2) {
            first += dis[i];
        } else {
            second += dis[i];
        }
    }
    return first < second ? first : second;
}

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> dis[i];
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int start, end;
        std::cin >> start >> end;
        std::cout << shortdistance(start, end, N) << std::endl;
    }
    return 0;
}
*/
