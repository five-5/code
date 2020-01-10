#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int M = 26 * 26 * 26 * 10 + 1;
const int N = 40001;
char name[5];
std::vector<int> tables[M];

int getID(char *name)
{
    int result = 0;
    for (int i = 0; i < 3; ++i)
    {
        result = result * 26 + name[i] - 'A';
    }
    result = result * 10 + name[3] - '0';
    return result;
}

int main()
{
    int n, k, index, num;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &index, &num);
        for(int j = 0; j < num; ++j)
        {
            scanf("%s", name);
            int id = getID(name);
            tables[id].push_back(index);
        }
    }

    // ²éÑ¯
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", name);
        int id = getID(name);
        std::sort(tables[id].begin(), tables[id].end());
        int counter = tables[id].size();
        printf("%s %d", name, counter);
        for(int j = 0; j < counter; ++j)
        {
            printf(" %d", tables[id][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9


*/
