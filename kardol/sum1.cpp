#include <bits/stdc++.h>

using namespace std;

int sum(int x)
{
    int w = 0;
    while(x > 0)
    {
        w += x % 10;
        x /= 10;
    }
    return w; 
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, m, q;
    cin >> s >> m >> q;
    while(q--)
    {
        int k;
        cin >> k;
        int akt = 0, byl = 0;
        while(byl != k && akt <= 1000 * 1000)
        {
            if(sum(akt) == s)
                byl++;
            akt += m;
        }
        if(byl == 0)
        {
            cout << "NIE\n";
            continue;
        }
        cout << akt - m << "\n";
    }
}