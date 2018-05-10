#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
using namespace std;
int M;
bool graph[500][500];
long long rides[500];
int A[500][2];
int B[500][2];
long long n;
long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}
long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}

bool in[500];
bool out[500];
#define NIL 0
vector<int> X;
vector<int> Y;
vector<int> Adj[501];
int MAXX;
int MAXY;
int pairX[501];
int pairY[501];
unsigned int Dist[501];

bool BFS(){
  queue<int> Q;
  Dist[NIL] = UINT_MAX;
  for(auto x : X){
    Dist[x] = (pairX[x] == NIL) ? 0 : UINT_MAX;
    if(pairX[x] == NIL)Q.push(x);
  }
  while(!Q.empty()){
    int x = Q.front(); Q.pop();
    if(Dist[x] < Dist[NIL]){
      for(auto y : Adj[x]){
        if(Dist[pairY[y]] == UINT_MAX){
          Dist[pairY[y]] = Dist[x] + 1;
          Q.push(pairY[y]);
        }
      }
    }
  }
  //cout << Dist[NIL] << endl;
  return Dist[NIL] != UINT_MAX;
}

bool DFS(int x){
  if(x != NIL){
    for(auto y : Adj[x]){
      if(Dist[pairY[y]] == (Dist[x] + 1) && DFS(pairY[y])){
        pairX[x] = y;
        pairY[y] = x;
        return true;
      }
    }
    Dist[x] = UINT_MAX;
    return false;
  }
  return true;
}



int HopcroftKarp(){
  fill_n(pairX,501,NIL);
  fill_n(pairY,501,NIL);
  int matching = 0;
  while(BFS()){

    for(auto x : X){
      if(pairX[x] == NIL && DFS(x))matching++;
    }
  }
  //cout << matching << endl;

  return M - matching;
}

void initialise(){
  for(int i = 0; i <= M ;i++){
    Adj[i].clear();
  }
  X.clear();
  Y.clear();
  for(int i = 0 ; i < M ; i++){
    in[i] = false;
    out[i] = false;
    for(int j = 0; j < M;j++ ){
      graph[i][j] = false;
    }
  }
  cin >> M;
  int hour = 0;
  int minutes = 0;
  char h;
  int x1,y1,x2,y2;
  for(int i = 0; i < M ;i++){
    cin >> hour >> h >> minutes;
    cin >> x1 >> y1 >> x2 >> y2 ;
    //cout << hour << " " << minutes << endl;
    rides[i] = hour * 60 + minutes;
    A[i][0] = x1;
    A[i][1] = y1;
    B[i][0] = x2;
    B[i][1] = y2;
  }

  for(int i = 0; i < M;i++){
    for(int j = i+1 ; j < M ;j++){
      if(i != j){
        long long distanceAA = abs(A[i][0] - B[i][0]) +  abs(B[i][1] - A[i][1]);
        long long distanceAB = abs(B[i][0] - A[j][0]) +  abs(B[i][1] - A[j][1]);
        if(rides[i] + distanceAA + distanceAB < rides[j]){
          graph[i][j] = true;
          in[j] = true;
          out[i] = true;
        }
      }
    }
  }
  int x_max = 0;
  int y_max = 0;
  for(int i = 0; i < M ; i++){
    if(in[i]){
      y_max++;
      Y.push_back(i + 1);
    }
    if(out[i]){
      x_max++;
      X.push_back(i + 1);
    }
  }
  MAXY = y_max;
  MAXX = x_max;
  //cout << MAXX << " " << MAXY << endl;
  for(int i = 0 ; i < MAXX ; i++){
    int i_bis = X[i];
    for(int j = i_bis ; j < M ; j++){
      if(graph[i_bis -1][j])Adj[i_bis].push_back(j + 1);
    }
  }
  /*
  cout << "ADJ" << endl;
  for(int i = 1; i <= M ; i++){
    for(auto it = Adj[i].begin() ; it != Adj[i].end() ; it++){
      cout << i << " " << *it << endl;
    }
  }
  cout << "ADJ" << endl;*/
}



void solver(){
  initialise();
  cout << HopcroftKarp() << endl;

}
int main(){
  int n;
  cin >> n;
  for(long long i = 0 ; i < n ; i++){
    solver();
  }


  return 0;

}
