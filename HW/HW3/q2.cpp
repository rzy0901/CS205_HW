#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void changeDirection(int &dx, int &dy)
{
    if (dy == -1)
    {
        dx = 1;
        dy = 0;
        return;
    }
    if (dx == 1)
    {
        dx = 0;
        dy = 1;
        return;
    }
    if (dy == 1)
    {
        dx = -1;
        dy = 0;
        return;
    }
    if (dx == -1)
    {
        dx = 0;
        dy = -1;
        return;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **a;
    a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }
    int x = 0, y = m;
    int dx = 0;
    int dy = -1;
    for (int i = 1; i <= n * m; i++)
    {
        if (x + dx < 0 || x + dx > n - 1 || y + dy < 0 || y + dy > m - 1 || a[x + dx][y + dy] != 0)
        {
            changeDirection(dx, dy);
        }
        x = x + dx;
        y = y + dy;
        a[x][y] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int width = 0;
        for (int j = 0; j < m; j++)
        {
            width = ((int)log10(n * m) + 1) + 1 - ((int)log10(a[i][j]) + 1);
            cout << a[i][j];
            cout << setw(width) << "";
        }
        cout << endl;
    }
}