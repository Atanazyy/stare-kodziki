#include<bits/stdc++.h>

using namespace std;

const int M=1e9*2;
const int N=1e6;
vector<pair<int,int>>tab[N];
pair<int,int>s[N];
int lider[N];
int wielkosc[N];

int finde(int a){
    if(lider[a]==a){
        return a;
    }
    lider[a]=finde(lider[a]);
    return lider[a];
}
void unione(int a, int b){
    wielkosc[finde(b)]=min(wielkosc[finde(a)],wielkosc[finde(b)]);
    lider[finde(a)]=finde(b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b,c;
    int cen=0;
    cin>>n>>m;
    for (int i=0;i<N;i++){
        wielkosc[i]=M;
        lider[i]=i;
    }
    for (int i=0;i<n;i++){
        cin>>s[i].first;
        s[i].second=i+1;
    }
    sort(s,s+n);
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        tab[a].push_back({b,c});
        tab[b].push_back({a,c});
    }
    int mini=M;
    int ind=0;
    //cout<<"xd";
    for (int i=0;i<n;i++){
        for (int j=0;j<tab[s[i].second].size();j++){
            //cout<<"xd";
            if (wielkosc[finde(tab[s[i].second][j].first)]!=M){
                if (tab[s[i].second][j].second<mini){
                    mini=tab[s[i].second][j].second;
                    ind=tab[s[i].second][j].first;
                }
            }
        }
        if (mini<s[i].first){
            //cout<<"xd";
            unione(ind, s[i].second);
            cen+=mini;
        }else{
            wielkosc[finde(s[i].second)]=s[i].first;
            cen+=s[i].first;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<tab[i].size();j++){
            if(finde(i)!=finde(tab[i][j].first)){
                if (max(wielkosc[finde(i)],wielkosc[finde(tab[i][j].first)])>tab[i][j].second){
                    cen+=tab[i][j].second;
                    cen-=max(wielkosc[finde(i)],wielkosc[finde(tab[i][j].first)]);
                    unione(i, tab[i][j].first);
                }
            }
        }
    }
    cout<<cen;
}
