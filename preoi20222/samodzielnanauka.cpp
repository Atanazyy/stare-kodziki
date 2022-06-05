#include <bits/stdc++.h>

using namespace std;

const long long r = 1e6;
long long n, m;
long long A[r], B[r];

bool czy(long long mw)
{
    long long dom = 0;
    long long szk = 0;
    for(int i = 1; i <= n; i++)
    {
        long long pot = mw / A[i];
        if(pot * A[i] != mw)
            pot ++;
        if(pot <= m)
        {
            //cout << pot << " 0\n";
            szk += pot;
        }
        else
        {
            long long zos = mw - A[i] * m;
            long long wyp = zos / B[i];
            if(B[i] * wyp != zos)
                wyp++;
            //cout << m << " " << wyp << "\n";
            if(m + wyp > n * m)
                return 0;
            szk += m;
            dom += wyp;
        }
        if(szk + dom > n * m)
            return 0;
    }
    return szk + dom <= n * m;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    for(int i = 1; i <= n; i++)
        cin >> B[i];
    for(int i = 1; i <= n; i++)
        A[i] = max(A[i], B[i]);
    long long p = 0, k = LONG_MAX;
    while(p < k)
    {
        long long sr = (p + k) / 2;
        if(czy(sr))
        {
            p = sr + 1;
        }
        else
        {
            k = sr;
        }
    }
    cout << k - 1;
}
