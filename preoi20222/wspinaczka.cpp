#include <bits/stdc++.h>

using namespace std;

struct odc
{
    long double x1, y1, x2, y2;
};

const int r = 1e6;
odc tab[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i].x1 >> tab[i].y1 >> tab[i].x2 >> tab[i].y2;
    int akt = 0;
    int wyn = 0;
    while(1)
    {
        wyn ++;
        vector <pair<long double, int> > moz;
        long double naj = 0;
        int kto = -1;
        for(int i = 0; i <n; i++)
        {
            if(i == akt)
                continue;
            long double y = tab[i].y1 + ((tab[i].y1 - tab[i].y2) / (tab[i].x1 - tab[i].x2)) * (tab[akt].x2 - tab[i].x1);
            if(y < tab[akt].y2 && y > naj && tab[akt].x2 >= tab[i].x1 && tab[akt].x2 < tab[i].x2)
            {
                naj = y;
                kto = i;
            }
        }
        if(kto == -1)
        {
            cout << wyn;
            return 0;
        }
        akt = kto;
    }
}
