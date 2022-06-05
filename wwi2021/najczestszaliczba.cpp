#include <bits/stdc++.h>

using namespace std;

map <int, int> mapa;
int tab[1009];

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <=n; i++)
    {
        cin >> tab[i];
    }
    while (q--)
    {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int l, r;
        cin >> l >> r;
        mapa.clear();
        for(int i = l; i <= r; i++)
        {
            mapa[tab[i]]++;
        }
        int rek = 0;
        for(auto x:mapa)
        {
            if(mapa[rek] < x.second) rek = x.first;
            else if(mapa[rek] == x.second && rek > x.first) rek = x.first;
        }
        cout<<mapa[rek]<<" "<<rek<<"\n";
    }
}