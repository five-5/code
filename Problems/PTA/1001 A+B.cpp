/*
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
*/

#include <iostream>
#include <string>

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::string result = std::to_string(a+b);

    // 1. check >= 4 digits
    int times = 0;
    int left = 0;
    int lenth = result.size();
    if (result[0] != '-' ) {
        if (lenth >= 4) {
            times = lenth / 3;
            if (lenth % 3 == 0) {
                times = times - 1;
                left = 3;
            } else {
                left = lenth % 3;
            }
        }
    } else {
        if (lenth >= 5) {
            times = (lenth - 1 ) / 3;
            if ((lenth - 1 ) % 3 == 0) {
                times = times - 1;
                left = 3 + 1;
            } else {
                left = (lenth - 1) % 3 + 1;
            }

        }
    }

    // 2. format
    if (times != 0) {
        std::string tmp = "";
        for (int i = 1; i <= times; ++i) {
            tmp.insert(0, result.substr(lenth-3*i,3));
            tmp.insert(0,1,',');
        }
        tmp.insert(0, result.substr(0,left));
        result = tmp;
    }


    std::cout << result << std::endl;

    return 0;
}

// method 2： 压栈
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

int main()
{
    long  int a;
    long  int b;
    long  int c;
    long  int d;
    stack<long int> stk;
    cin >> a >> b;
    c = a + b;
    string str;
    while(c>999||c<-999)
    {
        d = abs(c % 1000);//取最后三位
        c = c / 1000;//去掉最后三位
        stk.push(d);
    }
    cout << c;
    while (!stk.empty())
    {
        cout << "," << setfill('0') << setw(3) <<stk.top();
        stk.pop();
    }
    return 0;
}

// method 3: 直接从前往后处理
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ","; // 找到第一个打逗号的地方，后续都是+3 +3跳着打逗号的过程
    }
    return 0;
}

