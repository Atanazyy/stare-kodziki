#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > matrix;

const int p = 1e9 + 7;
const long long mk = 1e18 + 9;
pair <int, int> que[209];
pair <long long, int> dosor[209];
long long odp[209];
matrix tab[100];

matrix mno(matrix A, matrix B)
{
    matrix C;
    int n = A.size();
    C.resize(n);
    for(int i = 0; i < n; i++)
    {
        C[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % p;
            }
        }
    }
    return C;
}

matrix pot(long long k)
{
    matrix B;
    int n = tab[0].size();
    B.resize(n);
    for(int i = 0; i < n; i++)
    {
        B[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            B[i][j] = (i == j);
        }
    }
    int s = 0;
    while(k > 0)
    {
        if(k % 2 == 1)
        {
            B = mno(B, tab[s]);
        }
        k/=2;
        s ++;
    }
    return B;
}

void pre(matrix A, long long k)
{
    int s = 0;
    while(k > 0)
    {
        tab[s] = A;
        A = mno(A, A);
        s ++;
        k /=2 ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, z;
    cin >> n >> m >> z;
    matrix A;
    A.resize(n);
    for(int i = 0; i < n; i++)
    {
        A[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
    }
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        A[a - 1][b - 1] ++;
    }
    pre(A, mk);
    matrix B = A;
    for(int i = 0; i < z; i++)
    {
        int a, b;
        long long k;
        cin >> a >> b >> k;
        dosor[i] = {k, i};
        que[i] = {a, b};
    }
    sort(dosor, dosor + z);
    long long pk = 1;
    for(int i = 0; i < z; i++)
    {
        auto x = dosor[i];
        long long roz = x.first - pk;
        pk = x.first;
        A = mno(A, pot(roz));
        /*for(auto x : A)
        {
            for(auto y : x)
                cout << y << " ";
            cout << " \n";
        }*/
        int a = que[x.second].first - 1;
        int b = que[x.second].second - 1;
        //cout << a << " " << b << "\n";
        odp[x.second] = A[a][b];
    }
    for(int i = 0; i < z; i++)
        cout << odp[i] << "\n";
}