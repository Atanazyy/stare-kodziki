#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens                                                                                                                                           
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation                                                                            
#pragma GCC target("movbe")                                      // byte swap   
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption  
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
int roz;
int sum[r];
int gw[r];
int ost[r][10];

inline int mod(int a, int b)
{
    if(a + b >= 10) return a + b - 10;
    return a + b;
}

inline void zep (int v)
{
    int temp[10];
    for(int j = 0; j < 10; j++)
        temp[mod(gw[v], j)] = ost[v][j];
    sum[v] = 0;
    for(int j = 0; j < 10; j++)
    {
        ost[v][j] = temp[j];
        sum[v] += j * ost[v][j];
    }
    gw[v << 1] = mod(gw[v << 1], gw[v]);
    gw[(v << 1) + 1] = mod(gw[(v << 1) + 1], gw[v]);
    gw[v] = 0;
}

void ubdat(int a, int b, int v, int p, int k, int x)
{
    if(a > k || b < p)
    {
        zep(v);
        return;
    }
    if(p >= a && k <= b)
    {
        gw[v] = mod(x, gw[v]);
        zep(v);
        return;
    }
    zep(v);
    int sr = (p + k) >> 1;
    ubdat(a, b, (v << 1), p, sr, x);
    ubdat(a,  b, (v << 1) + 1, sr + 1, k, x);
    sum[v] = sum[v << 1] + sum[(v << 1) + 1];
    for(int j = 0; j < 10; j++)
        ost[v][j] = ost[(v << 1)][j] +ost[(v << 1) + 1][j]; 
}

int kuery(int a, int b, int v, int p, int k)
{
    zep(v);
    if(a > k || b < p)
        return 0;
    if(p >= a && k <= b)
        return sum[v];
    int sr = (p + k) >> 1;
    return kuery(a, b, (v << 1), p, sr) + kuery(a,  b, (v << 1) + 1, sr + 1, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        y = x % 10;
        sum[i + roz] = y;
        ost[i + roz][y] = 1;
    }
    for(int i = roz - 1; i > 0; i--)
    {
        sum[i] = sum[(i << 1)] + sum[(i << 1) + 1]; 
        for(int j = 0; j < 10; j++)
            ost[i][j] = ost[(i << 1)][j] + ost[(i << 1) + 1][j]; 
    }
    while(q--)
    {
        char z;
        int a, b;
        cin >> z >> a >> b;
        if(z == '?') 
            cout << kuery(a, b, 1, 1, roz) << "\n";
        else
        {
            int x;
            cin >> x;
            ubdat(a, b, 1, 1, roz, x % 10);
        }
    }
}