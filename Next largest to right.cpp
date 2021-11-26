#include<bits/stdc++.h>
using namespace std;
vector <int> nextLargest(vector<int> v1)
{
  stack<int>s;
  vector<int>v;
  for(int i=v1.size()-1;i>=0;i--){
    if(s.size()==0)
      v.push_back(-1);
    else if(s.size()>0 && s.top()>v1[i]){
      v.push_back(s.top());
    }
    else if(s.size()>0 && s.top()<=v1[i]){
      while(s.size()>0 && s.top()<=v1[i]){
        s.pop();
      }
      if(s.size()==0)
        v.push_back(-1);
      else{
        v.push_back(s.top());
      }
    }
    s.push(v1[i]);
  }
  reverse(v.begin(),v.end());
  return v;
}
int main(){
   vector<int> v={1,3,2,4};
   vector<int> u=nextLargest(v);
   for(int i=0;i<u.size();i++){
    cout<<u[i]<<" ";
   }
   return 0;
}
