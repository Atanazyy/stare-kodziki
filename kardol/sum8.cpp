#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
long long dp[209][209][209];  //miejsce, suma, reszta
vector <int> wyn[10 * 1000 + 9]; 
vector <pair<long long, int> > tab;
int pre[209];

int mod(int w)
{
    return pre[w];
}

void wyp(int mie, int s, int r, int m, long long poz, int x)
{
    //cout << mie <<" " << s << " " << r << " " << m << "\n";
    if(mie == 0)
    {
        wyn[x].push_back(s);
        return;
    }
    long long byl = 0;
    for(int c = 0; c <= 9; c++)
    {
        int ns = s - c;
        int nr = ((r - (c * mod(mie)) % m) + m) % m;
        byl += dp[mie - 1][ns][nr];
        if(byl >= poz)
        {
            wyn[x].push_back(c);
            wyp(mie - 1, ns, nr, m, poz - byl + dp[mie - 1][ns][nr], x);
            return;
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int s, m, q;
    cin >> s >> m >> q;
    pre[0] = 1 % m;
    for(int i = 1; i <= 200; i++)
        pre[i] = (10 * pre[i - 1]) % m;
    for(int i = 0; i <= 9; i++)
        dp[0][i][i % m] = 1;
    for(int i = 0; i < q; i++)
    {
        long long k;
        cin >> k;
        if(k == dp[0][s][0])
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
            for(int k = 0; k < m; k++)
            {
               // cout << i << " " << j << " " << k << "\n";
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
        while(dp[i][s][0] >= tab[nr].first)
        {
            //cout <<"XD";
            wyp(i, s, 0, m, tab[nr].first, tab[nr].second);
           // cout << wyn[0].size() << "\n";
            nr++;
        }
        //cout << "\n";
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