#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > matrix;
const int p = 123456789;

matrix mno(matrix A, matrix B)
{
    matrix C;
    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();
    C.resize(n);
    for(int i = 0; i < n; i++)
    {
        C[i].resize(k);
        for(int j = 0; j < k; j++)
        {
            C[i][j] = 0;
            for(int l = 0; l < m; l++)
            {
                //cout << i << j << l;
                C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % p;
            }
        }
    }
    return C;
}

matrix pot(matrix A, long long k)
{
    matrix B;
    int n = A.size();
    B.resize(n);
    for(int i = 0; i < n; i++)
    {
        B[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            B[i][j] = (i == j);
        }
    }
    while(k > 0)
    {
        if(k % 2 == 1)
            B = mno(B, A);
        A = mno(A, A);
        k /= 2;
    }
    return B;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    matrix A;
    A.resize(1);
    int lic = 'z' - 'a' + 1;
    A[0].resize(lic);
    for(int i = 0; i < lic; i++)
        A[0][i] = 1;
    matrix P;
    P.resize(lic);
    for(int i = 0; i < lic; i++)
    {
        P[i].resize(lic);
        for(int j = 0; j < lic; j++)
            P[i][j] = 1;
    }
    while(k--)
    {
        char a, b;
        cin >> a >> b;
        P[a - 'a'][b - 'a'] = 0;
    }
    P = pot(P, n - 1);
    A = mno(A, P);
    long long wyn = 0;
    for(int i = 0; i < lic; i++)
        wyn = (wyn + A[0][i]) % p;
    cout << wyn;
}