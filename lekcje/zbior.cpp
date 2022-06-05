#include <bits/stdc++.h>

using namespace std;

const int roz = 1 << 19 - 1; 
int drz[2 * roz + 9];

void pus(int v, int x)
{
    v += roz;
    drz[v] = x;
    v /= 2;
    while(v > 0)
    {
        drz[v] = drz[v * 2] + drz[v * 2 + 1];
        v /= 2;
    }
}

int czy(int x, int v)
{
    if(v > roz) return v - roz;
    if(x > drz[2 * v]) return czy(x - drz[2 * v], v * 2 + 1);
    return czy(x, v * 2);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int o, x;
        cin >> o >> x;
        if(o == 1) pus(x, 1); 
        if(o == 2) pus(x, 0);
        if(o == 3) cout << czy(x, 1) << "\n";
    }
}