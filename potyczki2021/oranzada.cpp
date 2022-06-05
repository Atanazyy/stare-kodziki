#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

bool byl[r];
queue <int> kol;

int main()
{
    int n, k;
    cin >> n >> k;
    long long wyn = 0;
    int zr = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        kol.push(i);
        if(!byl[x]) 
        {
            byl[x] = 1;
            wyn += i - kol.front();
            kol.pop();
            zr ++;
        }
        if(zr == k) break;
    }
    if(k > zr) cout << -1;
    else cout << wyn;
}
