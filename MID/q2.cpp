#include <iostream>
using namespace std;

int main()
{
    int n,x,y;
    cin >> n>>x>>y;
    if (n < 0 || n > 50000 || x < 1 || y > n){
        exit(0);
    }   
    int array [n];
    int max = 0;
    for (int i =0; i<n; i++)
    {
        cin >> array[i];
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    int min = max;
    for (int j = 1; j< max; j++)
    {
        int count1 = 0,count2=0;
        for (int i = 0; i < n; i++)
        {
            if (array[i] > j)
            {
                count2+=1;
            }
            else
                count1 +=1;
        }
        if (count2 <=y && count1 <=y && count2>=x && count1>=x && j<min)
        {
            min = j;
        }
    }
    if (min==max)
    {
        min = 0;
    }
    cout << min;
    return 0;
}