#include <bits/stdc++.h>

using namespace std;

const int r = 1e6, mod = 1e9 + 7;
vector<int> tab[r];
long long wyn[r];

int main()
{
    int n, k, m;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[min(a, b)].push_back(max(a, b));
    }
    wyn[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(auto x : tab[i])
        {
            if(x > i)
                wyn[x] = (wyn[x] + wyn[i]) % mod;
        }
        //cout << wyn[i] << " ";
    }
    cout << wyn[n]
}
