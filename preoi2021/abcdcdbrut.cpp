#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int wyn =0;
    for(int m1 = 0; m1 < n; m1++)
    {
        for(int m2 = m1 + 1; m2 < n; m2++)
        {
            for(int m3 = m2+ 1; m3 < n; m3++)
            {
                for(int m4 = m3 + 1; m4 < n; m4++)
                {
                    for(int m5 = m4 + 1; m5 < n; m5++)
                    {
                        for(int m6 = m5 + 1; m6 < n; m6++)
                        {
                            if(s[m6] != s[m4]) 
                                continue;
                            if(s[m5] != s[m3])
                                continue;
                            set <int> xd;
                            xd.insert(s[m1]);
                            xd.insert(s[m2]);
                            xd.insert(s[m3]);
                            xd.insert(s[m4]);
                            xd.insert(s[m5]);
                            xd.insert(s[m6]);
                            if(xd.size() != 4)
                                continue;
                            wyn++;
                        }
                    }
                }
            }
        }
    }
    cout << wyn;
}