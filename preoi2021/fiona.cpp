#include <bits/stdc++.h>

using namespace std;

const int roz = 2e7 + 9;
int z[roz];
int rz[roz];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int x;
    x = s1.size();
    string s = s1 + '#' + s2;
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
       // cout << z[i] << " ";
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    s = s1 + '#' + s2;
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            rz[i] = min (r - i + 1, rz[i - l]);
        while (i + rz[i] < n && s[rz[i]] == s[i + rz[i]])
            ++rz[i];
        if (i + rz[i] - 1 > r)
            l = i, r = i + rz[i] - 1;
    }
    int wyn = 0;
    for(int i = x + 1; i + x - 1 < n; i++)
    {
        //cout << (n-1) + (x - i + 1) << " "; 
        wyn = max( wyn, min(x, z[i] + rz[-(i + x - 1) + n - 1 + x + 1]) );

    }
    cout << x - wyn;
}   