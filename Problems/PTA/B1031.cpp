#include <cstdio>

char ID[18];
int table[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isValid(char s[]) {
    long long num = 0;
    for (int i = 0; i < 17; ++i) {
        if (!(s[i] >= '0' && s[i] <= '9'))        // ÅÐ¶ÏºÏ·¨ÐÔ
            return false;
        num += (s[i] - '0' ) * table[i];
    }
    num = num % 11;
    if (check[num] == s[17]) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int N;
    bool flag = true;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", &ID);
        if (!isValid(ID)) {
            flag = false;
            printf("%s\n", ID);
        }
    }
    if (flag) {
        printf("All passed\n");
    }
    return 0;
}
