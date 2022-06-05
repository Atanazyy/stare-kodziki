#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens                                                                                                                                           
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation                                                                            
#pragma GCC target("movbe")                                      // byte swap   
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption  
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#include <bits/stdc++.h>

using namespace std;

const int p1 = 313, p2 = 997, N = 1e9 + 7, M = 1e9 + 9, r = 1e6;
long long h1[r], h2[r], pot1[r], pot2[r];
int n, le;
string s;

inline int hasz(int p, int roz)
{
    return (h1[p + roz] - (h1[p] * pot1[roz]) % N + N) % N;
}

inline int solve(int a, int b, int l)
{
    int p = 1, k = l + 1;
    while (p < k)
    {
        int  sr = (p + k) / 2;
        if(hasz(a, sr) == hasz(b, sr))
            p = sr + 1;
        else
            k = sr;
    }
    return k;
}

inline bool por(int a, int b)
{
    int x = solve(a, b, le);
    return s[a + x - 1] > s[b + x - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> le >> s;
    for(int i = le; i < 2 * le; i++)
        s += (char)('a' - 1);
    n = s.size();
    pot1[0] = 1;
    for(int i = 0; i < n; i++)
    {
        pot1[i + 1] = (pot1[i] * p1) % N;
        h1[i + 1] = (h1[i] * p1 + s[i]) % N;
    }
    vector<int> vec;
    for(int i = 0; i < le; i++)
        vec.push_back(i);
    sort(vec.begin(), vec.end(), por);
    /*for(auto x: vec)
        cout << x << " ";*/
    cout << vec[0] + 1;
}