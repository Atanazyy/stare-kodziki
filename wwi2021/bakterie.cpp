#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
bool tab[r];
bool t2[r];
long long pot[100];

int main()
{
    long long k;
    int n;
    string s;
    cin >> n >> k >> s;
    pot[0] = 1;
    for(int i = 1; i <= 60; i++)
        pot[i] = pot[i-1] * 2;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'o')
        {
            tab[i] = 1;
            t2[i] = 1;
            t2[n * 2 - i] = 1;
        }
    }
    long long d = k;
    for(long long w = 60; w >= 0; w--)
    { 
        if(pot[w] <= d)
        {
            d -= pot[w];
            vector <int> jed;
            for(int i = 0; i < n; i ++)
            {
                if(tab[i]) jed.push_back(i);
            }
            long long p = pot[w];
            for(auto i : jed)
            {
                tab[i] ^= 1;
                tab[(((i - p) % n) + n) % n] ^= 1;
                tab[(i + p) % n] ^= 1;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(tab[i]) cout << 'o';
        else cout<< '.';
    }
    cout<<"\n";

    d = k;
    n = n * 2 + 2;
    for(long long w = 60; w >= 0; w--)
    { 
        if(pot[w] <= d)
        {
            d -= pot[w];
            vector <int> jed;
            for(int i = 0; i < n; i ++)
            {
                if(t2[i]) jed.push_back(i);
            }
            long long p = pot[w];
            for(auto i : jed)
            {
                t2[i] ^= 1;
                t2[(((i - p) % n) + n) % n] ^= 1;
                t2[(i + p) % n] ^= 1;
            }
        }
    }
    for(int i = 0; i < n / 2 -1; i++)
    {
        if(t2[i]) cout << 'o';
        else cout<< '.';
    }
    cout<<"\n";
}