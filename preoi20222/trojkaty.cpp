#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

struct pkt
{
    long long x;
    long long y;
};

const int r = 1009;

pkt tab[r];
pair<pkt, pkt> tro[r];

bool f(int i, int j)
{
    long long C = -tro[i].f.y * tro[i].s.x;
    long long Cp = -tab[j].x * tro[i].f.y -tab[j].y * tro[i].s.x;
    return Cp > C;
}

int main()
{
    int k, m;
    cin >> k >> m;
    for(int i = 0; i < k; i++)
        cin >> tab[i].x >> tab[i].y;
    for(int i = 0; i < m; i++)
        cin >> tro[i].f.x >> tro[i].f.y >> tro[i].s.x >> tro[i].s.y;
    for(int i = 0; i < m; i++)
    {
        bool c = 0;
        for(int j = 0; j < k; j++)
        {
            c |= f(i, j);
            if(f(i, j))
                break;
        }
        if(c)
            cout << "T\n";
        else
            cout << "N\n";
            //cout << i << " " << j << " " << f(i, j) << "\n";
    }
}
