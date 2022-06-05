#include<bits/stdc++.h>

using namespace std;

map <int, int> mapa;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int p, k, x;
        cin >> p >> k >> x;
        for(int j = p; j <= k; j+= x)
        {
            mapa[j] ++;
        }
    }
    for(auto x: mapa)
    {
        if(x.second % 2 == 1)
        {
            cout << x.first << " " <<x.second <<"\n";
            return 0;
        }
    }
    cout << "NIE\n";
}