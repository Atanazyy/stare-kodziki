#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

bool czy[r];
int o[r];
pair<int, pair <int, int> > tab[r];

int finde(int v)
{
    if(o[v] == v) return v;
    o[v] = finde(o[v]);
    return(o[v]);
}

void unione(int a, int b)
{
    int ao = finde(a), bo = finde(b);
    czy[ao] = czy[ao] | czy[bo];
    o[bo] = ao;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i].first;
        tab[i].second.first = i;
        o[i] = i;
    }
    for(int i = n + 1; i <= n + m; i ++)
    {
        cin >> tab[i].second.first >> tab[i].second.second >> tab[i].first;
    }
    sort(tab + 1, tab + 1 + n + m);
    long long wyn = 0;
    for(int i = 1; i <= n + m; i++)
    {
        int k = tab[i].first, a = tab[i].second.first, b = tab[i].second.second;
        if(b == 0)
        {
            if(!czy[finde(a)])
            {
                wyn += k;
                czy[finde(a)] = 1;
            }
        }
        else
        {
            if((!czy[finde(a)] || !czy[finde(b)]) && finde(a) != finde(b))
            {
                wyn += k;
                unione(a, b);
            }
        }
    }
    cout << wyn;
}