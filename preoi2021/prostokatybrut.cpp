#include <bits/stdc++.h>

using namespace std;

const int r = 2000;

int tab[r][r];
int dp[r][r];

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
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = tab[i][j] - dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1];
        }
    int wyn = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = i; k <= n; k++)
                for(int l = j; l <= m; l++)
                    if(dp[k][l] + dp[i - 1][j - 1] - dp[k][j - 1] - dp[i - 1][l] == 0)
                    {
                        //cout << i << " " << j << " " << k << " " << l << "\n";
                        wyn++;
                    }
    cout << wyn;
}