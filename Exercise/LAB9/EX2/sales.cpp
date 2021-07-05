#include <iostream>
#include "sales.h"

using namespace std;
namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        int sum=0;
        s.max=0;
        s.min=100000000;
        for (int i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            sum += s.sales[i];
            if(s.sales[i]<s.min){
               s.min=s.sales[i];
            }
            if(s.sales[i]>s.max){
                s.max=s.sales[i];
            }
        }
        s.average = sum/n;
    }
    void setSales(Sales & s)
    {
        cout << "Enter sales for 4 quarters: ";
        cin >> s.sales[0] >> s.sales[1] >> s.sales[2] >> s.sales[3];
        int sum=0;
        s.max=0;
        s.min=10000000;
        for (int i = 0; i < 4; i++)
        {
            sum += s.sales[i];
            if(s.sales[i]<s.min){
               s.min=s.sales[i];
            }
            if(s.sales[i]>s.max){
                s.max=s.sales[i];
            }
        }
        s.average = sum/4;
    }
    void showSales(const Sales &s)
    {
        cout << "Sales:";
        for (double sa : s.sales)
        {
            if (sa != 0)
            {
                cout << sa << "  ";
            }
        }
        cout << "\n";
        cout << "Average:" << s.average << endl;
        cout << "Max:" << s.max << endl;
        cout << "Min:" << s.min << endl;
    }
}
