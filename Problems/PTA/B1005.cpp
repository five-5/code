#include <cstdio>
#include <algorithm>
#include <map>
#define maxn 101
int number[maxn] = {0};
std::map<int, int> hashTable;
void guess(int n) {
    while (n!=1) {
        if (hashTable.count(n) == 0) hashTable[n] = 1;
        else ++hashTable[n];
        if (n % 2 == 1) {
            n = (3*n+1) / 2;
        } else {
            n /= 2;
        }
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &number[i]);
        guess(number[i]);
    }
    std::sort(number, number + k);
    bool flag = false;
    for (int i = k - 1; i >= 0; --i) {
        if (hashTable.count(number[i]) && hashTable[number[i]] == 1) {
            if (flag) printf(" ");
            flag = true;
            printf("%d",number[i]);
        }
    }
    return 0;
}
