#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;

int dp[r];
int len[200];
int tab[200][200];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        len[i] = s.size();
        for(auto x : s)
            tab[i][x]++;
        dp[(1 << i)] = len[i] + 1;
    }
    for(int msk1 = 1; msk1 < (1 << n); msk1++)
    {

        if(__builtin_popcount(msk1) == 1)
        {
            /*int a = msk1;
            for(int i = 0; i < n; i++)
            {
                if(a % 2)
                {
                    //jed.push_back(i);
                }
                //cout << a % 2;
                a /= 2;
            }
            //cout << " " << dp[msk1] << "\n";*/
            continue;
        }
        int a = msk1;
        vector<int> jed;
        for(int i = 0; i < n; i++)
        {
            if(a % 2)
            {
                jed.push_back(i);
            }
            //cout << a % 2;
            a /= 2;
        }
        //cout << ": ";
        int wyn = 1e9;
        for(int msk2 = 1; msk2 < (1 << jed.size()) - 1; msk2++)
        {
            int s = 0;
            int b = msk2;
            for(int i = 0; i < jed.size(); i++)
            {
                if(b % 2)
                {
                    s += (1 << jed[i]);
                }
                b /= 2;
            }
            wyn = min(wyn, dp[s] + dp[msk1 ^ s]);
            /*for(int i = 0; i < n; i++)
            {
                cout << s % 2;
                s /= 2;
            }
            cout << " ";*/
        }
        //cout << "\n";
        for(int i = 'a'; i <= 'z'; i++)
        {
            int wsp = 1e9;
            for(auto x : jed)
                wsp = min(tab[x][i], wsp);
            wyn -= wsp;
        }
        wyn--;
        dp[msk1] = wyn;
        //cout << wyn << "\n";
    }
    cout << dp[(1 << n) - 1];
}
