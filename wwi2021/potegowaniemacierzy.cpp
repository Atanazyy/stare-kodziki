#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > matrix;

const long long p=1e9+7;

matrix mno(const matrix &a,const matrix &b)
{
    matrix c;
    int n=a.size();
    int m=a[0].size(); //=b.size()
    int k=b[0].size();
    c.resize(n);
    for(int i=0;i<n;i++)
    {
        c[i].resize(k);
        for(int j=0;j<k;j++)
        {
            c[i][j]=0;
            for(int l=0;l<m;l++)
                c[i][j]=(c[i][j]+a[i][l]*b[l][j])%p;
        }
    }
    return c;
}

matrix pot(matrix &a, long long w)
{
    int n=a.size();
    matrix b;
    b.resize(n);
    for(int i=0;i<n;i++)
    {
        b[i].resize(n);
        for(int j=0;j<n;j++)
            b[i][j]=(long long)(i==j);
    }
    while(w)
    {
        if(w&1)
            b=mno(b,a);
        a=mno(a,a);
        w/=2;
    }
    return b;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    matrix V1={{0,1,1}};
    matrix P1={{0,1,1},{1,1,1},{0,0,1}};
    matrix V2={{0,1,1}};
    matrix P2={{0,1,1},{1,1,1},{0,0,1}};
    long long wyn=(mno(V1,pot(P1,b))[0][2])%p;
    wyn=(wyn-(mno(V2,pot(P2,a-1))[0][2])+p)%p;
   /* V=mno(V,pot(P,5));
    for(auto x:V)
        for(auto y:x)
            cout<<y;*/
    cout<<wyn;
}