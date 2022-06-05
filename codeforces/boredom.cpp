#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;

pair<long long, long long> dp[r];
long long tab[r]; 

int main()
{
    int n, ma = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        tab[a] ++;
        ma = max(ma, a);
    }
    for(int i = 1; i <= ma; i++)
    {
        dp[i].first = dp[i - 1].second + tab[i] * i;
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }
    cout << max(dp[ma].first, dp[ma].second);
}