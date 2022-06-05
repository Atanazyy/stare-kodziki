#include <bits/stdc++.h>

using namespace std;

string s;
int n;

bool czy(int x)
{
    for(int i = 0; i < n - x + 1; i++)
    {
        for(int j = 0; j < n - x + 1; j++)
        {
            if(i == j) continue;
            bool f = 1;
            for(int k = 0; k < x; k++)
            {
                if(s[i + k] != s[j + k])
                {
                    f = 0;
                    break;
                }
            }
            if(f) return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> s;
    for(int i = n; i >= 0; i--)
    {
        if(czy(i))
        {
            cout << i;
            return 0; 
        }
    }
}