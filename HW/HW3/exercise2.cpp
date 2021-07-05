#include <iostream>

using namespace std;

int main()
{
    int m;
    int n;
    int length;
    int counter = 1;
    cin >> m >> n;
    int array[m][n];

    for (int i = 0; i < (min(m, n) + 1) / 2; i++)
    {
        for (int t = n - i - 1; t > i; t--)
        {
            array[i][t] = counter++;
        }
        for (int l = i; l < m - i - 1; l++)
        {
            array[l][i] = counter++;
        }
        for (int b = i; b < n - i - 1; b++)
        {
            array[m - i - 1][b] = counter++;
        }
        for (int r = m - i - 1; r > i; r--)
        {
            array[r][n - i - 1] = counter++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << '\t';
        }
        cout << endl;
    }
}