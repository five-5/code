/*
 * @Author: five-5
 * @Description: array to minimum integer
 * @Date: 2019-03-26
 * @LastEditTime: 2019-03-26
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using std::cin;
using std::endl;
using std::cout;

std::string To_Str(int ival) {
    std::string rresult;
    while (ival) {
        rresult += '0' + ival % 10;
        ival /= 10;
    }
    return std::string(rresult.rbegin(), rresult.rend());
}

bool compare(int a, int b) {
    std::string str_a = "", str_b = "";
    int tmpa = a, tmpb = b;
    while(tmpa) {
        str_a += '0' + tmpa % 10;
        tmpa /= 10;
    }

    while(tmpb) {
        str_b += '0' + tmpb % 10;
        tmpb /= 10;
    }

    // compare from end;
    int len_a = str_a.size();
    int len_b = str_b.size();
    int i, j;
    for(i = len_a - 1, j = len_b - 1; i >= 0 && j >= 0; --i, --j) {
        if (str_a[i] == str_b[j]) {
            continue;
        } else if (str_a[i] > str_b[j]) {
            return false;
        } else {
            return true;
        }
    }

    // 有前缀的情况
    long long tmp_a = a * pow(10,To_Str(b).size()) + b;
    long long tmp_b = b * pow(10,To_Str(a).size()) + a;
    //cout << "t:" << tmp_a << " " << tmp_b << endl;
    if (tmp_a <= tmp_b) {
        return true;
    } else {
        return false;
    }
}



int main()
{
    std::vector<int> int_vec;
    int num;
    while(cin >> num) {
        int_vec.push_back(num);
    }

    std::sort(int_vec.begin(), int_vec.end(),compare);

   // long long result = 0;
    std::string result;
    for (auto num : int_vec) {
        result += To_Str(num);
    }

    cout << result << endl;

    return 0;
}