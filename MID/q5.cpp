#include <iostream>
#include <vector>
using namespace std;

void chan(vector<vector<char>> &arr, int &n, int &m, int x, int y, int &ans)
{
    char ch = arr[x][y];
    arr[x][y] = 'X';
    int i, j;
    if (ch == 'B')
    {
        i = x + 1;
        j = y - 1;
        while (i < n && j > -1)
        {
            if (arr[i][j] == ch)
                arr[i][j] = 'X';
            else if (arr[i][j] == 'G')
                arr[i][j] = 'Y';
            else
                break;
            ++i, --j;
        }
    }
    else
    {
        i = x + 1;
        j = y + 1;
        while (i < n && j < m)
        {
            if (arr[i][j] == ch)
                arr[i][j] = 'X';
            else if (arr[i][j] == 'G')
                arr[i][j] = 'B';
            else
                break;
            ++i, ++j;
        }
    }
    ans += 1;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] == 'X')
                continue;
            else if (arr[i][j] == 'B')
                chan(arr, N, M, i, j, ans);
            else if (arr[i][j] == 'Y')
                chan(arr, N, M, i, j, ans);
            else
            {
                arr[i][j] = 'B';
                chan(arr, N, M, i, j, ans);
                arr[i][j] = 'Y';
                chan(arr, N, M, i, j, ans);
            }
        }
    }
    cout << ans;
    return 0;
}