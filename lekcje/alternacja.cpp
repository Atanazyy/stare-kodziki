#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    string s;
    cin >> n >> q >> s;
    char o = 'a';
    int wyn = 0;
    for(auto x : s)
    {
        if(x != o)
            wyn ++;
        o = x;
    }
    cout << wyn << "\n";
    while(q--)
    {
        int x;
        cin >> x;
        x --;
        if(x == 0)
            if(s[0] == s[1]) wyn ++;
            else wyn --;
        else if(x == n - 1)
            if(s[n - 1] == s[n - 2]) wyn ++;
            else wyn --;
        else
        {
            if(s[x - 1] == s[x + 1] && s[x - 1] == s[x]) wyn += 2;
            if(s[x - 1] == s[x + 1] && s[x - 1] != s[x]) wyn -= 2;
        }
        if(s[x] == '0') s[x] = '1';
        else s[x] = '0';
        cout << wyn << "\n";
    }
}