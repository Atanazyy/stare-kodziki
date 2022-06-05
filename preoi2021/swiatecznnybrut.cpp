#include <bits/stdc++.h>

using namespace std;

const int r = 50;
int tab[r];
int n, s;

int f(int x)
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

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    cin >> s;
    for(int i = 0; i < (1 << n); i++)
    {
        if(f(i) == s) 
        {
            int x = i;
            for(int j = 0; j < n; j++)
            {
                cout << x % 2;
                x /= 2;
            }
            return 0;
        }
    }
}