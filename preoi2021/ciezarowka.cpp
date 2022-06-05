#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
struct edg
{
    int x;
    int y;
    int a;
    int b;
};
struct zap
{
    int k;
    int num;
    int a;
    int b;
};
long long wyn[r];
zap lis[r];
edg kra[r];
vector <pair<int, int> > G[r];
int pre[r];
int gle[r];
int siz[r];
long long tree[4 * r];
int prn, roz;
int lca[r][21];

bool com1(edg a, edg b)
{
    return a.x < b.x;
}

bool com2(zap a, zap b)
{
    return a.k < b.k;
}

void dfs(int v, int o)
{
    pre[v] = prn;
    prn ++;
    siz[v] = 1;
    for(auto x : G[v])
    {
        if(x.first != o)
        {
            gle[x.first] = gle[v] + 1;
            dfs(x.first, v);
            siz[v] += siz[x.first];
            lca[x.first][0] = v;
        }
    }
}

void dod(int x)
{
    int a = pre[kra[x].b] + roz, b = pre[kra[x].b] + siz[kra[x].b] + roz - 1;
    long long d = kra[x].y;
    //cout << a - roz<< " " << b -roz<< " " << d << "\n";
    if(a == b)
    {
        tree[a] += d;
        return;
    }
    tree[a] += d;
    tree[b] += d;
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0)
            tree[a + 1] += d;
        if(b % 2 == 1)
            tree[b - 1] += d;
        a /= 2;
        b /= 2;
    }
}

long long czyt(int x)
{
    int v = x + roz;
    long long wyn = 0;
    while(v > 0)
    {
        wyn += tree[v];
        v /= 2;
    }
    return wyn;
}

int flca(int a, int b)
{
    if(gle[b] < gle[a]) 
        swap(a, b);
    for(int i = 20; i >= 0; i--)
        if(gle[lca[b][i]] >= gle[a]) b = lca[b][i];
    for(int i = 20; i >= 0; i--)
    {
        if(lca[a][i] != lca[b][i])
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    if(a == b) 
        return a;
    return lca[a][0];

}

int main()
{
    int n, q;
    cin >> n >> q;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        kra[i] = {x, y, a, b};
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    sort(kra, kra + n - 1, com1);
    for(int i = 0; i < q; i++)
    {
        cin >> lis[i].a >> lis[i].b >> lis[i].k;
        lis[i].num = i;
    }
    sort(lis, lis + q, com2);
    dfs(1, 1);
    for(int x = 0; x < n - 1; x++)
        if(gle[kra[x].a] > gle[kra[x].b]) 
            swap(kra[x].a, kra[x].b);
    for(int i = 1; i <= n; i++)
    {
        //cout << i << " " << pre[i] << "\n";
    }
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
                lca[j][i] = lca[lca[j][i - 1]][i - 1];
    int o = 0;
    for(int i = 0; i < q; i++)
    {
        while(lis[i].k >= kra[o].x && o < n - 1)
        {
            dod(o);
            o++;
        }
        //cout <<czyt(pre[lis[i].a]) << " " << czyt(pre[lis[i].b]) << "\n";
        wyn[lis[i].num] = czyt(pre[lis[i].a]) + czyt(pre[lis[i].b]) - 2 * czyt(pre[flca(lis[i].a, lis[i].b)]);
    }
    for(int i = 0; i < q; i++) 
        cout <<wyn[i] << "\n";
}