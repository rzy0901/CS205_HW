#include<iostream>
#include<algorithm>
using namespace std;

void maopao(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void show(int a[], int  n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool comp(int a, int b){
    return a>b;
}
int main()
{
    int a[] = {1, 2, 7, 9, 4, 5, 10};
    // maopao(a,7);
    sort(a,a+7,comp);
    show(a,7);
    return 0;
}