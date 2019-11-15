#include <iostream>

struct holy{
    long long Galleon;
    short Sickle;
    short Knut;
} input[2];

// 判断钱是否为0
bool isZero(holy &num) {
    if (num.Galleon == 0 && num.Sickle == 0 && num.Knut == 0) {
        return true;
    } else {
        return false;
    }
}

// lhs - rhs
holy sub(holy &lhs, holy &rhs) {
    if (isZero(rhs)) {
        return lhs;
    }
    if (isZero(lhs)) {
        lhs.Galleon = - rhs.Galleon;
        lhs.Sickle = - rhs.Sickle;
        lhs.Knut = - rhs.Knut;
        return lhs;
    }

    holy result;

    // Knut
    if (lhs.Knut >= rhs.Knut) {
        result.Knut = lhs.Knut - rhs.Knut;
    } else {
        result.Knut = lhs.Knut - rhs.Knut + 29;
        lhs.Sickle -= 1;
    }

    if (lhs.Sickle >= rhs.Sickle) {
        result.Sickle = lhs.Sickle - rhs.Sickle;
    } else {
        result.Sickle = lhs.Sickle - rhs.Sickle + 17;
        lhs.Galleon -= 1;
    }

    result.Galleon = lhs.Galleon - rhs.Galleon;

     // 负数处理
    if (result.Galleon < 0) {
        if (result.Knut != 0) {
            result.Knut = 29 - result.Knut;
            result.Sickle += 1;
        }

        if (result.Sickle != 0) {
            result.Sickle = 17 - result.Sickle;
            result.Galleon += 1;
        }
    }

    return result;
}

int main()
{
    char c;
    for (int i = 0; i < 2; ++i) {
        std::cin >> input[i].Galleon >> c >> input[i].Sickle >> c >> input[i].Knut;
    }

    holy result = sub(input[1], input[0]);
    std::cout << result.Galleon << c << result.Sickle << c << result.Knut << std::endl;

    return 0;
}
