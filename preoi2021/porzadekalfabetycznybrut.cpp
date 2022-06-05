#include <bits/stdc++.h>

using namespace std;

const int r = 509;
string tab[r];

bool spr(int s1, int s2 ,int p, int q)
{
    for(int i = p; i <= q; i++)
    {
        if(tab[s1][i] > tab[s2][i])
            return 0;
        if(tab[s1][i] < tab[s2][i])
            return 1;
    }
    return 0;
}

pair <bool, pair<int, int> > czy (int n, int l, int d)
{
    for(int i = 0; i < l - d + 1; i++)
    {
        bool f = 1;
        for(int j = 0; j < n - 1; j++)
        {
            if(!spr(j, j + 1, i, i + d - 1))
            {
                f = 0;
                break;
            }
        }
        if(f)
        {
            return {1, {i + 1, i + d}};
        }
    }
    return {0, {0, 0}};
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    //int s1, s2, p, q;
    //cin >> s1 >> s2 >> p >> q;
    //cout << spr(s1, s2, p, q);
    //int x;
    //cin >> x;
    //cout << czy(n, l, x).first << " " << czy(n, l, x).second.first << " " << czy(n, l, x).second.second << "\n";
    int wyn = 0;
    int s1, s2;
    for(int i = 1; i <= l; i++)
    {
        auto w = czy(n, l, i);
        if(w.first)
        {
            cout << w.second.first << " " << w.second.second << "\n";
            return 0;
        }
    }
}