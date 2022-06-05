#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
int P[r];

int main()
{
    string s;
    int n;
    cin >> s;
    n = s.size();
    cout << "0 ";
    for(int i = 1; i < n; i++)
    {
        int j = P[i - 1];
        while(s[i] != s[j] && j > 0)
            j = P[j - 1];
        if(s[i] == s[j])
            j++;
        P[i] = j;
        cout << j << " ";
    }
}