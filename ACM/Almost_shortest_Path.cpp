#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <utility>
using namespace std;
long long relation[500][500];
long long debut,fin;
bool belongToShort[500];
bool seen[500];
long long dist[500];

long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}

long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}

void initialise(long long N,long long M){
  long long x,y,p;
  cin >> debut >> fin;

  for(long long  i = 0 ; i < N ; i++){
    dist[i] = LLONG_MAX;
    belongToShort[i] = false;
    seen[i] = false;
    for(long long j = 0 ; j < N ;j++){
      relation[i][j] = -1 ;
    }
  }

  for(int i = 0 ; i < M ; i++){
    cin >> x >> y >> p ;
    relation[x][y] = p;
  }
}


long long minIn( list<long long > *nextlist){
  long long min = LLONG_MAX;
  auto outmax = nextlist->begin();

  for(auto it = nextlist->begin(); it != nextlist->end(); it++){
    if( dist[*it] < min){
      outmax = it;
      min = dist[*it];
    }
  }

  long long out = *outmax;
  nextlist->erase(outmax);
  return out;
}

void dikjstra(long long N){

  list<long long > next;
  long long tocheck;
  dist[debut] = 0;
  seen[debut] = true;
  next.push_back(debut);
  while(next.size() != 0 ){
    tocheck = minIn(&next);
    for(long long  i = 0; i < N ; i++){
      if(relation[tocheck][i] != -1 && seen[i] == false){
        if(dist[i] == LLONG_MAX)next.push_back(i);
        dist[i] = mini(dist[i], dist[tocheck] + relation[tocheck][i]);
      }
    }
    seen[tocheck] = true;
  }
}

void dikjstra2(long long N){
  for(int i = 0 ; i < N ; i++){
    dist[i] = LLONG_MAX;
    seen[i] = false;
  }
  list<long long > next;
  bool flag;
  long long tocheck;
  dist[debut] = 0;
  seen[debut] = true;
  next.push_back(debut);
  while(next.size() != 0 ){
    tocheck = minIn(&next);
    for(long long  i = 0; i < N ; i++){
      flag = belongToShort[i] && belongToShort[tocheck];
      //cout << "tocheck = " << tocheck << " i = " << i << " flat = " << flag << " " << relation[tocheck][i] << endl;
      if(relation[tocheck][i] != -1 && seen[i] == false && flag == false){
        if(dist[i] == LLONG_MAX)next.push_back(i);
        dist[i] = mini(dist[i], dist[tocheck] + relation[tocheck][i]);
      }
    }
    seen[tocheck] = true;
  }
}

void backtrackShortPath(long long N){
  queue <long long> file ;
  file.push(fin);
  belongToShort[fin] = true;
  long long check;
  while(file.size() != 0){
    check = file.front() ; file.pop();
    for(int i = 0 ; i < N ; i++){
      if(relation[i][check] != -1 && (relation[i][check] + dist[i]) == dist[check] && belongToShort[i] == false){
        belongToShort[i] = true;
        file.push(i);
      }
    }

  }

}
void solver(long long N, long long M){
  initialise(N,M);
  dikjstra(N);
  backtrackShortPath(N);
  dikjstra2(N);

  if(dist[fin] != LLONG_MAX) cout << dist[fin] << endl;
  else cout << "-1" << endl;

}
int main(){
  long long N,M;
  cin >> N >> M;
  while( N != 0 && M != 0){
    solver(N,M);
    cin >> N >> M;
  }

  return 0;

}
