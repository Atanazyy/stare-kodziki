#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
int tab[r];
long long wyn[r];

struct S
{
    long long zos = 1;
    void roz(long long n)
    {
        for(int i = 2; i <= ceil(sqrt(n)); i++)
        {
            while(n > 1 && n % i == 0)
            {
                n /= i;
                tab[i] ++;
            }
        }
        zos = n;
    }

    void solve()
    {
        long long n;
        cin >> n;
        for(int i = 0; i <= ceil(sqrt(n)); i++)
        {
            wyn[i] = 1;
            tab[i] = 0;
        }
        roz(n);
        int wie = 0;
        for(int i = 2; i <= ceil(sqrt(n)); i++)
        {
            for(int j = 0; j < tab[i]; j++)
                wyn[j] *= i;
            if(tab[i] > 0)
                wie = max(wie, tab[i]);
        }
        if(zos != 1)
        {
            wie = max(wie, 1);
            wyn[0] *= zos;
        }
        cout << wie << "\n";
        /*for(int i = wie - 1; i >= 0; i--)
        {
            cout << wyn[i] << " ";
        }
        cout << "\n";*/
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
