#include <bits/stdc++.h>

using namespace std;

const int p = 1e9 + 7;
const int r = 1e5 + 9;
long long dp[r];
long long pre[r];
queue <pair<int, int> > tab;

int main()
{
    int t, k, mb = 0;
    cin >> t >> k;

    while(t--)
    {
        int a, b;
        cin >> a >> b;
        mb = max(mb, b);
        tab.push({a, b});
    }
    dp[0] = 1;
    pre[0] = 1;
    for(int i = 1; i <= mb; i++)
    {
        dp[i] = dp[i - 1];
        if(i >= k) 
            dp[i] = (dp[i] + dp[i - k]) % p; 
        pre[i] = (pre[i - 1] + dp[i]) % p;
        //cerr << i << " " << dp[i] << "\n";
    }
    while(!tab.empty())
    {
        auto z = tab.front();
        tab.pop();
        //cerr << z.first << " " << z.second << "\n";
        cout << (pre[z.second] - pre[z.first - 1] + p) % p << "\n";
    }
}