#include <bits/stdc++.h>

using namespace std;

const int r = 1e4 + 9;
short dp[r][r];

int main()
{
    string s;
    int n;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;
    for(int i = 0; i < n - 1; i++)
        dp[i][i + 1] = max(1, 2 * (s[i] == s[i + 1]));
    for(int siz = 3; siz <= n; siz++)
    {
        for(int i = 0; i + siz - 1 < n; i++)
        {
            int l = i;
            int p = i + siz - 1;
            dp[l][p] = max(dp[l + 1][p], dp[l][p - 1]);
            if(s[l] == s[p])
                dp[l][p] = max(dp[l][p], (short)(dp[l + 1][p - 1] + 2));
            //cout << l << " " << p << " " << dp[l][p] << "\n";
        }
    }
    cout << n - dp[0][n - 1];
}