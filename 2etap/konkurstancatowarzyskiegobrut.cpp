#include <bits/stdc++.h>

using namespace std;

vector <int> tab[1000 * 1000 + 9];
int kto[1000 * 1000 + 9];
int roz[3];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q;
    cin >> q;
    int y = 3;
    if(q > 5000)
    {
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
        return 0;
    }
    tab[1].push_back(2);
    tab[2].push_back(1);
    while(q--)
    {
        char z;
        cin >> z;
        int x;
        cin >> x;
        if(z == '?')
            cout << tab[x].size() << "\n";
        if(z == 'W')
        {
            tab[x].push_back(y);
            tab[y].push_back(x);
            y++;
        }
        if(z == 'Z')
        {
            for(auto v : tab[x])
            {
                tab[v].push_back(y);
                tab[y].push_back(v);
            }
            y++;
        }
        /*for(int i = 1; i <= y; i++)
        {
            cout << i << ": ";
            for(auto v : tab[i])
                cout << v << " ";
            cout << "\n";
        }
        cout << "\n";*/
    }
}