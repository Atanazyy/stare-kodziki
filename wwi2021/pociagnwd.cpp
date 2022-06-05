#include <bits/stdc++.h>

using namespace std;

const int r = 5e5+9;
int tab[r];
int o[2*r];
vector <int> dzie[2*r];
int dp[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    int n;
    cin >> n;
    int maxn = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
        maxn = max(maxn, tab[i]);
    }
    int wyn = 0;
    for(int i = 2; i <= maxn; i++)
    {
        if(dzie[i].size()!=0)
            continue;
        dzie[i].push_back(i);
        for(int j = i * 2 ; j <= maxn; j += i)
        {
            dzie[j].push_back(i);
        }
    }
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int x : dzie[tab[i]])
            dp[i] = max(o[x]+1, dp[i]);
        for(int x : dzie[tab[i]])
            o[x] = dp[i];
        wyn = max(wyn, dp[i]);
        //cout<<dp[i]<<" ";
    }
    cout << wyn;
}