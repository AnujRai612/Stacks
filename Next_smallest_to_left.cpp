#include<bits/stdc++.h>
using namespace std;
vector <int> nextLargest(vector<int> arr)
{
  stack<int>s;
  vector<int>v;
  for(int i=0;i<arr.size();i++){
    if(s.size()==0)
      v.push_back(-1);
    else if(s.size()>0 && s.top()<arr[i]){
      v.push_back(s.top());
    }
    else if(s.size()>0 && s.top()>=arr[i]){
      while(s.size()>0 && s.top()>=arr[i]){
        s.pop();
      }
      if(s.size()==0)
        v.push_back(-1);
    }
    else{
      v.push_back(s.top());
    }
    s.push(arr[i]);
  }
  return v;
  
}
int main(){
   vector<int> v={4,5,2,10,8};
   vector<int> u=nextLargest(v);
   for(int i=0;i<u.size();i++){
    cout<<u[i]<<" ";
   }
   return 0;
}
