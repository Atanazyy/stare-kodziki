#include<bits/stdc++.h>
using namespace std;
const long long  N = 262144*2;
long long tree[N*2];
long long star[N*2];

void push(long long x)
{
tree[x]+=star[x];
star[x*2]+=star[x];
star[x*2+1]+=star[x];
star[x]=0;
}


void add(long long x, long long Qp , long long Qk , long long p , long long k , long long value)
{
    push(x);
    if(Qp>k || Qk<p)
    {
        return;
    }
  if(Qp <= p && k <=Qk)
  {
      star[x]=value;
      push(x);
      return;
  }

 long long sr = (p+k)/2;
      add(x*2,Qp,Qk,p,sr,value);
      add(x*2+1,Qp,Qk,sr+1,k,value);

  tree[x]=min(tree[x*2],tree[x*2+1]);
}

long long read (long long x, long long Qp , long long Qk , long long p , long long k)
{
     push(x);
    if(Qp>k || Qk<p)
    {
        return 9223372036854775806;
    }
    if(Qp <= p && k <=Qk)
    {
      return tree[x];
    }
long long sr = (p+k)/2;
return min(read(x*2,Qp,Qk,p,sr),read(x*2+1,Qp,Qk,sr+1,k));

}

int main()
{
long long n,q;
cin>>n>>q;
long long p;
for(long long  i=0;i<n;i++)
{
   cin>>p;
    tree[N+i]=p;
}
for(long long i = N-1; i >0; i--){
tree[i] = min(tree[2*i], tree[2*i+1]);
}


char w;
long long a,b,c;
for(long long i =0;i<q;i++)
{
    cin>>w;
    if(w=='?')
       {
           cin>>a>>b;
          cout<<read(1,a,b,1,N)<<endl;
       }
    else if(w=='+')
       {
        cin>>a>>b>>c;
         add(1,a,b,1,N,c);
       }
}

}