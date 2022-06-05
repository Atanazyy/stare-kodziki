#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
long long dp[209][209][209];  //miejsce, suma, reszta
vector <int> wyn; 
int pre[209];

int mod(int w)
{
    return pre[w];
}

void wyp(int mie, int s, int r, int m)
{
    //cout << mie <<" " << s << " " << r << " " << m << "\n";
    if(mie == 0)
    {
        wyn.push_back(s);
        return;
    }
    for(int c = 0; c <= 9; c++)
    {
        int ns = s - c;
        int nr = ((r - (c * mod(mie)) % m) + m) % m;
        if(dp[mie - 1][ns][nr] > 0)
        {
            wyn.push_back(c);
            wyp(mie - 1, ns, nr, m);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, m, q;
    cin >> s >> m >> q;
    pre[0] = 1 % m;
    for(int i = 1; i <= 200; i++)
        pre[i] = (10 * pre[i - 1]) % m;
    for(int i = 0; i <= 9; i++)
        dp[0][i][i % m] = 1;
    if(dp[0][s][0] > 0)
    {
        while(q--)
        {
            int k;
            cin >> k;
            cout << s <<"\n";
        }
        return 0;
    }
    for(int i = 1; i < 200; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            for(int k = 0; k < m; k++)
            {
                for(int c = 0; c <= min(9, j); c++)
                {
                    int ns = j - c;
                    int nm = ((k - (c * mod(i)) % m) + m) % m;
                    dp[i][j][k] += dp[i - 1][ns][nm];
                    dp[i][j][k] = min(dp[i][j][k], inf);
                }
                //cout << i << " " << j << " " << k << ": " <<dp[i][j][k] <<"\n"; 
                //cout << dp[i][j][k] << " ";
            }
            //cout << "\n";
        }
        if(dp[i][s][0] > 0)
        {
            wyp(i, s, 0, m);
            while(q--)
            {
                int k;
                cin >> k;
                for(auto x : wyn)
                    cout << x;
                cout << "\n";
            }
            return 0;
        }
        //cout << "\n";
    }
    while(q--)
    {
        int k;
        cin >> k;
        cout <<"NIE\n";
    }
}