#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
pair <int, int> tab[r];
bool wyn[r];
int n;

bool czy(int x)
{
    long long s = tab[x].first;
    for(int i = 0; i < n; i++)
    {
        if(x == i) continue;
        if(s <= tab[i].first) return 0;
        s += tab[i].first;
    }
    return 1;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    int p = 0, k = n;
    sort(tab, tab + n);
    while(p < k)
    {
        int sr = (p + k) / 2;
        //cout << czy(sr);
        if(czy(sr))
            k = sr;
        else
            p = sr + 1;
    }
    //cout << k;
    for(int i = k; i < n; i++)
    {
        wyn[tab[i].second] = 1;
    }
    for(int i = 0; i < n; i++)
        if(wyn[i]) cout << 'T';
        else cout << 'N';
}