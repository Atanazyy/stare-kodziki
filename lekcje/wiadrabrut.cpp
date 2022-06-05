#include <bits/stdc++.h>

using namespace std;

int tab[100];
int wyn[100];

int main()
{
    int n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
    {
        cin >> tab[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int p, k, v;
        cin >> p >> k >> v;
        for(int j = p; j <= k; j++)
        {
            tab[j] -= v;
            if(tab[j] <= 0 && wyn[j] == 0) wyn[j] = i;
        }
    }
    for(long long i = 1; i <= n; i++)
    {
        if(wyn[i] == 0) cout <<"NIE\n";
        else cout << wyn[i] << "\n";
    }
}