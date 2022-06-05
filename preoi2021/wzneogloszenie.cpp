#include<bits/stdc++.h>

using namespace std;

const int r = 5e5;
int tab[r];
pair<long long, int> dp[r];

bool com(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first * b.second >= b.first * a.second;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    long long ost = 0;
    for(int i = 1; i <= k; i++)
        ost += tab[i];
    dp[k] = {ost, k};
    for(int i = k + 1; i <= n; i++)
    {
        ost += tab[i] - tab[i - k];
        dp[i] = {ost, k};
        if(com({dp[i - 1].first + tab[i], dp[i - 1].second + 1}, dp[i]))
            dp[i] = {dp[i - 1].first + tab[i], dp[i - 1].second + 1};
        //cout << dp[i].first << " " << dp[i].second << "\n";
    }
    pair <long long, long long> rek;
    for(int i = k; i <= n; i++)
    {
        if(com(dp[i], rek))
            rek = dp[i];
    }
    double a = rek.first, b = rek.second, wyn = a / b;
    cout << fixed;
    cout << setprecision(3) << wyn;
}