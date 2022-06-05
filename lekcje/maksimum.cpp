#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

long long drz[r];
int roz;

void pus(int v, int w)
{
    v += roz;
    drz[v] += w;
    v /= 2;
    while(v > 0)
    {
        drz[v] = max(drz[2 * v], drz[2 * v + 1]);
        v /= 2;
    }
}

long long czy(int a, int b)
{
    a += roz;
    b += roz;
    if(a == b) return drz[a];
    long long wyn = max(drz[a], drz[b]);
    while(a / 2 != b / 2)
    {
        if(a % 2 == 0) wyn = max(wyn, drz[a + 1]);
        if(b % 2 == 1) wyn = max(wyn, drz[b - 1]); 
        a /= 2;
        b /= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    roz = ceil(log2(n));
    roz = 1 << roz;
    roz --;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pus(i, x);
    }
    while(m --)
    {
        //for(int i = 1; i <= roz + n; i++) cout << drz[i] << " "; cout << "\n";
        char z;
        cin >> z;
        if(z == '+')
        {
            int x, v;
            cin >> v >> x;
            pus(v, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << czy(a, b) << "\n";
        }
    }
}