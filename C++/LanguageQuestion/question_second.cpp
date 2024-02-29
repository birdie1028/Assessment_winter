/**
 * @file question_second.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 /*
 创建一个 C++ 程序，定义一个带有虚函数 calculateArea 的基类 Shape。
 从基类派生出两个类 Circle 和 Rectangle。在每个派生类中实现 calculateArea 函数，
 分别计算圆形和矩形的面积。在主函数中，创建两个派生类的实例，
 分别调用 calculateArea 函数，并显示结果。
 */

 #include <iostream>
 
 using namespace std;

class Shape 
{
public:
    virtual float calculateArea()=0;
    
};

class Circle : public Shape 
{
private:
    float radius;

public:
    Circle(float r) : radius(r) 
    {}
    float calculateArea() override
    {
        double PI = 3.1415926;
        float res=PI*radius*radius;
        return res;
    }


};


class Rectangle : public Shape 
{
private:
    float length;
    float width;
public:
    Rectangle(float l,float w) : length(l),width(w)
    {}

    float calculateArea() override
    {
        float area;
        area=length*width;
        return area;
    }

};

int main() 
{
    //补充你的代码
    Circle circle(1.0);

    cout<<"圆的面积："<< circle.calculateArea()<<endl;

    Rectangle rectangle(1,2);

    cout<<"矩形面积："<<rectangle.calculateArea()<<endl;

    return 0;
}
