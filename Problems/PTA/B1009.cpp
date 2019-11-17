#include <iostream>
#include <string>

int main()
{
    std::string sentence;
    getline(std::cin, sentence);
    // 去除句子开头空格
    int lenth = sentence.size();
    int startIndex= 0;
    for (; startIndex < lenth && sentence[startIndex] == ' '; ++startIndex);
    sentence = sentence.substr(startIndex, lenth - startIndex);
    lenth = lenth - startIndex;
    int pre = lenth;
    int cur = pre;
    for (int i = lenth - 1; i >= 0; --i) {
        if (sentence[i] == ' ') {
            cur = i;
            std::cout << sentence.substr(cur + 1, pre - cur - 1) << " ";
            pre = cur;
        }
        if (i == 0) {
            std::cout << sentence.substr(0, pre);
        }
    }

    return 0;
}
