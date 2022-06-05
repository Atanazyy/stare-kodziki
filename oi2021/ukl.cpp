#include <bits/stdc++.h>

using namespace std;

const int r = 2e6 + 9;
long long sil[r];
int n;

long long sum(int x)
{
    long long wyn = 0;
    for(int i = n - x; i <= n - 1; i++)
    {
        wyn += i;
    }
    return wyn;
}

long long sss(int x)
{
    if(x < 0) return 1;
    else return sil[x];
}

int main()
{
    long long wyn = 0;
    cin >> n;
    sil[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        sil[i] = sil[i - 1] * i;
    }
    for(int i = 1; i <= n; i++)
    {
        long long odj = sss(n - 1) / sss(n - i);
        odj = odj * n * (n - 1);
        cout << odj << " ";
        wyn = wyn - odj;
        //cout << odj << " ,";
        int d = n - 1; 
        for(int j = 1; j <= i - 1 + n; j++)
        {
            // wyn = 0;
            wyn = wyn + sum(d) * sss(n - 1) / d;
            if(d != 1) d--;
            cout << wyn << " ";
        }
        cout << "\n";
    }
}