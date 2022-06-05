#include <bits/stdc++.h>

using namespace std;

const int r = 1e7 + 9;
string slo;
const long long a = 997, b = 313, N = 1e9 + 7, M = 1e9 + 9;

long long h[2][r];
long long h1[2][r];
long long pot[r];
long long potb[r];

pair<long long, long long> hasz(int x, int poc, int d)
{
    return {(h[x][poc + d]-((h[x][poc] * pot[d]) % N) + N) % N, (h1[x][poc + d] - ((h1[x][poc] * potb[d]) % M) + M) % M};
}

bool por(int p, int q, int d)
{
    return hasz(0, p, d) == hasz(1, q, d);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int m = s2.size();
    int n = s1.size();
    pot[0] = 1;
    potb[0] = 1;
    for(int j = 0;j < n;j++)
    {
        pot[j + 1] = (pot[j] * a) % N;
        potb[j + 1] = (potb[j] * b) % M;
        h[0][j + 1] = (h[0][j] * a + s1[j]) % N;
        h1[0][j + 1] = (h1[0][j] * b + s1[j]) % M;
    }
    for(int j = 0;j < m;j++)
    {
        pot[j + 1] = (pot[j] * a) % N;
        potb[j + 1] = (potb[j] * b) % M;
        h[1][j + 1] = (h[1][j] * a + s2[j]) % N;
        h1[1][j + 1] = (h1[1][j] * b + s2[j]) % M;
    }
    int naj = 0;
    for(int i = 0; i < m - n + 1; i++)
    {
        int lo = 0, hi = n + 1;
        while(lo < hi)
        {
            int sr = (lo + hi) / 2;
            if(por(0, i, sr))
            {
                lo = lo + 1;
            }
            else
            {
                hi = sr;
            }
        }
        int p = hi - 1;
        lo = 0, hi = n + 1;
        while(lo < hi)
        {
            int sr = (lo + hi) / 2;
            if(por(n - sr, i + n - sr, sr))
            {
                lo = lo + 1;
            }
            else
            {
                hi = sr;
            }
        }
        int k = hi - 1;
        int wyn = min(n, p + k);
        //cout << wyn << " ";
        naj = max(wyn, naj);
    }
    cout << n - naj;
}