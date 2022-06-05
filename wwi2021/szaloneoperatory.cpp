#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
vector <long long> tabi;
int opi[r];
vector <long long> tab;
int op[r];
const int p = 1e9 + 7;
vector <int> kol;

int main()
{
    int n;
    cin >> n;
    if(n > 8)
    {
        long long wyn = 1;
        for(int i = 0; i < n ; i++)
        {
            int a;
            cin >> a;
            wyn = (wyn * a) % p;
        }
        for(int i = 0; i < n - 1 ; i++)
        {
            char a;
            cin >> a;
        }
        cout << wyn;
        return 0;
    }
    for(int i = 0; i < n ; i++)
    {
        int a;
        cin >> a;
        tabi.push_back(a);
    }
    for(int i = 0; i < n - 1 ; i++)
    {
        char a;
        cin >> a;
        opi[i] = a;
        kol.push_back(i);
    }
    long long sum = 0;
    do
    {
        tab.clear();
        for(int i = 0; i < n - 1 ; i++) op[i] = opi[i];
        for(int i = 0; i < n ; i++) tab.push_back(tabi[i]);
        for(auto x:kol) 
        {
            int kto = 0;
            for(int i = 0; i < x; i++)
            {
                if(op[i] != 0) kto ++;
            }
            if(op[x] == '*')
                tab[kto] = (tab[kto] * tab[kto + 1]) % p;
            if(op[x] == '+')
                tab[kto] = (tab[kto] + tab[kto + 1]) % p;
            if(op[x] == '-')
                tab[kto] = (tab[kto] - tab[kto + 1] + p) % p;
            op[x] = 0;
            tab.erase(tab.begin() + kto + 1);
        }
        //cout << tab[0]<< "\n";
        sum = (sum + tab[0]) % p;
    } while (next_permutation(kol.begin(), kol.end()));
    cout<<sum;
}