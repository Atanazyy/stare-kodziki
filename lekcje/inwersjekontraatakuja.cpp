#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
int roz;
int tree[r];
pair <int, int> tab[r];

int czyt(int v)
{
    v += roz;
    int wyn = 0;
    while(v > 0)
    {
        wyn += tree[v];
        v /= 2;
    }
    return wyn;
}

void dod(int p, int k)
{
    p += roz;
    k += roz;
    if(p == k)
    {
        tree[p] ++;
        return;
    }
    tree[p] ++;
    tree[k] ++;
    while(p / 2 != k / 2)
    {
        if(p % 2 == 0) tree[p + 1] ++;
        if(k % 2 == 1) tree[k - 1] ++;
        p /= 2;
        k /= 2;
    }
}

int main()
{
    int n;
    cin >> n;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort(tab, tab + n);
    long long wyn = 0;
    for(int i = 0; i < n; i++)
    {
        if(tab[i].second != 0) dod(0, tab[i].second - 1);
        wyn += czyt(tab[i].second);
    }
    cout << wyn;
}