#include <bits/stdc++.h>

using namespace std;

const int r = 10009;
stack<int> stos[r];
bool sa[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        int v;
        cin >> v;
        if(c == 'a')
        {
            stos[i] = stos[v];
            stos[i].push(i);
        }
        if(c == 'b')
        {
            stos[i] = stos[v];
            cout << stos[i].top() << "\n";
            stos[i].pop();
        }
        if(c == 'c')
        {
            int w;
            cin >> w;
            stos[i] = stos[v];
            for(int j = 0; j <= i; j++)
                sa[j] = 0;
            vector<int> xd;
            while(!stos[v].empty())
            {
                sa[stos[v].top()] = 1;
                xd.push_back(stos[v].top());
                stos[v].pop();
            }
            reverse(xd.begin(), xd.end());
            for(auto x : xd)
                stos[v].push(x);

            xd.clear();
            int wyn = 0;

            while(!stos[w].empty())
            {
                if(sa[stos[w].top()])
                    wyn ++;
                xd.push_back(stos[w].top());
                stos[w].pop();
            }
            reverse(xd.begin(), xd.end());
            for(auto x : xd)
                stos[w].push(x);
            cout << wyn << "\n";
        }
    }
}
