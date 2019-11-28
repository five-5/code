#include <cstdio>
#include <cstring>
#define maxn 1002
int hashTable[256];
char str[maxn];
int main()
{
    memset(hashTable, 0, sizeof(hashTable));
    scanf("%s", str);
    int olen = strlen(str);
    for (int i = 0; i < olen; ++i) {
        ++hashTable[str[i]];
    }
    int count = 0;
    scanf("%s", str);
    bool flag = true;
    int nlen = strlen(str);
    for (int i = 0; i < nlen; ++i) {
        if (hashTable[str[i]] == 0) {
            flag = false;
            ++count;
        } else {
            --hashTable[str[i]];
        }
    }
    if (flag) {
        printf("Yes %d", olen-nlen);
    } else {
        printf("No %d", count);
    }
    return 0;
}
