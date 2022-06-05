#include <bits/stdc++.h>

using namespace std;

struct Solve
{
    char out[100][100];
    void solve()
    {
        int n;
        string s;
        cin >> n >> s;
        int win = 0;
        int las = -1;
        int fir;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                for(int j = 0; j < n; j++)
                {
                    out[i][j] = out[j][i] = '=';
                }
            }
            else
            {
                win ++;
                if(las == -1)
                {
                    fir = i;
                    las = i;
                    continue;
                }
                out[i][las] = '+';
                out[las][i] = '-';
                las = i;
            }
        }
        if(win == 1 || win == 2)
        {
            cout << "NO\n";
            return;
        }
        if(win != 0)
        {
            out[fir][las] = '+';
            out[las][fir] = '-';
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                if(i == j) 
                    cout << "X";
                else 
                    cout << out[i][j];
            cout << "\n";
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve o;
        o.solve();
    }  
}