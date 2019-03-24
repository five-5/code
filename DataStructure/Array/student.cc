/*
 * @Author: five-5
 * @Description: 自定义类测试MyArray
 * @Date: 2019-03-24
 * @LastEditTime: 2019-03-24
 */

#include <iostream>
#include "my_array.hpp"

class Student {

 public:
    Student(){}
    Student(std::string student_name, int student_score):name(student_name), score(student_score) {}

    friend std::ostream & operator<< (std::ostream &out, const Student &stu) {
        
        out << "Student(name: " << stu.name << ", score:" << stu.score << ")";
        return out;
    }

    friend bool operator== (const Student &stu1, const Student &stu2) {
        if ((stu1.name == stu2.name) && (stu1.score == stu2.score)) {
            return true;
        } else {
            return false;
        }  
    }

 private:
    std::string name;
    int score;
};

int main()
{
    MyArray<int> arr = MyArray<int>();
    for (int i = 0; i < 10; ++i) {
        arr.AddLast(i);
    }
    cout << arr << endl;

    arr.Add(1, 100);
    cout << arr << endl;

    arr.AddFirst(-1);
    cout << arr << endl;
    // [-1, 0, 100, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    arr.Remove(2);
    cout << arr << endl;
    // [-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    arr.RemoveElement(4);
    cout << arr << endl;

    arr.RemoveFirst();
    cout << arr << endl;

    
    MyArray<Student> arr1 = MyArray<Student>();

    arr1.AddLast( Student("Alice", 100));
    arr1.AddLast( Student("Bob", 66));
    arr1.AddLast( Student("Charle", 88));
    arr1.AddLast( Student("Charle", 88));

    std::cout << arr1 << std::endl;

    arr1.RemoveElement(Student("Charle", 88));
    std::cout << arr1 << std::endl;

    return 0;
}