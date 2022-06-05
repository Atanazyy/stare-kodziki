#include <bits/stdc++.h>

using namespace std;

const int r = 1e3 + 9;
const long long inf = 1e18 + 9;
long long tab[r][r];

int main()
{
    int n;
    long long a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            tab[i][j] = inf;
    for(int i = 1; i <= n + 1; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << tab[i][j] << " ";
            tab[i + j][j] = min(tab[i][j] + b, tab[i + j][j]);
            tab[i][i] = min(tab[i][j] + a, tab[i][i]);
        }
        cout << " ";
    }
}