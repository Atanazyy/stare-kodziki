#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
long long tab[r];
long long N, K;
long double xd;


long long czy(long double x)
{
    long long wyn = 0;
    xd = 0;
    for(int i = 0; i < N; i++)
    {
        long double k = floor((x + sqrt(x * x + 4 * tab[i] * x)) / (2 * x));
        wyn += k;
        //cout << k << " " << tab[i] << "\n" ;
        xd += tab[i] / k;
    }
    return wyn;
}

int main()
{
    //cout << fixed;
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> tab[i];
    }
    long double p = 0, k = 1e18;
    long double eps = 1e-15;
    //cin >> k;
    //k++;
    while(k - p > eps)
    {
        //cout << p << " " << k << "\n";
        long double sr = (p + k) / 2;
        if(czy(sr) > K)
        {
            p = sr;
        }
        else
        {
            k = sr;
        }
    }
    //cout << k << " ";
    cout << (long long)round(xd);
}
