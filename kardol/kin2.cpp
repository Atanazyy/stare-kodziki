#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
const int inf = 1e9;

int tab[r];
int fil[r];
long long tree[4 * r];
long long gw[4 * r];
int byl[r];
int nas[r];

void zep(int v)
{
    tree[v] += gw[v];
    gw[2 * v] += gw[v];
    gw[2 * v + 1] += gw[v];
    gw[v] = 0;
}

long long szum(int a, int b, int v, int p, int k)
{
    zep(v);
    if(a > k || b < p)
        return 0;
    if(p >= a && k <= b)
        return tree[v];
    int sr = (p + k) / 2;
    return max(szum(a, b, v * 2, p, sr), szum(a, b, v * 2 + 1, sr + 1, k));
}

void ubdat(int a, int b, int v, int p, int k, int x)
{
    zep(v);
    if(a > k || b < p)
    {
        return;
    }
    if(p >= a && k <= b)
    {
        gw[v] = x;
        zep(v);
        return;
    }
    long long sr = (p + k) / 2;
    ubdat(a, b, v * 2, p, sr, x);
    ubdat(a, b, v * 2 + 1, sr + 1, k, x);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    int roz = ceil(log2(n));
    roz = 1 << roz; 
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    for(int i = 1; i <= m; i++)
        cin >> fil[i];
    for(int i = 1; i <= n; i++)
    {
        if(byl[tab[i]] == 0) 
            tree[i + roz - 1] = tree[i + roz - 2] + fil[tab[i]];
        else if(byl[tab[i]] == 1)
            tree[i + roz - 1] = tree[i + roz - 2] - fil[tab[i]];
        else
            tree[i + roz - 1] = tree[i + roz - 2];
        byl[tab[i]] ++;
        //cout << akt[i] << " ";
    }
    for(int i = 1; i <= m; i++)
        nas[i] = byl[i] = inf;
    for(int i = n; i >= 1; i--)
    {
        nas[i] = byl[tab[i]];
        byl[tab[i]] = i;   
    }
    for(int i = roz - 1; i >= 1; i--)
    {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    /*for(int i = 1; i < 2 * roz; i++)
        cout << tree[i] << " ";*/
    long long wyn = szum(1, n, 1, 1, roz);
    for(int i = 1; i <= n; i++)
    {
        wyn = max(szum(i, n, 1, 1, roz), wyn);
        int p = nas[i];
        if(p == inf)
        {
            ubdat(i + 1, n, 1, 1, roz, -fil[tab[i]]);
            continue;
        }
        int d = nas[p];
        if(d == inf)
        {
            ubdat(i + 1, p - 1, 1, 1, roz, -fil[tab[i]]);
            ubdat(p, n, 1, 1, roz, fil[tab[i]]);
            continue;
        }
        ubdat(i + 1, p - 1, 1, 1, roz, -fil[tab[i]]);
        ubdat(p, d - 1, 1, 1, roz, fil[tab[i]]);
    }
    cout << wyn;
}