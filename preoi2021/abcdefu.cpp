#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9, sig = 65, mod = 1e9 + 7;
long long tab[r], L[r][sig], dp[sig][sig][5], S[r], SUM;

int main()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] <= '9')
            tab[i] = s[i] - '0';
        else if(s[i] <= 'Z')
            tab[i] = 10 + s[i] - 'A';
        else 
            tab[i] = 10 + 26 + s[i] - 'a';
        if(i >= 1) 
            for(int j = 0; j < sig; j++)
                L[i][j] = L[i - 1][j];
        L[i][tab[i]] ++; 
        //cout << tab[i] << " ";
    }
    int wyn = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < sig; j++)
        {
            if(tab[i] == j)
                continue;
            wyn = (wyn + L[i][j] * (SUM - S[tab[i]] - S[j] + dp[tab[i]][j][4] + dp[j][tab[i]][4] + mod + mod)) % mod;
        }
        for(int j = 0; j < sig; j++)
        {
            if(tab[i] == j)
                continue;
            dp[j][tab[i]][1] ++;
            dp[tab[i]][j][2] = (dp[tab[i]][j][2] + dp[tab[i]][j][1]) % mod;
            dp[j][tab[i]][3] = (dp[j][tab[i]][3] + dp[j][tab[i]][2]) % mod;
            dp[tab[i]][j][4] = (dp[tab[i]][j][4] + dp[tab[i]][j][3]) % mod;
            S[tab[i]] = (S[tab[i]] + dp[tab[i]][j][3]) % mod;
            S[j] = (S[j] + dp[tab[i]][j][3]) % mod;
            SUM = (SUM + dp[tab[i]][j][3]) % mod;
        }
    }
    cout << wyn;
}