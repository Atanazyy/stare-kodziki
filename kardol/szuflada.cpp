#include <bits/stdc++.h>

using namespace std;

const int roz = 2e6 + 9;
int z[roz];
int rz[roz];
int ss[roz];

int main()
{
    int n, m;
    string t, s;
    cin >> t >> s;
    n = t.size();
    m = s.size();
    string mer = s + '#' + t;
    int r = -1, l = -1;
    for(int i = 1; i <= n + m; i++)
    {
        if(r >= i) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] <= n + m && mer[z[i]] == mer[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    /*cout << mer << "\n";
    for (int i = 0; i <= n + m; i++)
        cout << z[i] << " ";*/
    r = -1, l = -1;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    string rev = s + "#" + t;
    for(int i = 1; i <= n + m; i++)
    {
        if(r >= i) rz[i] = min(r - i + 1, rz[i - l]);
        while(i + rz[i] <= n + m && rev[rz[i]] == rev[i + rz[i]])
            rz[i]++;
        if(i + rz[i] - 1 > r)
        {
            r = i + rz[i] - 1;
            l = i;
        }
    }
    //cout << mer << "\n";
    int o = m + 1;
    for(int i = n + m; i >= 0 && o <= n + m; i--)
    {
        ss[o] = rz[i];
        o ++;
    }
    for(int i = m + 1; i <= n + m; i++)
    {
        if(z[i] + ss[i - 1] >= m)
        {
            cout <<"TAK";
            return 0;
        }
        //cout << ss[i] << " ";
        //cout << z[i] << " " << rz[n + m + 1 - i + 1] << ", ";
    }
    cout << "NIE";
}