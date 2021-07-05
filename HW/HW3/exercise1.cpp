#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    int bullets = 0;

    //cout<<"what size of matrix you want,enter x "<<endl;
    cin >> x >> y >> bullets;
    //cout<<"what size of matrix you want,enter y "<<endl;
    int array[x][y];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            array[i][j] = 0;
        }
    }
    //初始化

    int a, b, c, d;

    for (int i = 0; i < bullets; i++)
    {
        cin >> a >> b >> c >> d;
        while (a >= 0 && a < x && b >= 0 && b < y)
        {
            array[a][b] = 1;
            a += c;
            b += d;
        }
    }
    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (array[i][j] == 0)
            {
                sum++;
            }
        }
    }
    cout << sum << endl;
}