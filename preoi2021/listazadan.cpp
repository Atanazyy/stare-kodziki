#include <bits/stdc++.h>

using namespace std;

const int r = 1e7 + 9;
int roz;
pair<int, int> tab[r];
int tree[r];
int ost[r];

int czyt(int v)
{
    int wyn = 0;
    while(v > 0)
    {
        wyn += tree[v];
        v /= 2;
    }
    return wyn;
}

void ubdat(int a, int b)
{
    if(a == b)
    {
        tree[a]++;
        return;
    }
    tree[a]++;
    tree[b]++;
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0) tree[a + 1]++;
        if(b % 2 == 1) tree[b - 1]++;
        a /= 2;
        b /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i].first;
        tab[i].second = -i;
    }
    sort(tab, tab + n);
    for(int i = 0; i < n; i++)
    {
        ost[-tab[i].second] = czyt(roz - tab[i].second);
        ubdat(roz - tab[i].second, roz + n);
    }
    for(int i = 0; i < n; i++)
    {
        cout << ost[i] << "\n";
    }
}