#include <bits/stdc++.h>

using namespace std;

const int roz = 1e6 + 9;

int p[roz];

int main()
{
    string s;
    int n;
    cin >> n >> s;
    string t = "#";
    for(auto x : s)
    {
        t += x;
        t += '#';
    }
    t = '!' + t + '@';
    int r = 0, l = 1;
    //cout << t;
    /*for(int i = 1; i <= 2 * n + 1; i++)
        cout << t[i] << " ";
    cout << "\n"; */
    for(int i = 1; i <= 2 * n + 1; i++)
    {
        p[i] = max(0, min(r - i, p[l + r - i]));
        while(t[i - p[i]] == t[i + p[i]])
            p[i] ++;
        if(i + p[i] > r)
        {
            r = i + p[i];
            l = i - p[i];
        }
    }
    for(int i = 2; i < 2 * n + 1; i++)
        cout << p[i] - 1 << " ";
}