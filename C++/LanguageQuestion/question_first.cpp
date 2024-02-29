/**
 * @file question_first.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 /*
 编写一个 C++ 程序，其中包括一个带有私有 name（字符串）和 age（int）的 Person 类。
 实现一个参数化构造函数来初始化这些属性。添加一个成员函数 display，用于打印人的姓名和年龄。
 在主函数中，创建两个 Person 类实例，并使用 display 函数打印它们的信息。

 */

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name ;
    int age;


public:
    // 参数化构造函数
    Person(const std::string& personName, int personAge) : name(personName),age(personAge)
    {}

    // 成员函数 display，用于打印姓名和年龄
    void display() const
    {
        cout << "名字：" << name << "年龄：" << age << endl;
    }
};

int main() 
{
    //实现你的功能
    Person person1("DANK1KG",25);
    Person person2("Karsa",30);
    cout<<"person1:";

    person1.display();

    cout<<"person2:";

    person2.display();
    return 0;
}
