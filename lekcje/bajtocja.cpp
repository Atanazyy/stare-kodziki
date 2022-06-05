#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int a;
    int b;
    int c;
    int nr;
};

const int r = 3e5 + 9;
edge tab[r];
int o[r];
bool wyn[r];

bool com(edge a, edge b)
{
    return a.c < b.c;
}

int Finde(int v)
{
    if(o[v] == v) return v;
    o[v] = Finde(o[v]);
    return o[v];
}

void Unione(int a, int b)
{
    int oa = Finde(a), ob = Finde(b);
    o[oa] = ob;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> tab[i].a >> tab[i].b >> tab[i].c;
        tab[i].nr = i;
    }
    sort(tab, tab + m, com);
    for(int i = 1; i <= n; i++) 
        o[i] = i;
    int ost = 0;
    for(int i = 0; i < m; i++)
    {
        wyn[tab[i].nr] = (Finde(tab[i].a) != Finde(tab[i].b));
        if(tab[i].c != tab[i + 1].c)
        {
            for(int j = ost; j <= i; j++)
                Unione(tab[j].a, tab[j].b);
            ost = i + 1;
        }
    }
    for(int i = 0; i < m; i ++)
    {
        if(wyn[i]) cout << "TAK\n";
        else cout <<"NIE\n";
    }
}