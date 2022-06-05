#include <bits/stdc++.h>

using namespace std;

const int r=1e6+9;
int tab[r];
long long pref[r];
int spa[25][r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
        pref[i]=pref[i-1]+tab[i];
    }
    for(int i=1;i<=n;i++) spa[0][i]=tab[i];
    int siz=1;
    for(int i=1;i<=20;i++)
    {
        siz*=2;
        for(int j=1;j<=n-siz+1;j++)
        {
            spa[i][j]=max(spa[i-1][j],spa[i-1][j+siz/2]);
           // cout<<i<<" "<<j<<" "<<spa[i][j]<<"\n";
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int siz=b-a+1;
        if(siz<3)
        {
            cout<<"NIE\n";
            continue;
        }
        long long sum=pref[b]-pref[a-1];
        siz=log2(siz);
        //cout<<siz;
        int ma=max(spa[siz][a],spa[siz][b-(1<<siz)+1]);
        //cout<<ma<<"\n";
        if(ma*2 < sum) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
}