#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int r = 500 * 1000 + 9;
bool tab[r];
vector <int> G[r];
long long dp[r][2][2];

void dfs(int v, int o)
{
    int syn = 0;
    for(auto x : G[v])
    {
        if(x == o)
            continue;
        syn ++;
        dfs(x, v);
    }
    dp[v][1][1] = 0;
    for(auto x : G[v])
    {
        if(x == o)
            continue;
        if(tab[x])
            dp[v][1][1] += min(dp[x][1][0], dp[x][1][1]);
        else
        {
            dp[v][1][1] += min(dp[x][1][1] + 2, min(dp[x][0][0], dp[x][0][1]));
        }
    }

    vector <int> pot;
    dp[v][1][0] = 0;
    for(auto x : G[v])
    {
        if(x == o)
            continue;
        if(tab[x])
        {
            dp[v][1][0] += min(dp[x][1][0], dp[x][1][1]);
            continue;
        }
        int nie = dp[x][1][0] + 1;
        int wyj = min(min(dp[x][0][0], dp[x][0][1]), dp[x][1][1] + 2);
        dp[v][1][0] += wyj;
        if(nie - wyj < 0)
            pot.push_back(nie - wyj);
    }
    sort(pot.begin(), pot.end());
   // reverse(pot.begin(), pot.end());
    if(pot.size() != 0)
        dp[v][1][0] += pot[0];
    if(tab[v])
    {
        dp[v][0][0] = dp[v][0][1] = inf;
        return;
    }

    dp[v][0][1] = inf;
    for(auto bie : G[v])
    {
        if(bie == o)
            continue;
        long long wyn = 1;
        if(tab[bie]) wyn += dp[bie][1][1];
        else wyn += dp[bie][0][1];
        if(wyn >= inf)
            continue;
        for(auto x : G[v])
        {
            if(x == o || x == bie)
                continue;
            if(tab[x])
                wyn += min(dp[x][1][0], dp[x][1][1]);
            else
            {
                wyn += min(dp[x][1][1] + 2, min(dp[x][0][0], dp[x][0][1]));
            }
        }
        dp[v][0][1] = min(dp[v][0][1], wyn);
    }

    dp[v][0][0] = inf;
    for(auto bie : G[v])
    {
        if(bie == o)
            continue;
        long long wyn = 1;
        if(tab[bie]) wyn += dp[bie][1][1];
        else wyn += dp[bie][0][1];
        if(wyn >= inf)
            continue;
        vector <int> pod;
        for(auto x : G[v])
        {
            if(x == o || x == bie)
                continue;
            if(tab[x])
            {
                wyn += min(dp[x][1][0], dp[x][1][1]);
                continue;
            }
            int nie = dp[x][1][0] + 1;
            int wyj = min(min(dp[x][0][0], dp[x][0][1]), dp[x][1][1] + 2);
            wyn += wyj;
            if(nie - wyj < 0)
                pod.push_back(nie - wyj);
        }
        sort(pod.begin(), pod.end());
        reverse(pod.begin(), pod.end());
        if(pod.size() != 0)
            wyn += pod[0];
        dp[v][0][0] = min(dp[v][0][0], wyn);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    int start = 1;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        tab[x] = 1;
        start = x;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    if(tab[1])
        cout << min(dp[1][1][0], dp[1][1][1]);
    else
        cout << min(dp[1][0][1], dp[1][0][0]);
    /*cout << "\n";
    for(int i = 1; i <= n; i++)
    {
        cout << i << " " << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << "\n";
    }*/
}