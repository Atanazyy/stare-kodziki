#include<bits/stdc++.h>
using namespace std;
int lzapyt;
/*bool comp1(int a,int b){
    return szk[a]<szk[b];
}
bool comp2(int a,int b){
    return szk[b]<szk[a];
}*/
queue<int>que[2];
queue<int> que2[2];
void Toposort(int curr){}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>lzapyt;
    for(int i=0;i<lzapyt;i++){
        int lpa,lstr;
        int wyn0=0,wyn1=0;
        bool curr;
        cin>>lpa>>lstr;
        bool szk[lpa+1];
        vector<int>t[lpa+1];
        int lwchod[lpa+1];
        int lwchod2[lpa+1];
        for(int i=1;i<=lpa;i++){
            int s;
            cin>>s;
            szk[i]=s-1;
            lwchod[i]=0;
            lwchod2[i]=0;
        }
        for(int i=0;i<lstr;i++){
            int a,b;
            cin>>a>>b;
            t[a].push_back(b);
            lwchod[b]++;
            lwchod2[b]++;
        }
        //for(int i=0;i<=lpa;i++)
            //cout<<lwchod[i]<<" ";
        for(int i=1;i<=lpa;i++){
            if(lwchod[i]==0){
                que[szk[i]].push(i);
                que2[szk[i]].push(i);
            }
        }
        //cout<<"\n";
        curr=0;
        while(!que[0].empty()||!que[1].empty()){
            while(!que[curr].empty()){
                int w=que[curr].front();
                que[curr].pop();

                for(int i=0;i<t[w].size();i++){
                    int syn=t[w][i];
                    lwchod[syn]--;
                    if(lwchod[syn]==0){
                        que[szk[syn]].push(syn);
                    }
                }
            }
            wyn0++;
            curr=!curr;
        }
        curr=1;
        while(!que2[0].empty()||!que2[1].empty()){
            while(!que2[curr].empty()){
                int w=que2[curr].front();
                que2[curr].pop();
                //cout<<w<<" ";
                for(int i=0;i<t[w].size();i++){
                    int syn=t[w][i];
                    lwchod2[syn]--;
                    if(lwchod2[syn]==0){
                        que2[szk[syn]].push(syn);
                    }
                }
            }
            wyn1++;
            curr=!curr;
        }

        //cout<<"\n";
        //cout<<wyn0<<wyn1<<"\n";
        wyn0=min(wyn0,wyn1)-1;
        cout<<wyn0<<"\n";
    }
    /*
1
5 6
1 2 1 2 1
1 2
1 3
2 4
3 4
2 5
3 5
*/
}
