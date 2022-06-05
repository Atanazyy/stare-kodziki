#include <bits/stdc++.h>

using namespace std;

vector<int> wyn;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i <= m; i++)
    {
        bool f = 1;
        if(m % i != 0) continue;
        for(int j = 0; j  < m; j++)
        {
            if(s[j % i] != s[j]) 
            {
                f = 0;
                break;
            }
        }
        if(f)
            wyn.push_back(i);
    }
    cout << wyn.size() << "\n";
    for(auto x : wyn)
        cout << x << " ";
}