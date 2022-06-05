#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const int r = 5009;
int A[r];
int dp[r][r];
int n, m;

struct S
{
    void solve()
    {
        string S, P;
        cin >> S >> P;
        n = S.size();
        m = P.size();
        for(int i = 0; i < n; i++)
        {
            int j = i, por = 0;
            while(j < n && por < m)
            {
                if(S[j] == P[por])
                    por++;
                j++;
            }
            if(por != m)
                A[i] = -1;
            else
                A[i] = j - 1;
            //cout << A[i] << " ";
        }
        //cout << "\n";
        for(int i = (n + m) * 2; i >= 0; i--)
            for(int j = 0; j <= (n + m) * 2; j++)
            {
                dp[i][j] = -1e9;
                if(j == 0)
                    dp[i][j] = 0;
            }

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= n - i; j++)
            {
                dp[i][j] = max(dp[i + 1][j - 1], dp[i + 1][j]);
                if(A[i] != -1)
                    dp[i][j] = max(1 + dp[A[i] + 1][j - (A[i] - i + 1 - m)], dp[i][j]);
                //cout << dp[i][j] << " ";
            }
            //cout << "\n";
        }
        for(int i = 0; i <= n; i++)
        {
            cout << dp[0][i] << " ";
        }
        cout << "\n";
    }

};

int main()
{
    int z;
    cin >> z;
    while(z --)
    {
        S s;
        s.solve();
    }
}
