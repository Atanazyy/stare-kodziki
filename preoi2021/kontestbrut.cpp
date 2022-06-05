#include <bits/stdc++.h>

using namespace std;

vector<pair <long long, long long> > tab[1009];
long long pkt[1009];
long long wyn[1009];
int main()
{
    long long n, m, t;
    cin >> n >> m >> t;
    long long mi = 100000;
    for(long long i = 0; i < m; i++)
    {
        long long a, s, p;
        cin >> a >> s >> p;
        tab[s].push_back({a, p});
        mi = min(mi, s);
    }
    for(long long j = mi; j <= t; j++)
    {
        for(auto x: tab[j])
            pkt[x.first] += x.second;
        long long ma = 0;
        for(long long i = 1; i <= n; i++)
            ma = max(ma, pkt[i]);
        for(long long i = 1; i <= n; i++)
            if(pkt[i] == ma)
                wyn[i]++;
    }
    int ma = 0;
    int co = 0;
    for(long long i = 1; i <= n; i++)
    {
        if(wyn[i] > ma)
        {
            ma = wyn[i];
            co = i;
        }
    }
    cout << co;
}