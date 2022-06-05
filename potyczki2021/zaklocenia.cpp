#include <bits/stdc++.h>

using namespace std;

char tab[7] = {'x','x','x','a','c','g','w'};

void rozw(int zli, int n)
{
    if(n == 0) 
        return;
    for(int i = 3; i <= 6; i++)
    {
        int nt = n - 1, zlit = zli - i;
        if(zlit > 6 * nt || zlit < nt * 3) 
            continue;
        cout << tab[i];
        rozw(zlit, nt);
        break;
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zli = 0;
    for(auto x : s)
    {
        if(x == '1') zli++;
    }
    //cout << zli;
    if(zli > 6 * n || zli < n * 3) 
    {
        cout << "NIE";
        return 0;
    }
    rozw(zli, n);
}