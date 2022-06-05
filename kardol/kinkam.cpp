#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int tab[N];
int w[N];
int odw[N];

int main(){
    int n,m,maxi,wyn;
    maxi=-1;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>tab[i];
    }
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=0;i<n;i++){
        wyn=0;
        for (int j=1;j<=m;j++){
            odw[j]=0;
        }
        for (int j=i;j<n;j++){
            if (odw[tab[j]]==1){
                wyn-=w[tab[j]];
                odw[tab[j]]++;
            }
            if (odw[tab[j]]==0){
                wyn+=w[tab[j]];
                maxi=max(maxi,wyn);
                odw[tab[j]]++;
            }
        }
    }
    cout<<maxi;
}