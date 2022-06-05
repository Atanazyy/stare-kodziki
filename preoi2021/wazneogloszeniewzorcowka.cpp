#include <bits/stdc++.h>

using namespace std;

const int r = 3e5 + 9;
int tab[r];
double pre[r];
int n, k;

bool czy(double x)
{
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + tab[i] - x;
    double naj = 0;
    int s = 0;
    for(int i = k; i <= n; i++)
    {
        naj = min(naj, pre[s]);
        s++;
        if(pre[i] - naj >= 0) return 1;
    }
    return 0;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    double poc = 1, kon = 1e6, eps = 0.000001;
    while (kon - poc > eps)
    {
        double sr = (poc + kon) / 2;
        if(czy(sr)) poc = sr;
        else kon = sr;
    }
    
    cout << fixed << setprecision(3) << kon;
}