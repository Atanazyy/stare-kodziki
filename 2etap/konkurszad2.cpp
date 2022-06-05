#include <bits/stdc++.h>

using namespace std;

int kto[1000 * 1000 + 9];
int roz[3];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin >> q;
    int y = 3;
    kto[1] = 1;
    kto[2] = 2;
    roz[1]= 1;
    roz[2] = 1;
    while(q--)
    {
        int x;
        char z;
        cin >> z;
        cin >> x;
        if(z == '?')
        {
            cout << roz[kto[x]] << "\n";
        }
        else
        {
            if(kto[x] == 1)
            {
                roz[2]++;
                kto[y] = 1;
            }
            else
            {
                roz[1]++;
                kto[y] = 2;
            }
            y++;
        }
    }
}