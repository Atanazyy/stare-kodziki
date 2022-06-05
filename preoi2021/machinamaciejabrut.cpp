#include <bits/stdc++.h>

using namespace std;

int tab[1009][1009];

int fmin(int x1, int y1, int x2, int y2)
{
    int wyn = 1000 * 1000 * 1000;
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            wyn = min(wyn, tab[i][j]);
    return wyn;
}

int main()
{
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> tab[i][j];
    for(int i = 1; i <= n - k + 1; i++)
    {
        for(int j = 1; j <= m - l + 1; j++)
            cout << fmin(i, j, i + k - 1, j + l - 1) << " ";
        cout << "\n";
    }
}