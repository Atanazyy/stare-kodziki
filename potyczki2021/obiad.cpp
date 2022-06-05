#include <bits/stdc++.h>

using namespace std;

struct skl
{
    int v;
    int l;
    int r;
    int id;
};

const int r = 1e6;
int roz;
skl tab[r];
int drz[2 * r][2];

pair<int, int> kuery(int a, int b)
{
    a += roz + 1;
    b += roz + 1;
    if(a == b)
        return {drz[a][0], drz[a][1]};
    int mi = max(drz[a][0], drz[b][0]), ma = min(drz[a][1], drz[b][1]);
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0)
        {
            mi = max(mi, drz[a + 1][0]);
            ma = min(ma, drz[a + 1][1]);
        }
        if(b % 2 == 1)
        {
            mi = max(mi, drz[b - 1][0]);
            ma = min(ma, drz[b - 1][1]);
        }
        a /= 2;
        b /= 2;
    }
    return {mi, ma};
}

bool por(skl a, skl b)
{
    return (a.v < b.v);
}

int main()
{
    int N;
    cin >> N;
    roz = ceil(log2(N));
    roz = 1 << roz;
    for(int i = 0; i < N; i++)
    {
        cin >> tab[i].v >> tab[i].l >> tab[i].r;
        tab[i].id = i;
    }
    sort(tab, tab + N, por);
    for(int i = 0; i < N; i++)
    {
        drz[roz + 1 + i][0] = tab[i].l;
        drz[roz + 1 + i][1] = tab[i].r;
    }
    for(int i = roz; i >= 1; i--)
    {
        drz[i][0] = max(drz[2 * i][0], drz[2 * i + 1][0]);
        drz[i][1] = min(drz[2 * i][1], drz[2 * i + 1][1]);
    }
    /*for(int i = 0; i < N; i++)
        cout << tab[i].v << " " << tab[i].l << " " << tab[i].r << "\n";*/
    int j = 0;
    int poc, kon, rek = -1;
    for(int i = 0; i < N; i++)
    {
        j = max(j, i);
        auto xd = kuery(i, j + 1);
        int l = xd.first;
        int p = xd.second;
        while(j + 1 < N && tab[i].v >= l && tab[j + 1].v <= p)
        {
            j ++;
            xd = kuery(i, j + 1);
            l = xd.first;
            p = xd.second;
            //cout << i << " " << j  + 1<< " " << l << " "<< p << " " << "\n";
        }
        if(j - i + 1 > rek)
        {
            rek = j - i + 1;
            poc = i;
            kon = j;
        }
    }
    cout << rek << "\n";
    vector<int> wyn;
    for(int i = poc; i <= kon; i++)
        wyn.push_back(tab[i].id + 1);
    sort(wyn.begin(), wyn.end());
    for(auto x : wyn)
        cout << x << " ";
}