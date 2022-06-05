#include <bits/stdc++.h>

using namespace std;

bool tab[1509][1509];
long long tree[1509][];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        tab[x][y] = 1;
    }
    long long wyn = 0;
    for(int i = 1; i <= n; i++)
    {
        int d = 0;
        for(int j = m; j >= 1; j--)
        {
            if(tab[i][j])
            {
                d = 0;
                for(int k = 1; k <= m; k++)
                    dp[j][k] = 0;
                continue;
            }
            d++;
            for(int k = 1; k <= d; k++)
            {
                dp[j][k]++;
                wyn += dp[j][k];
            }
            for(int k = d + 1; k <= m; k++)
                dp[j][k] = 0;
        }
    }
    cout << wyn;
}