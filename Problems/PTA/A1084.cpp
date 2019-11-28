#include <cctype>
#include <cstdio>
#include <map>
#define maxn 85
int main()
{
    char origin[maxn], out[maxn];
    scanf("%s", origin);
    scanf("%s", out);
    std::map<char, int> worn;
    int i, j;
    for (i = 0, j = 0; origin[i] != '\0' && out[j] != '\0'; ++i) {
        if (origin[i] != out[j]) {
            char tmp = origin[i];
            if (isalpha(tmp)) {
                tmp = toupper (tmp);
            }
            if (worn.count(tmp)== 0) {
                printf("%c", tmp);
                worn[tmp] = 1;
            }
        } else {
            ++j;
        }
    }

    // 判断原串最后一位
    for (; origin[i] != '\0'; ++i) {
        char tmp = origin[i];
        if (isalpha(tmp)) {
            tmp = toupper (tmp);
        }
        if (worn.count(tmp)== 0) {
            printf("%c", tmp);
            worn[tmp] = 1;
        }
    }
    return 0;
}
