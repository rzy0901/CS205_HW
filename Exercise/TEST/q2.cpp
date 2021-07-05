#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string info;
    getline(cin, info);
    int count = 0;
    int max = 0;
    int temp = 0;
    for (char &i : info)
    {
        if (isdigit(i))
        {
            count++;
            temp = (int)i - (int)'0';
            if (temp > max)
            {
                max = temp;
            }
        }
    }
    cout << temp + count << endl;
    return 0;
}