#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
int tab[r];
int ost[r];
bool byl[r];
const long long p = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    long long ile = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        if(!byl[tab[i]]) ile ++;
        byl[tab[i]] = 1;
    }
    for(int i = 1; i <= n - 2; i++)
        if(tab[i] == tab[i + 2]) ost[i + 1] = tab[i];
    for(int i = 2; i <= n; i += 2)
    {
        if(ost[i] != 0 && ost[i] != tab[i - 1])
        {
            cout << 0;
            return 0;
        }
        ost[i] = tab[i - 1];
        if(tab[i + 1] == tab[i - 1]) break;
    }
    for(int i = n - 1; i >= 1; i -= 2)
    {
        if(ost[i] != 0 && ost[i] != tab[i + 1])
        {
            cout << 0;
            return 0;
        }
        ost[i] = tab[i + 1];
        if(tab[i + 1] == tab[i - 1]) break;
    }
    long long wyn = 1;
    for(long long i = 1; i <= n - ile; i++)
        wyn = (wyn * i)  % p;
    //for(long long i = 1; i <= n; i ++)
      //  cout << ost[i] << " ";
    //cout << "\n";
    for(long long i = 1; i <= n; i ++)
    {
        long long j = i;
        while(ost[j] == 0 && j <= n)
        {
            ost[j] = -1;
            j += 2;
        }
        //cout << i <<" " << j - i << "\n";
        wyn = (wyn * max((long long)1, (j - i)/2) ) % p;
    }
    cout << wyn;
}