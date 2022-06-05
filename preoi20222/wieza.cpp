#include <bits/stdc++.h>

using namespace std;

const long long r = 1e6;
pair<long long, long long> tab[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue <pair<double, long long> > pq;
    long long n, k;
    cin >> n >> k;
    for(long long i = 0; i < n; i++)
    {
        cin >> tab[i].first;
        double xd = tab[i].first;
        tab[i].second = 1;
        pq.push({xd - (xd / 2), i});
    }
    k -= n;
    while(k --)
    {
        long long i = pq.top().second;
        pq.pop();
        tab[i].second ++;
        double xd = tab[i].first;
        pq.push({xd / tab[i].second - xd / (tab[i].second + 1), i});
    }
    double wyn = 0;
    for(long long i = 0; i < n; i++)
    {
        double xd = tab[i].first;
        wyn += xd / tab[i].second;
    }
    cout << round(wyn);
}
