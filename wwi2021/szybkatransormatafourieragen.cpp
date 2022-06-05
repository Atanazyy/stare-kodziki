#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

#define MIN_PER_RANK 0 /* Nodes/Rank: How 'fat' the DAG should be.  */
#define MAX_PER_RANK 4
#define MIN_RANKS 1    /* Ranks: How 'tall' the DAG should be.  */
#define MAX_RANKS 4
#define PERCENT 50     /* Chance of having an Edge.  */

vector<pair<int,int> > tab;

int main (void)
{
  int a;
  cin >> a;
  srand (a);
    int t = (rand() % 5) +1;
    cout<< t<<"\n";
    while(t--){
    int i, j, k,nodes = 1;
    tab.clear();
  int ranks = MIN_RANKS
              + (rand () % (MAX_RANKS - MIN_RANKS + 1));
  for (i = 0; i < ranks; i++)
    {
      /* New nodes of 'higher' rank than all nodes generated till now.  */
      int new_nodes = MIN_PER_RANK
                      + (rand () % (MAX_PER_RANK - MIN_PER_RANK + 1));

      /* Edges from old nodes ('nodes') to new ones ('new_nodes').  */
      for (j = 1; j < nodes; j++)
        for (k = 0; k < new_nodes; k++)
          if ( (rand () % 100) < PERCENT)
            tab.push_back ({j, k + nodes}); /* An Edge.  */

      nodes += new_nodes; /* Accumulate into old node set.  */
    }
    cout <<nodes << " "<<tab.size()<<"\n";
    for(int i = 0; i < nodes; i++)
        cout<<1+(rand()%2)<<" ";
    cout<<"\n";
    for(auto x:tab) cout <<x.first<<" "<<x.second<<"\n";
    }
  return 0;
}