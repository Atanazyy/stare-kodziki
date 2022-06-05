#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > matrix;
const int p = 1e9 + 7;

matrix mno(matrix &A, matrix &B)
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

matrix pot(matrix &A, long long k)
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
    long long k, l;
    cin >> k >> l;
    matrix A = {{0,1,1},{1,1,1},{0,0,1}};
    A = pot(A, l);
    matrix B = {{0, 1, 1}};
    matrix C = mno(B, A);
    long long wyn = C[0][2];
    A = {{0,1,1},{1,1,1},{0,0,1}};
    A = pot(A, k - 1);
    B = {{0, 1, 1}};
    C = mno(B, A);
    cout << (p + wyn - C[0][2]) % p;
}