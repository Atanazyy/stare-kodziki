#include <bits/stdc++.h>

using namespace std;
                                                                                                                                                                         
const long long r = 1e6;
vector <pair <long long, long long> > tab[r];
long long pre[r], lca[r][21], gle[r];

void dfs(long long v, long long o)
{
    for(auto x : tab[v])
    {
        long long u = x.first;
        long long w = x.second;
        if(u == o) continue;
        pre[u] = pre[v] + w;
        gle[u] = gle[v] + 1;
        lca[u][0] = v;
        dfs(u, v);
    }
}

int main()
{
    long long n;
    cin >> n;
    for(long long i = 1; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        tab[a].push_back({b, c});
        tab[b].push_back({a, c});
    }
    lca[1][0] = 1;
    dfs(1, 1);
    for(long long i = 1; i <= 20; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
    long long ao, bo;
    while(cin >> ao)
    {
        if(ao == -1) return 0;
        cin >> bo;
        long long a = ao, b = bo;
        if(gle[b] < gle[a]) swap(a, b);
        for(long long i = 20; i >= 0; i--)
            if(gle[lca[b][i]] >= gle[a]) b = lca[b][i];
        //cout << a << " " << b << "\n";
        for(long long i = 20; i >= 0; i--)
        {
            if(lca[a][i] != lca[b][i])
            {
                a = lca[a][i];
                b = lca[b][i];
            }
        }
        if(a != b) a = b = lca[a][0];
        cout << pre[ao] + pre[bo] - 2 * pre[a] << "\n";
    }
}