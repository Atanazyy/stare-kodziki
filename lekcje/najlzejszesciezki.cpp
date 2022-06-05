#include <bits/stdc++.h>

using namespace std;

struct edg
{
    int a;
    int b;
    int x;
};

const long long r = 1e3 + 9, inf = 1e17;
pair <long long, int> tab[r];
vector <edg> kra;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        kra.push_back({a,b,x});
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        for(int i = 0; i <= n; i++)
            tab[i].first = inf;
        tab[a].first = 0;
        tab[a].second = -1;
        for(int i = 0; i < n; i++)
            for(auto x : kra)
                if(tab[x.a].first != inf && tab[x.a].first + x.x < tab[x.b].first)
                {
                    tab[x.b].first = tab[x.a].first + x.x;
                    tab[x.b].second = x.a;
                }
        if(tab[b].first == inf) 
        {
            cout << "NIE\n";
            continue;
        }
        cout << tab[b].first << " ";
        int x = b;
        vector <int> wyn;
        while (b != -1)
        {
            wyn.push_back(b);
            b = tab[b].second;
        }
        reverse(wyn.begin(), wyn.end());
        cout << wyn.size() << " ";
        for(auto x : wyn)
            cout << x << " ";
        cout << "\n";
    }
}