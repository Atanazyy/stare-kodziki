#include <bits/stdc++.h>

using namespace std;

int sol(long long n, long long mam, long long mem)
{
    //cout << mam << " "<< mem <<"\n";
    if(mam > n) return 0;
    if(mam + mem > n) return 1;
    if(mam + 2 * mem > n) return 2;
    return sol(n, 2 * mam, mam) + 2;
}

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    int wyn = sol(n, 1, 0);
    int akt = 2;
    //cout << sol(n, 3, 1) + 3 <<"\n";
    for(long long i = 2; i <= n; i *= 2)
    {
        //cout << i + i / 2 << " " << i / 2 << " " << akt + 1 << " " << sol(n, i + i / 2, i / 2) + akt + 1 <<"\n";
        wyn = min(wyn, sol(n, i + i / 2, i / 2) + akt + 1);
        akt += 2;
    }
    cout << wyn;
}