#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

const int roz = 1048576;
int tab[r];
int tree[4 * r];

void ubdat(int v, int w)
{
    tree[v] += w;
    v /= 2;
    while(v > 0)
    {
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
        v /= 2;
    }
}

int kuery(int v)
{
    if(v >= roz)
        return v;
    if(tree[v * 2] > 0)
        return kuery(v * 2);
    return kuery(v * 2 + 1);
}

void solve1(int n, int m, int k, int l)
{
    for(int i = 1; i <= m; i++)
        cin >> tab[i];
    for(int i = 1; i <= l; i++)
        ubdat(tab[i] + roz, 1);
    for(int i = 1; i <= m - l + 1; i++)
    {
        cout << kuery(1) - roz << " ";
        ubdat(tab[i] + roz, -1);
        ubdat(tab[i + l] + roz, 1);
    }
}

int tabb[1009][1009];
int fmin(int x1, int y1, int x2, int y2)
{
    int wyn = 1000 * 1000 * 1000;
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            wyn = min(wyn, tabb[i][j]);
    return wyn;
}

void solve2(int n, int m, int k, int l)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> tabb[i][j];
    for(int i = 1; i <= n - k + 1; i++)
    {
        for(int j = 1; j <= m - l + 1; j++)
            cout << fmin(i, j, i + k - 1, j + l - 1) << " ";
        cout << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, l, k;
    cin >> n >> m >> k >> l;
    if(n == 1)
    {
        solve1(n, m, k, l);
    }
    else
    {
        solve2(n, m, k, l);
    }
}