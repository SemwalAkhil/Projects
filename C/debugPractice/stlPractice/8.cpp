// 8. Program to Convert Enum to String
#include <iostream>
#include <string>
using namespace std;
enum colors
{
    red,
    blue,
    black
};
string enumToStr(colors color)
{
    switch (color)
    {
    case red:
        return string("red");
        break;
    case blue:
        return string("blue");
        break;
    case black:
        return string("black");
        break;
    }
}
int main()
{
    printf("%s", enumToStr(red).c_str());
}
