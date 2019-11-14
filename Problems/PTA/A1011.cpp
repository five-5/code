#include <iostream>

struct result {
    int results[3];
    double profits;
};
int main()
{
    char tables[3] = {'W', 'T', 'L'};
    double odds[3][3];
    result ret;
    ret.profits = 1.0;
    for (int i = 0; i < 3; ++i) {
        double tmp = 0.0;
        for (int j = 0; j < 3; ++j) {
            std::cin >> odds[i][j];
            if (odds[i][j] > tmp) {
                ret.results[i] = j;
                tmp = odds[i][j];
            }
        }
        ret.profits *= odds[i][ret.results[i]];
    }

    ret.profits = (ret.profits * 0.65 - 1 ) * 2;
    printf("%c %c %c %.2f\n", tables[ret.results[0]], tables[ret.results[1]], tables[ret.results[2]], ret.profits);

    return 0;
}
/*
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1

T T W 39.31
*/
