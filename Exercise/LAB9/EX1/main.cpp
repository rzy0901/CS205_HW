#include<iostream>
#include<cstring>
#include "golf.h"

int main() {
    golf g,g2;
    setgolf(g,"Ann Birdfee",24);
    showgolf(g);
    int a=0;
    while (a==0)
    {
        a = setgolf(g2);
        std::cin.ignore();
    }
    showgolf(g2);
    return 0;
}