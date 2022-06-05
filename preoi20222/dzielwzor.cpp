#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9, d = 1e6;
int tab[r];

struct S
{
    void solve()
    {
        long long n, on;
        cin >> n;
        on = n;
        int rek = 0, co = 0;
        for(int i = 2; i <= d; i++)
        {
            int ile = 0;
            while(n % i == 0 && n > 1)
            {
                ile ++;
                n /= i;
            }
            if(rek < ile)
            {
                rek = ile;
                co = i;
            }
        }
        long long pie = sqrt(n);
        if(n != 1 && pie * pie == n && rek < 2)
        {
            rek = 2;
            co = pie;
        }
        else if(n != 1 && rek == 0)
        {
            rek = 1;
            co = pie;
        }
        cout << rek << "\n";
        for(int i = 1; i < rek; i++)
        {
            cout << co << " ";
            on /= co;
        }
        cout << on << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int Z;
    cin >> Z;
    while(Z--)
    {
        S s;
        s.solve();
    }
}
