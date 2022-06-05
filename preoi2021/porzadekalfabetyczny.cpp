#include <bits/stdc++.h>

using namespace std;

const int r = 509, rl = 20 * 1000 + 9;
string tab[r];
const long long a = 997, b = 313, N = 1e9 + 7, M = 1e9 + 9;

long long h[r][rl];
long long h1[r][rl];
long long pot[rl];
long long potb[rl];

pair<long, long> hasz(int x, int poc, int d)
{
    return {(h[x][poc + d]-((h[x][poc] * pot[d]) % N) + N) % N, (h1[x][poc + d] - ((h1[x][poc] * potb[d]) % M) + M) % M};
}

int spr(int s1, int s2 ,int p, int q)
{   
    int d = q - p + 1;
    int lo = 0;
    int hi = d;
    while(lo < hi)
    {
        int sr = (lo + hi) / 2;
        if(hasz(s1, p , sr) == hasz(s2, p, sr))
        {
            lo = sr + 1;
        }
        else
        {
            hi = sr;
        }
    }
    return tab[s1][p + hi - 1] < tab[s2][p + hi - 1];
}

pair <bool, pair<int, int> > czy (int n, int l, int d)
{
    for(int i = 0; i < l; i++)
    {
        bool f = 1;
        for(int j = 0; j < n - 1; j++)
        {
            if(!spr(j, j + 1, i, min(i + d - 1, l - 1)))
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
    pot[0] = 1;
    potb[0] = 1;
    for(int j = 0;j < l;j++)
    {
        pot[j + 1] = (pot[j] * a) % N;
        potb[j + 1] = (potb[j] * b) % M;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
        for(int j = 0;j < l;j++)
        {
            h[i][j + 1] = (h[i][j] * a + tab[i][j]) % N;
            h1[i][j + 1] = (h1[i][j] * b + tab[i][j]) % M;
            pot[j + 1] = (pot[j] * a) % N;
            potb[j + 1] = (potb[j] * b) % M;
        }
    }
    if(l == 1)
    {
        cout << "1 1";
        return 0;
    }
    //int x, p, d;
    //cin >> x >> p >> d;
    //cout << hasz(x, p, d).first << " " << hasz(x, p ,d).second;
    //int s1, s2, p, q;
    //cin >> s1 >> s2 >> p >> q;
    //cout << spr(s1, s2, p, q);
    //int x;
    //cin >> x;
    //cout << czy(n, l, x).first << " " << czy(n, l, x).second.first << " " << czy(n, l, x).second.second << "\n";
    int p = 1, k = 500;
    int wyn = 0;
    int s1, s2;
    while(p < k)
    {
       // cout<<  p << " " << k << "\n";
        int sr = (p + k) / 2;
        auto w = czy(n, l, sr);
        if(w.first)
        {
            k = sr;
            wyn = sr;
            s1 = w.second.first;
            s2 = w.second.second;
        }
        else p = sr + 1;
    }
    auto w = czy(n, l, k);
    if(w.first)
    {
        wyn = k;
        s1 = w.second.first;
        s2 = w.second.second;
    }
    cout <<s1 << " " << s2 <<"\n";
   // cout << czy(n, l, 1).first;
}