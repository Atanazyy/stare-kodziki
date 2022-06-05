#include <bits/stdc++.h>

using namespace std;

struct pkt
{
    long long x;
    long long y;
};

vector <pkt> oto;
const int r = 1e5 + 9;
pkt fx;
pkt tab[r];

long long ilo(pkt v1, pkt v2)
{
    return v1.x * v2.y - v2.x * v1.y;
}

bool C(pkt a, pkt b)
{
    if(a.x == b.x)
    {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool comp(pkt a, pkt b)
{
    a.x -= fx.x;
    a.y -= fx.y;
    b.x -= fx.x;
    b.y -= fx.y;
    return 0 < ilo(a, b);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        tab[i] = {x, y};
    }
    sort(tab, tab + n, C);
    fx = tab[0];
    sort(tab + 1, tab + n, comp);
    for(int i = 0; i < n; i++)
    {
        while(oto.size() > 2 )
        {
            pkt v1 = oto[oto.size() - 1];
            pkt v2 = oto[oto.size() - 2];
            if(ilo({tab[i].x - v1.x, tab[i].y - v1.y}, {tab[i].x - v2.x, tab[i].y - v2.y}) < 0) 
                break;
            oto.pop_back();
        }
        oto.push_back(tab[i]);
    }
    for(auto x : oto) cout<<x.x<<" "<<x.y<<"\n";
}