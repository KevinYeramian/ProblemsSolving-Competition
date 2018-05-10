#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int max_indice;
vector<int> Circuit;
list<int> adj[51];
long long n;
int number_edge;
long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}
long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}

void Hierholzer(){
  int v = 1;
  for(int i = 1 ; i < n;i++){
    if(adj[i].size() != 0){
      v = i;
      break;
    }

  }
  stack<int> Stack;
  Stack.push(v);
  while(!Stack.empty()){
    if(!adj[v].empty()){
      Stack.push(v);
      int tmp = *(adj[v].begin());
      adj[v].pop_front();
      for(auto it = adj[tmp].begin();it != adj[tmp].end();it++){
          if(*it == v){
            adj[tmp].erase(it);
            break;
          }
      }

      v = tmp;
    }
    else{
      Circuit.push_back(v);
      v = Stack.top();
      Stack.pop();
    }
  }
}

void initialise(){
  for(int i = 0 ; i <= 50 ; i++){
    adj[i].clear();
  }
  Circuit.clear();
  cin >> number_edge;
  //cout << number_edge << endl;
  //cout << "number_edge = " << number_edge << endl;
  int x,y;
  for(int i = 0 ; i < number_edge ; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}

void solver(){
  initialise();

  for(int i = 0; i <= 50 ; i++){
    if(adj[i].size()%2 != 0){
      cout << "some beads may be lost" << endl;
      return;
    }
  }
  Hierholzer();


    for(int i = 0; i < Circuit.size() - 1;i++){
      cout << Circuit[i] << " " << Circuit[i + 1] << endl;
    }
    //cout << Circuit.size() << endl;
    //cout << Circuit[Circuit.size() - 1] << " " << Circuit[0] << endl;


}
int main(){
  int k = 1;
  cin >> n;
  for(long long i = 0 ; i < n ; i++){
    cout << "Case #" << k <<endl;
    k++;
    solver();
    if(i !=  n - 1) cout << endl;
  }


  return 0;

}
