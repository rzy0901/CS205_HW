#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int lineset[k][4];
    int **array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[m];
    }
    int x, y, dx, dy;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> dx >> dy;
        if (x >= n || x < 0 || y >= m || y < 0)
        {
            cout << "Error, start point not on the screen." << endl;
            exit(0);
        }
        if (!(dx == 0 || dx == 1 || dx == -1) || !(dy == 0 || dy == 1 || dy == -1) || (dx == 0 && dy == 0))
        {
            cout << "Error, wrong direction of the bullet." << endl;
            exit(0);
        }
        do
        {
            array[x][y] = 1;
            x = x + dx;
            y = y + dy;
        } while (x >= 0 && x < n && y >= 0 && y < m);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] == 0)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}