#include <iostream>

#define maxn 100001
int grades[maxn] = {0};

int main()
{
    int maxIndex = 0;
    int N;
    std::cin >> N;
    while (N--) {
        int index, grade;
        std::cin >> index >> grade;
        grades[index] += grade;
        if (grades[maxIndex] < grades[index]) {
            maxIndex = index;
        }
    }
    std::cout << maxIndex << " " << grades[maxIndex] << std::endl;
    return 0;
}

/*
6
3 65
2 80
1 100
2 70
3 40
3 0

2 150
*/
