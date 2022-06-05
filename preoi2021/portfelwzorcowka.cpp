#include <bits/stdc++.h>

using namespace std;

int tab[209];
int pre[209];

int main()
{
    int n;
    cin >> n;
    if(n >= 200)
    {
        cout << 1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        pre[i] = pre[i - 1] ^ tab[i];
    }
    int wyn = 1e9;
    for(int i = 1; i < n; i++)
    {
        for(int s1 = 1; s1 < n; s1++)
        {
            for(int s2 = 1; s2 <= n - i + 1 - s1; s2++)
            {
                if((pre[i + s1 - 1] ^ pre[i - 1]) > (pre[i + s1 + s2 - 1] ^ pre[i + s1 - 1]))
                {
                    //cout << i << " " << s1 << " " << s2 << "\n";
                    wyn = min(s1 + s2 - 2, wyn);
                }
            }
        }
    }
    if(wyn == 1e9) 
        cout << -1;
    else
        cout << wyn;
}