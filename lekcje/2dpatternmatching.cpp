#include <bits/stdc++.h>

using namespace std;

const int r = 1000;
long long p1 = 997, p2 = 313, N = 1e9 + 7;
long long tab[r][r], szu[r][r], pot1[r], pot2[r];
string wzo[r];
string mac[r];

long long hasz(long long x, long long y, long long dx, long long dy)
{
    return (2 * N + tab[x + dx][y + dy] + (((tab[x][y] * pot1[dx]) % N) * pot2[dy]) % N - (tab[x + dx][y] * pot2[dy]) % N - (tab[x][y + dy] * pot1[dx]) % N) % N;
}

int main()
{
    long long n, m, l, k;
    cin >> n >> m;
    for(long long i = 0; i < n; i++)
        cin >> wzo[i];
    cin >> l >> k;
    for(long long i = 0; i < l; i++)
        cin >> mac[i];
    pot1[0] = 1;
    pot2[0] = 1;
    for(long long i = 0; i <= max(l, k); i++)
    {
        pot1[i + 1] = (pot1[i] * p1) % N;
        pot2[i + 1] = (pot2[i] * p2) % N;
    }
    for(long long i = 1; i <= l; i++)
    {
        for(long long j = 0; j < k; j++)
        {
            tab[i][j + 1] = (tab[i][j] * p2 + mac[i - 1][j]) % N;
        }
    }
    for(long long i = 0; i < l; i++)
    {
        for(long long j = 1; j <= k; j++)
        {
            tab[i + 1][j] = (tab[i + 1][j] + (tab[i][j] * p1)) % N;
        }
    }
    /*for(long long i = 1; i <= l; i++)
    {
        for(long long j = 1; j <= k; j++)
            cout << tab[i][j] << " ";
        cout << "\n";
    }*/
   // long long x, y, dx, dy;
    //cin >> x >> y >> dx >> dy;
    //cout << N <<" " << hasz(x, y, dx, dy) << " " << (N > hasz(x, y, dx, dy)) << "\n";
    for(long long i = 1; i <= n; i++)
    {
        for(long long j = 0; j < m; j++)
        {
            szu[i][j + 1] = (szu[i][j] * p2 + wzo[i - 1][j]) % N;
        }
    }
    for(long long i = 0; i < n; i++)
    {
        for(long long j = 1; j <= m; j++)
        {
            szu[i + 1][j] = (szu[i + 1][j] + (szu[i][j] * p1)) % N;
        }
    }
    vector<pair<long long, long long> > wyn;
    //cout << szu[n][m] << "\n";
    for(long long i = 0; i <= l - n; i++)
    {
        for(long long j = 0; j <= k - m; j++)
        {
            if(hasz(i, j, n, m) == szu[n][m])
            {
                wyn.push_back({i, j});
            }
        }
    }
    cout << wyn.size() << "\n";
    sort(wyn.begin(), wyn.end());
    for(auto xd : wyn)
        cout << xd.first + 1<< " " << xd.second + 1<< "\n";
}