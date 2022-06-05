#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

long long drz[r];
int roz;
char tab[r];

void pus(int v, int w)
{
    v += roz;
    drz[v] = w;
    v /= 2;
    while(v > 0)
    {
        drz[v] = drz[2 * v] + drz[2 * v + 1];
        v /= 2;
    }
}

long long czy(int a, int b)
{
    a += roz;
    b += roz;
    if(a == b) return drz[a];
    long long wyn = drz[a] + drz[b];
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0) wyn = wyn + drz[a + 1];
        if(b % 2 == 1) wyn = wyn + drz[b - 1]; 
        a /= 2;
        b /= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    long long akt = 0;
    cin >> n >> m;
    roz = ceil(log2(n));
    roz = 1 << roz;
    roz --;
    int ip = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        if(tab[i] == 'P') 
        {
            ip++;
            pus(i, 1);
        }
        else akt += ip;
    }
    cout << akt << "\n";
    while(m --)
    {
        int x;
        cin >> x;
        if(tab[x] == 'P')
        {
            tab[x] = 'K';
            akt -= n - x + 1 - czy(x, n);
            pus(x, 0);
            akt += czy(1, x);
        }
        else
        {
            tab[x] = 'P';
            akt -= czy(1, x);
            pus(x, 1);
            akt += n - x + 1 - czy(x, n);
        }
        cout << akt << "\n";
    }
}