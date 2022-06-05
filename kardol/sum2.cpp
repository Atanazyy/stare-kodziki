#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s, m, q;
    cin >> s >> m >> q;
    while(q--)
    {
        long long k;
        cin >> k;
        long long pie = -1;
        long long akt = 1;
        for(int i = 0; i <= 17; i ++)
        {
            if(akt % m == 0) 
            {
                pie = i;
                break;
            }
            akt *= 10;
        }
        if(pie == -1 || pie + k - 1 > 199)
        {
            cout << "NIE\n";
            continue;
        }
        cout << "1";
        for(int i = 0; i < pie + k - 1; i++)
            cout << "0";
        cout << "\n";
    }
}