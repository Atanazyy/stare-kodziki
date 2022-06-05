#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > matrix;
const int p = 1e9 + 7;

matrix mno(matrix &A, matrix &B, int n)
{
    matrix C;
    C.resize(n);
    for(int i = 0; i < n; i++)
    {
        C[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for(int l = 0; l < n; l++)
            {
                C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % p;
            }
        }
    }
    return C;
}

matrix pot(matrix &A, long long k, int n)
{
    if(k == 1) return A;
    if(k%2 == 0)
    {
        matrix P = pot(A, k / 2, n);
        return mno(P, P, n);
    }
    matrix P = pot(A, k - 1, n);
    P = mno(P, A, n);
    return P;
}

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    matrix A;
    A.resize(n);
    for(int i = 0; i < n; i++)
    {
        A[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    A = pot(A, k, n);
    for(auto x : A)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}
