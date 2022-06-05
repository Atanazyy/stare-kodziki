#include <bits/stdc++.h>

using namespace std;

const int r = 1e6, mod = 1e9 + 7;
vector<int> tab[r]; // zasady
int kol[r]; //kolor i
long long wyn[r];
long long dp[r];

int main()
{
    int n, k, m;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> kol[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b);
        if(a != b)
            tab[b].push_back(a);
    }
    dp[kol[1]] = 1;
    wyn[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(auto x : tab[kol[i]])
        {
            wyn[i] = (wyn[i] + dp[x]) % mod;
        }
        dp[kol[i]] = (wyn[i] + dp[kol[i]]) % mod;
        //cout << wyn[i] << " ";// << dp[kol[i]] << "\n";
    }
    cout << wyn[n];
}
