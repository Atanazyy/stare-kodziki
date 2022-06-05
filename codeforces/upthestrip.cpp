#include <bits/stdc++.h>

using namespace std;

const int r = 4e6 + 9;

long long dp[r];

int main()
{
    int n;
    long long m;
    cin >> n >> m;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 2; i <= n; i++)
    {
        //cerr<<dp[i]<<"\n";
        if(i != 2) dp[i] = (1 + dp[i] + 2 * dp[i-1]) % m;
        for(int j = i * 2; j <= n; j += i)
            dp[j] = (dp[j] + dp[i] - dp[i - 1] + m) % m;
    }
    cout << dp[n];
}
