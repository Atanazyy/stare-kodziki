#include <bits/stdc++.h>

using namespace std;

struct Solve
{
    void solve()
    {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int a;
                cin >> a;
                if(a % 2 != (i + j) % 2)
                    cout << a + 1 << " ";
                else 
                    cout << a << " "; 
            }
            cout << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, t;
    cin >> t;
    while(t--)
    {
        Solve s;
        s.solve();
    }
}