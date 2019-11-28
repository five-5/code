#include <cstdio>
#include <cstring>
#define maxn 10001
int hashTable[6] = {0};

char str[maxn];
int index(char c) {
    switch(c) {
    case 'P':
        return 0;
    case 'A':
        return 1;
    case 'T':
        return 2;
    case 'e':
        return 3;
    case 's':
        return 4;
    case 't':
        return 5;
    default:
        return -1;
    }
}
int main()
{
    scanf("%s", str);
    int lenth = strlen(str);
    for (int i = 0; i < lenth; ++i) {
        int tmp = index(str[i]);
        if (tmp != -1) {
            ++hashTable[tmp];
        }
    }

    while (1) {
        if (hashTable[index('P')]) {
            printf("P");
            --hashTable[index('P')];
        }
        if (hashTable[index('A')]) {
            printf("A");
            --hashTable[index('A')];
        }
        if (hashTable[index('T')]) {
            printf("T");
            --hashTable[index('T')];
        }
        if (hashTable[index('e')]) {
            printf("e");
            --hashTable[index('e')];
        }
        if (hashTable[index('s')]) {
            printf("s");
            --hashTable[index('s')];
        }
        if (hashTable[index('t')]) {
            printf("t");
            --hashTable[index('t')];
        }
        if (hashTable[index('P')] == 0 && hashTable[index('A')] == 0 && hashTable[index('T')] == 0 && hashTable[index('e')] == 0 && hashTable[index('s')] == 0 && hashTable[index('t')] == 0)
            break;
    }
}
