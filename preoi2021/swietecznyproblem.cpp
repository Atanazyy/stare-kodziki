#include <bits/stdc++.h>

using namespace std;

map <int, int> mapa;
const int r = 50;
int tab[r];

int f(int x, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(x % 2)
            sum += tab[i];
        x /= 2;
    }
    return sum;
}

void wyp(int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << x % 2;
        x /= 2;
    }
}

int main()
{
    int n, s;
    cin >> n;
    int p = n / 2;
    for(int i = 0; i < n / 2; i++)
        cin >> tab[i];
    for(int i = 0; i < (1 << (n / 2)); i++)
        mapa[f(i, n / 2)] = i;
    for(int i = n / 2; i < n; i++)
        cin >> tab[i - n / 2];
    cin >> s;
    int d = n - (n / 2);
    for(int i = 0; i < (1 << d); i++)
    {
        int z = f(i, d);
        if(mapa.find(s - z) != mapa.end())
        {
            wyp(mapa[s - z], n / 2);
            wyp(i, d);
            return 0;
        }
    }
}