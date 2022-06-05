#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s = "$" + s;
    int  n = s.size();
    for(int i = 1; i < n - 1; i++)
    {
        if (s[i] != s[i + 1]) continue;
        int j = 0;
        int l = i - j;
        int r = i + j + 1;
        while(s[l] == s[r])
        {
            for(int x = 0; x < j + 1; x++)
            {
                if (s[l + x] != s[r + x +1])
                    break;
                if(x == j)
                {
                    cout<<"TAK\n";
                    for(int z = 0; z < (j + 1) * 3; z++)
                        cout<<s[l + z];
                    return 0;
                }
            }
            j++;
            l = i - j;
            r = i + j + 1;
        }
    }
    cout<<"NIE";
}