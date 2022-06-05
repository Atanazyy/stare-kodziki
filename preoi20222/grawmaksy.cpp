#include <bits/stdc++.h>

using namespace std;

long long dp[2][130][17000];
const int mod = 1e9 + 7;

void solve()
{
    int n, K;
    cin >> n >> K;
    for(int i = 1; i <= 2; i++)
    {
        for(int a = 0; a <= n; a++)
        {
            for(int k = 0; k <= K; k++)
            {
                dp[i % 2][a][k] = 0;
            }
        }
    }
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int a = 0; a <= n; a++)
        {
            for(int k = 0; k <= K; k++)
            {
                dp[i % 2][a][k] %= mod;
                if(a != 0) dp[(i + 1) % 2][a - 1][k + 2 * (i + 1)] += dp[i % 2][a][k] * a * a;
                dp[(i + 1) % 2][a + 1][k] += dp[i % 2][a][k];
                dp[(i + 1) % 2][a][k + i + 1] += dp[i % 2][a][k] * (2 * a + 1);
                //cout << i << " " << a << " " << k << ": " << dp[i][a][k] << "\n";
            }
        }
        if(i == n) continue;
        for(int a = 0; a <= n; a++)
            for(int k = 0; k <= K; k++)
                dp[i % 2][a][k] = 0;
    }
    long long wyn = dp[n % 2][0][K];
    for(int i = 1; i <= n; i++)
        wyn = (wyn * i) % mod;
    cout << wyn << "\n";
    //cout << dp[n][0][K] << "\n";
}

int main()
{
    int z;
    cin >> z;
    while(z--)
    {
        solve();
    }
}
