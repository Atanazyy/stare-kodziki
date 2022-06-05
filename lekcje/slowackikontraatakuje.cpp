#include <bits/stdc++.h>

using namespace std;
                                                                                                                                                                         
const long long r = 1e6;
vector <pair <long long, long long> > tab[r];
long long lca[r][21], gle[r], ma[r][21];

void dfs(long long v, long long o)
{
    for(auto x : tab[v])
    {
        long long u = x.first;
        long long w = x.second;
        if(u == o) continue;
        gle[u] = gle[v] + 1;
        lca[u][0] = v;
        ma[u][0] = w;
        dfs(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    for(long long i = 1; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        tab[a].push_back({b, c});
        tab[b].push_back({a, c});
    }
    for(long long i = 0; i <= 20; i++)
        for(long long j = 1; j <= n; j++)
            ma[j][i] = -2e9;
    lca[1][0] = 1;
    dfs(1, 1);
    for(long long i = 1; i <= 20; i++)
    {
        for(long long j = 1; j <= n; j++)
        {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
            ma[j][i] = max(ma[j][i - 1], ma[lca[j][i - 1]][i - 1]);
        }
    }
    //cout << ma[5][1];
    long long ao, bo;
    while(cin >> ao)
    {
        if(ao == -1) return 0;
        cin >> bo;
        long long a = ao, b = bo;
        if(a == b)
        {
            cout << "0\n";
            continue;
        }
        if(gle[b] < gle[a]) swap(a, b);
        long long wyn = -2e9;
        //cout << a << b;
        for(long long i = 20; i >= 0; i--)
        {
            if(gle[lca[b][i]] >= gle[a])
            {
                //cout << ma[b][i] << "\n";
                //cout << "ZROB MI LOUDA";
                wyn = max(wyn, ma[b][i]);
                b = lca[b][i];
            }
        }
        //cout << a << " " << b << "\n";
        for(long long i = 20; i >= 0; i--)
        {
            if(lca[a][i] != lca[b][i])
            {
                wyn = max(wyn, ma[a][i]);
                wyn = max(wyn, ma[b][i]);
                a = lca[a][i];
                b = lca[b][i];
            }
        }
        if(a != b) 
        {
            wyn = max(wyn, ma[a][0]);
            wyn = max(wyn, ma[b][0]);
            a = b = lca[a][0];
        }
        cout << wyn << "\n";
    }
}