#include <iostream>
#include <sstream>
#include <string>

const std::string TODAY = "2014/09/06";
const std::string MAXDAY = "1814/09/06";

struct info{
    std::string name;
    std::string birthday;
}tmp, age_max, age_min;

bool isValid(const std::string &birth) {
    // check
    if (birth > TODAY || birth < MAXDAY) {
        return false;
    }

    return true;

}

int main()
{
    age_max.birthday = TODAY;
    age_min.birthday = MAXDAY;
    int N;
    std::cin >> N;
    int count = 0;
    while(N--) {
        std::cin >> tmp.name >> tmp.birthday;
        if (isValid(tmp.birthday)) {
            ++count;
            if (age_max.birthday >= tmp.birthday) {
                age_max.name = tmp.name;
                age_max.birthday = tmp.birthday;
            }
            if (age_min.birthday <= tmp.birthday) {
                age_min.name = tmp.name;
                age_min.birthday = tmp.birthday;
            }
        }
    }
    if (count == 0) {
        std::cout << count << std::endl;
    } else {
        std::cout << count << " " << age_max.name << " " << age_min.name << std::endl;
    }

    return 0;
}
