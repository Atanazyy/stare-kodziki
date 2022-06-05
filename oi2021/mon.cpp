#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
pair <int, int> tab[r];
priority_queue <pair<int, int>> kol;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int t, d;
        cin >> t >> d;
        tab[i] = {d, t};
    }
    sort(tab + 1, tab + n + 1);
    int wyn = 0;
    int o = tab[n].first;
    for(int i = n; i >= 1; i--)
    {
        int d = tab[i].first;
        int t = tab[i].second;
        int dif = o - d;
        while(dif > 0 && !kol.empty())
        {
            if(-kol.top().first > dif) 
            {
                pair<int, int> x = {-kol.top().first - dif, kol.top().second};
                kol.pop();
                kol.push({-x.first, x.second});
                dif = 0;
            }
            else
            {
                wyn ++;
                dif -= -kol.top().first;
                kol.pop();
            }
        }
        kol.push({-t, i});
        o = d;
    }
    int dif = o;
    while(dif > 0 && !kol.empty())
    {
        if(-kol.top().first > dif) 
        {
            pair<int, int> x = {-kol.top().first - dif, kol.top().second};
            kol.pop();
            kol.push({-x.first, x.second});
            dif = 0;
        }
        else
        {
            wyn ++;
            dif -= -kol.top().first;
            kol.pop();
        }
    }
    cout << wyn;
}