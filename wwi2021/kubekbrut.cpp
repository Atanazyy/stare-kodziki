#include <bits/stdc++.h>

using namespace std;

const int p = 1e9 + 7;

int main()
{
    int n, N = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        N= N * m;
    }
    int d = 1, nd = 0;
    while(N--)
    {
        int x = d;
        d = nd;
        nd = x + nd;
    }
    cout << d / __gcd(d, nd + d) << "/" << (nd + d) / __gcd(d, d + nd);
}