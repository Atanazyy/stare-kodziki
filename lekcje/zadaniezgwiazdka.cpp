#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
vector <int> G[r];
int siz[r];
int pre[r];
int lca[r][21];
int gle[r];
int nr;

void dfs(int v, int o)
{
    pre[v] = nr;
    nr ++;
    siz[v] = 1;
    lca[v][0] = o;
    for(auto x : G[v])
    {
        if(x != o)
        {
            gle[x] = gle[v] + 1;
            dfs(x, v);
            siz[v] += siz[x];
        }
    }
}

int flca(int a, int b)
{
    if(gle[a] > gle[b]) swap(a, b);
    for(int i = 20; i >= 0; i--)
    {
        if(gle[lca[b][i]] >= gle[a])
            b = lca[b][i];
    }
    for(int i = 20; i >= 0; i--)
        if(lca[a][i] != lca[b][i]) 
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    if(a != b) return lca[a][0];
    return a;
}

bool prz(int a, int b)
{
    return (pre[a] <= pre[b] && pre[b] < pre[a] + siz[a]);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 1);
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int lca = flca(a, b);
        if(prz(lca, c) && (prz(c, a) || prz(c, b)))
            cout << "TAK\n";
        else 
            cout << "NIE\n";
    }
}