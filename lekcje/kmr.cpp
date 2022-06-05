#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
int kmr[r][20];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        kmr[i][0] = s[i] - 'a' + 1;
    int j = 1;
    while((1 << j) <= 2 * n)
    {
        vector<pair<pair<int, int>, int> > tab;
        int i = 0;
        while(i < n)
        {
            tab.push_back({{kmr[i][j - 1], kmr[i + (1 << (j - 1))][j - 1]}, i});
            //cout << tab.back().first.first << " " << tab.back().first.second <<", ";
            i++;
        }
        //cout << "\n";
        sort(tab.begin(), tab.end());
        pair<int, int> ost = {-1, -1};
        int nr = 1;
        for(auto x : tab)
        {
            if(ost != x.first)
            {
                ost = x.first;
                nr++;
            }
            kmr[x.second][j] = nr;
        }
        j++;
    }
    /*for(int k = 0; k < 20; k++)
    {
        for(int i = 0; i < 2 * n; i++)
            cout << kmr[i][k] << " ";
        cout << "\n";
    }*/
    int mie = 0;
    int rek = -1;
    for(int i = 0; i < 2 * n; i++)
    {
        if(kmr[i][j - 1] > rek)
        {
            rek = kmr[i][j - 1];
            mie = i;
        }
    }
    cout << mie + 1;
}