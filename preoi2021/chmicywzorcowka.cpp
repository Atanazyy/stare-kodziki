#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

vector <pair<int, int> > tree[r];
long long upd[r];
vector <int> tab[r];
long long wyn[r];

void dfs(int v, int o, int h, long long sum)
{
    for(auto x : tree[v])
    {
        sum += x.second;
        upd[min(h + x.first + 1, r - 1)] -= x.second;
    }
    sum += upd[h];
    wyn[v] = sum;
    for(auto x : tab[v])
    {
        if(x == o) continue;
        dfs(x, v, h + 1, sum);
    }
    for(auto x : tree[v])
        upd[min(h + x.first + 1, r - 1)] += x.second;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int v, x, y;
        cin >> v >> x >> y;
        tree[v].push_back({x, y});
    }
    dfs(1, 1, 0, 0);
    for(int i = 1; i <= n; i++)
        cout << wyn[i] << " ";
}