#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

struct sub
{
    int a, s, p;
};

map <int, long long> mapa;
map <int, int> wyn;
sub tab[r];

bool comp(sub a, sub b)
{
    return a.s < b.s;
}

set <int> oso;
set <pair<int, int> > pro;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    if(m == 0)
    {
        cout << 1;
        return 0;
    }
    for(int i = 0; i < m; i++)
        cin >> tab[i].a >> tab[i].s >> tab[i].p;
    sort(tab, tab + m, comp);
    long long ppk = 0;
    for(int i = 0; i < m; i++)
    {
        if(tab[i].p == 0)
            continue;
        mapa[tab[i].a] += tab[i].p;
        oso.insert(tab[i].a);
        if(tab[i].s == tab[i + 1].s)
            continue;
        long long ma = 0;
        for(auto x: oso)
            ma = max(ma, mapa[x]);
        set <int> wyw;
        for(auto x: oso)
            if(mapa[x] == ma) wyw.insert(x);
        oso.clear();
        if(ma < ppk)
            continue;
        else if(ma == ppk)
        {
            for(auto x : wyw)
                pro.insert({x, tab[i].s});
        }
        else
        {
            for(auto x: pro)
                wyn[x.first] += tab[i].s - x.second;
            pro.clear();
            for(auto x : wyw)
                pro.insert({x, tab[i].s});
            ppk = ma;
        }
    }
    for(auto x: pro)
        wyn[x.first] += t + 1 - x.second;
    pro.clear();
    int ma = 0;
    for(auto x: wyn)
    {
        //cout << x.first << " " << x.second << "\n";
        ma = max(x.second, ma);
    }
    for(auto x: wyn)
        if(ma == x.second)
        {
            cout << x.first;
            return 0;
        }
}