#include <bits/stdc++.h>

using namespace std;

set <int> moz;

int main()
{
    int n;
    cin >> n;
    int wyn = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vector <int> wyw;
        for(auto y : moz)
        {
            if(y < x) 
                wyw.push_back(y);
            else
                break;
        }
        for(auto y : wyw)
            moz.erase(y);
        if(moz.find(x) == moz.end()) wyn ++; 
        moz.insert(x);
    }
    cout << wyn;
}