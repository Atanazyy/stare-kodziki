#include <bits/stdc++.h>

using namespace std;

const int maxa = 1e9;
unordered_map <int, int> mapa;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int maxx = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mapa[x] ++;
        maxx = max(x, maxx);
    }
    int p = 1073741824;
    if(maxx <= 1e6)
        p = 1048576;
    int wyn = 0;
    while(p >= 1)
    {
        //cout << p << " ";
        for(auto x : mapa)
        {
            if(x.first == p - x.first)
            {
                int a = x.second / 2;
                wyn += a;
                mapa[x.first] -= a * 2;
                //cout << a << " " << x.first << " " << x.first << "\n";
            }
            else
            {
                if(mapa.find(p - x.first) != mapa.end())
                {
                    int a = min(x.second, mapa[p - x.first]);
                    wyn += a;
                    mapa[x.first] -= a;
                    mapa[p - x.first] -= a;
                    //cout << a << " " << x.first << " " << p - x.first << "\n";
                }
            }
        }
        p /= 2;
    }
    cout << wyn;
}
