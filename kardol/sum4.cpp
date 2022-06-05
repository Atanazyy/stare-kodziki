#include <bits/stdc++.h>

using namespace std;

long long dp[209][209];
const long long inf = 1e18;

void wyp(int mie, int s, int poz)
{
    if(mie == 0)
    {
        cout << s;
        return;
    }
    int byl = 0;
    for(int c = 0; c <= 9; c++)
    {
        byl += dp[mie - 1][s - c];
        if(byl >= poz)
        {
            cout << c;
            wyp(mie - 1, s - c, poz - byl + dp[mie - 1][s - c]);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, m, q, k;
    cin >> s >> m >> q >> k;
    for(int i = 0; i <= 9; i++)
        dp[0][i] = 1;
    if(1 == k && s <= 9)
    {
        cout << s ;
        return 0;
    }
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
        if(dp[i][s] >= k)
        {
            wyp(i, s, k);
            return 0;
        }
    }
    cout << "NIE\n";
}