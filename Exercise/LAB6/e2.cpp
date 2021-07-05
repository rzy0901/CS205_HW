#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
struct box
{
    string maker;
    float height;
    float width;
    float length;
    float volume;
};
void Print(struct box Boxing);
void com(struct box *Boxing);

int main(void)
{
    struct box Boxing;
    Boxing.maker = "Jack Ma";
    Boxing.height = 3.4;
    Boxing.width = 4.5;
    Boxing.length = 5.6;
    Boxing.volume = 0;
    Print(Boxing);
    com(&Boxing);
    cout << "after setting the value:" << endl;
    Print(Boxing);
    return 0;
}

void Print(struct box Boxing)
{
    cout << "the maker is: " << Boxing.maker << endl;
    cout << "the height is: " << Boxing.height << endl;
    cout << "the width is: " << Boxing.width << endl;
    cout << "the length is: " << Boxing.length << endl;
    cout << "the volume is: " << Boxing.volume << endl;
}

void com(struct box *Boxing)
{
    Boxing->volume = Boxing->height * Boxing->width * Boxing->length;
}

/*
值传递: 
声明: void fun(int a)
调用: int a; fun(a);
引用传递:
声明: void fun(int &p)
调用: int a = 1;  fun(a);
指针传递:
声明: void fun(int*p)
调用: int a = 1l fun(&a);
*/