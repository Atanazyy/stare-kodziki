#include <bits/stdc++.h>

using namespace std;

long long dp[209][209];
vector <pair<long long, int> > tab;
vector<int> wyn[10 * 1000 + 9];
const long long inf = 1e18;

void wyp(int mie, int s, long long poz, int x)
{
    if(mie == 0)
    {
        wyn[x].push_back(s);
        return;
    }
    long long byl = 0;
    for(int c = 0; c <= 9; c++)
    {
        byl += dp[mie - 1][s - c];
        if(byl >= poz)
        {
            wyn[x].push_back(c);
            wyp(mie - 1, s - c, poz - byl + dp[mie - 1][s - c], x);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, m, q;
    cin >> s >> m >> q;
    for(int i = 0; i <= 9; i++)
        dp[0][i] = 1;
    for(int i = 0; i < q; i++)
    {
        long long k;
        cin >> k;
        if(1 == k && s <= 9)
            wyn[i].push_back(s);
        else
            tab.push_back({k, i});
    }
    sort(tab.begin(), tab.end());
    tab.push_back({2e18, q});
    int nr = 0;
    for(int i = 1; i < 200; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            for(int l = 0; l <= min(9, j); l++)
            {
                dp[i][j] += dp[i - 1][j - l];
                dp[i][j] = min(dp[i][j], inf);
            }
        }
        while(dp[i][s] >= tab[nr].first)
        {
            wyp(i, s, tab[nr].first, tab[nr].second);
            nr++;
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(wyn[i].size() == 0)
        {
            cout << "NIE\n";
        }
        else
        {
            for(auto x: wyn[i])
            {
                cout << x;
            }
            cout <<"\n";
        }
    }
}