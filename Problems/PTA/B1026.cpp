#include <iostream>
#include <cmath>
#define CLK_TCK 100

int main()
{
    int c1, c2;

    std::cin >> c1 >> c2;
    int seconds = round((c2 - c1)*1.0 / CLK_TCK);
    /*int seconds = c2 - c1;
    if (seconds % 100 >= 50) {
        seconds = seconds / CLK_TCK + 1;
    } else {
        seconds = seconds / CLK_TCK;
    }*/
    int mins = seconds / 60;
    seconds = seconds % 60;
    int hours = mins / 60;
    mins = mins % 60;
    printf("%02d:%02d:%02d\n",hours, mins, seconds);

    return 0;
}
