#include <bits/stdc++.h>

using namespace std;

bool czy(int a)
{
    int b = log2(a);
    b = 1 << b;
    if(a == b) return 1;
    return 0;
}

int solve(vector<int> tab)
{
    int n = tab.size();
    //for(auto x : tab)
    //    cout << x << " ";
    //cout << "\n";
    if(n < 2)
        return 0;
    //cout << "xd\n";
    int wyn = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = i + 1; j < n; j++)
        {
            vector<int> tem = tab;
            tem.erase(tem.begin() + i);
            tem.erase(tem.begin() + j - 1);
            int xd = solve(tem);
            if(czy(tab[i] + tab[j]))
                wyn = max(wyn, 1 + xd);
            wyn = max(wyn, xd);
        }
    }
    return wyn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> tab;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tab.push_back(x);
    }
    cout << solve(tab);
}