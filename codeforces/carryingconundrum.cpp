#include <bits/stdc++.h>

using namespace std;

struct Solve
{
    long long dp[20][4];
    void solve()
    {
        string a;
        cin >> a;
        if(a.size() == 1)
        {
            cout << a[0] - '1' << "\n";
            return;
        }
        dp[a.size() - 1][0] = a[a.size() - 1] - '0' + 1;
        dp[a.size() - 1][1] = 0;
        dp[a.size() - 1][2] = '9' - a[a.size() - 1];
        dp[a.size() - 1][3] = 0;
        //for(auto x : dp[a.size() - 1])
            //cout << x <<" ";
        for(int i = a.size() - 2; i >= 0; i--)
        {
            dp[i][0] = (a[i] - '0' + 1) * dp[i + 1][0];
            if(a[i] != '9')
                dp[i][0] += (a[i] - '0') * dp[i + 1][1];
            dp[i][1] = (a[i] - '0' + 1) * dp[i + 1][2];
            if(a[i] != '9')
                dp[i][1] += (a[i] - '0') * dp[i + 1][3];
            dp[i][2] = ('9' - a[i]) * dp[i + 1][0];
            dp[i][2] += ('9' - a[i] + 1) * dp[i + 1][1];
            dp[i][3] = ('9' - a[i]) * dp[i + 1][2];
            dp[i][3] += ('9' - a[i] + 1) * dp[i + 1][3]; 
            //for(auto x : dp[i])
                //cout << x <<" ";
        }
        cout << dp[0][0] - 2 << "\n";

    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        Solve s;
        s.solve();
    }
}
    