#include <bits/stdc++.h>
using namespace std;
 
int maxPackedSets(vector<int>& items, vector<set<int> >& sets)
{
  int maxSets = 0;
 
  for (auto set : sets) 
  {
    int numSets = 0;
    for (auto item : items) 
    {
      if (set.count(item)) 
      {
        numSets += 1;
        items.erase(remove(items.begin(),items.end(), item),items.end());
      }
    }
    maxSets = max(maxSets, numSets+1);
  }
  return maxSets;
}
 
int main()
{
  vector<int> items = { 5, 12, 3, 8, 4, 9 };
 
  vector<set<int> > sets
    = { { 12, 4, 3 }, 
        { 4, 9 }, 
        { 5, 3 }, 
        { 3, 4, 8, 9 } };
 
  int maxSets = maxPackedSets(items, sets);
  cout << "Maximum number of sets that can be packed: "<< maxSets << endl;
 
  return 0;
}
