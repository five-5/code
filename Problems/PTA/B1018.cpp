#include <iostream>
#include <map>

int compare(char a, char b) {
    if (a == 'C') {
        switch(b) {
            case 'C':
                return 0;
            case 'B':
                return -1;
            case 'J':
                return 1;
        }
    } else if (a == 'B') {
        switch(b) {
            case 'B':
                return 0;
            case 'C':
                return 1;
            case 'J':
                return -1;
        }
    } else {
        switch(b) {
            case 'J':
                return 0;
            case 'B':
                return 1;
            case 'C':
                return -1;
        }
    }
}

int maxt(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b > c) {
            return b;
        } else {
            return c;
        }
    }
}

int main()
{
    int N;
    std::cin >> N;
    int awin = 0, aequ = 0, afail = 0;
    std::map<char,int> a = {{'C',0},{'J',0},{'B',0}};
    std::map<char,int> b = {{'C',0},{'J',0},{'B',0}};
    while (N--) {
        char j, y;
        std::cin >> j >> y;
        switch(compare(j,y)) {
            case 0:
                ++aequ;
                break;
            case 1:
                ++awin;
                ++a[j];
                break;
            case -1:
                ++afail;
                ++b[y];
                break;
        }
    }
    std::cout << awin << " " << aequ << " " << afail << std::endl;
    std::cout << afail << " " << aequ << " " << awin << std::endl;
    int maxj = maxt(a['C'],a['B'],a['J']);
    int maxy = maxt(b['C'],b['B'],b['J']);
    if (a['B'] == maxj) {
        std::cout << "B ";
    } else if (a['C'] == maxj) {
        std::cout << "C ";
    } else {
        std::cout << "J ";
    }

    if (b['B'] == maxy) {
        std::cout << 'B' << std::endl;
    } else if (b['C'] == maxy) {
        std::cout << 'C' << std::endl;
    } else {
        std::cout << 'J' << std::endl;
    }
}
