#include <bits/stdc++.h>

using namespace std;

const int r = 1e3 + 9;
int dp[r][r];
int tab[r][r];
int n;

bool czy(int M)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(tab[i][j] >= M) dp[i][j]++;
        }
    }
    if(dp[n][n] >= n) return 1;
    return 0;
}

int main()
{    
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    int p = 1, k = 1e9, sr;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> tab[i][j];
        }
    }
    while(p < k)
    {
        sr = (p + k) / 2;
        if(czy(sr))
            p = sr + 1;
        else
            k = sr;
    }
    cout << k - 1;
}
