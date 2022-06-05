#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9, mod = 1e9 + 7;
vector<int> tab[r]; // zasady
int kol[r]; //kolor i
long long wyn[r];
long long war[r];
long long sum[r];
long long dp[r];
int ojc[r];
int n, k, m;

struct S1
{
    void dfs(int v, int o)
    {
        ojc[v] = o;
        for(auto x : tab[v])
        {
            if(x == o)
                continue;
            dfs(x, v);
        }
    }

    void solve()
    {
        //cout << n;
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            tab[a].push_back(b);
            if(a != b)
                tab[b].push_back(a);
        }
        tab[0].push_back(kol[1]);
        tab[kol[1]].push_back(0);
        dfs(0, 0);
        sum[0] = 1;
        war[kol[1]] = 1;
        wyn[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            wyn[i] = (war[ojc[kol[i]]] + sum[kol[i]]) % mod;
            war[kol[i]] = (wyn[i] + war[kol[i]]) % mod;
            sum[ojc[kol[i]]] = (wyn[i] + sum[ojc[kol[i]]]);
          //  cout << wyn[i] << " ";
        }
        cout << wyn[n];
    }
};

struct S2
{
    void solve()
    {
       // cout << "XD";
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
            //cout << wyn[i] << " " << dp[kol[i]] << "\n";
        }
        cout << wyn[n];
    }
};

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> kol[i];
    cin >> m;
    if(k - 1 == m)
    {
        //cout << "heura";
        S1 s;
        s.solve();
    }
    else
    {
        //cout << "brut";
        S2 s;
        s.solve();
    }
}
