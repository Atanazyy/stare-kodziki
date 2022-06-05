#include <bits/stdc++.h>

using namespace std;

const int r = 2e3 + 9;

struct el
{
    int ma;
    int su;
};

el dp[r][r];
pair<int, int> tab[r];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i].first;
        dp[i][0].su = dp[i - 1][0].su + tab[i].first;
        dp[i][0].ma = tab[i].first;
        if(i >= 3)
        {
            dp[i][0].ma = tab[i].first + dp[i - 2][0].ma;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> tab[i].second;
        dp[0][i].su = dp[0][i - 1].su + tab[i].second;
        dp[0][i].ma = tab[i].second;
        if(i >= 3)
        {
            dp[0][i].ma = tab[i].second + dp[0][i - 2].ma;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j].su = dp[i - 1][j - 1].su + tab[i].first + tab[j].second;
            dp[i][j].ma = max(dp[i - 1][j].su - dp[i - 1][j].ma + tab[i].first, dp[i][j - 1].su - dp[i][j - 1].ma + tab[j].second);
            //cout << dp[i][j].su << " " << dp[i][j].ma << " | ";
        }
        //cout << "\n";
    }
    cout << dp[n][m].ma;
}