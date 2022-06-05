#include <bits/stdc++.h>

using namespace std;

const int r = 2e3 + 9;
const long long inf = 1e18 + 9;
long long tab[r][r];

int main()
{
    int n;
    long long a, b;
    cin >> n >> a >> b;
    for(int i = 1; i <= 2 * (n + 1); i++)
        for(int j = 0; j <= 2 * (n + 1); j++)
            tab[i][j] = inf;
    long long wyn = inf;
    tab[1][0] = 0;
    for(int i = 1; i <= 2 * (n + 1); i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(tab[i][j] != inf)
                cout << i << " " << j << " " << tab[i][j] << "\n";
            if(i + j < r) tab[i + j][j] = min(tab[i][j] + b, tab[i + j][j]);
            tab[i][i] = min(tab[i][j] + a, tab[i][i]);
            if(i > n) wyn = min(wyn, tab[i][j]);
        }
    }
    cout << n << " " <<wyn <<"\n";
}