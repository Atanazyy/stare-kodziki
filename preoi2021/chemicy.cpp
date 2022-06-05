#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

vector <pair<int, int> > tree[r];
vector <int> tab[r];
long long wyn[r];

void dfs(int v, int o)
{
    for(auto x : tree[v])
        wyn[v] += x.second;
    for(auto x : tab[v])
    {
        if(x == o) continue;
        for(auto y : tree[v])
            if(y.first != 0) tree[x].push_back({y.first - 1, y.second});
        dfs(x, v);
    }
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
    dfs(1, 1);
    for(int i = 1; i <= n; i++)
        cout << wyn[i] << " ";
}