#include <bits/stdc++.h>
#include "slo.h"

using namespace std;

const int r = 1e5 + 9;
vector<pair<int, int>> G[r];
int pre[r], siz[r], gle[r], lca[r][20], tree[4 * r], roz, n, nr;
map <pair<int, int>, int> mapa;

void dfs(int v, int o)
{
    pre[v] = nr;
    nr ++;
    lca[v][0] = o;
    siz[v] = 1;
    for(auto x : G[v])
    {
        if(o == x.first) continue;
        gle[x.first] = gle[v] + 1;
        dfs(x.first, v);
        siz[v] += siz[x.first];
    }
}

int flca(int a, int b)
{
    if(gle[a] > gle[b]) swap(a, b);
    for(int i = 19; i >= 0; i--)
        if(gle[a] <= gle[lca[b][i]]) b = lca[b][i];
    for(int i = 19; i >= 0; i--)
        if(lca[a][i] != lca[b][i])
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    if(a == b) return a;
    return lca[a][0];
}

void change(int a, int b, int c)
{
    int d = c - mapa[{a, b}];
    mapa[{a, b}] = c;
    mapa[{b, a}] = c;
    if(gle[a] < gle[b]) swap(a, b);
    int aw = a;
    a = pre[aw] + roz;
    b = pre[aw] + siz[aw] + roz - 1;
    //cout << a << " " << b << " " << d << "\n";
    if(a == b)
    {
        tree[a] += d;
        return;
    }
    tree[a] += d;
    tree[b] += d;
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0) tree[a + 1] += d;
        if(b % 2 == 1) tree[b - 1] += d;
        a /= 2;
        b /= 2;
    }
}

int kuery(int v)
{
    int wyn = 0;
    while(v > 0)
    {
        wyn += tree[v];
        v /= 2;
    }
    return wyn;
}

int distance(int a, int b)
{
    int lc = pre[flca(a, b)] + roz;
    a = pre[a] + roz, b = pre[b] + roz;
    return kuery(a) + kuery(b) - 2 * kuery(lc);
}

void init(vector<tuple<int, int, int>> edges)
{
    n = edges.size() + 1;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(auto x : edges)
    {
        G[get<0>(x)].push_back({get<1>(x), get<2>(x)});
        G[get<1>(x)].push_back({get<0>(x), get<2>(x)});
    }
    dfs(1, 1);
    for(int i = 1; i <= 19; i++)
        for(int j = 1; j <= n; j++)
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
    for(auto x : edges)
        change(get<0>(x), get<1>(x), get<2>(x));
}