#include <iostream>
#include <vector>
using namespace std;

int backPack(int m, int* W, int* V,int k)
{
    vector<int> f(m + 1, 0);

    for (int i = 0; i < k; i++)
    {
        for (int j = m; j >= W[i]; j--)
        {
            f[j] = max(f[j], f[j - W[i]] + V[i]);
        }
    }
    return f[m];
}

int main()
{
    int* W = new int[6]{2,2,3,1,5,2};
    int* V = new int[6]{2,3,1,5,4,3};
    int n;
    cin >> n;
    cout<<backPack(n,W,V,6)<<endl;
    return 0;
}