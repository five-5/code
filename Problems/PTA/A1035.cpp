#include <iostream>
#include <map>
#include <string>

#define maxn 1001
// �޸�ת����
std::map<char, char> trans = {{'1', '@'},
                              {'0', '%'},
                              {'l', 'L'},
                              {'O', 'o'},};

struct user {
    std::string username;
    std::string password;
    bool modified = false;  // ��ʶ�����Ƿ��޸�
} input[maxn];

// �ж��Ƿ���Ҫ�޸ģ���Ҫʱ�޸�
bool isModified(std::string &str) {
    bool flag = false;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '1' || str[i] == '0' || str[i] == 'l' || str[i] == 'O') {
            flag = true;
            str[i] = trans[str[i]];
        }
    }

    return flag;
}

int main()
{
    int N;
    int count = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> input[i].username >> input[i].password;
        if (isModified(input[i].password)) {
            ++count;
            input[i].modified = true;
        }
    }

    // ����ж�
    if (count == 0) {
        std::cout << "There " << (N == 1 ? "is " : "are ") << N << (N == 1 ? " account" : " accounts")  << " and no account is modified" ;
    } else {
        std::cout << count;
        for (int i = 0; i < N; ++i) {
            if (input[i].modified) {
                std::cout << std::endl;
                std::cout << input[i].username << " " << input[i].password;
            }
        }
    }

    return 0;
}
