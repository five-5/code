#include <iostream>
#include <string>

int main()
{
    std::string lockID, unlockID;
    std::string firstTime = "24:00:00", lastTime = "00:00:00";
    std::string ID, inTime, outTime;
    int M;

    std::cin >> M;
    while (M--) {
        std::cin >> ID >> inTime >> outTime;
        if (inTime < firstTime) {
            firstTime = inTime;
            unlockID = ID;
        }
        if (outTime > lastTime) {
            lastTime = outTime;
            lockID = ID;
        }
    }

    std::cout << unlockID << " " << lockID << std::endl;

    return 0;
}
/*
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

SC3021234 CS301133
*/
