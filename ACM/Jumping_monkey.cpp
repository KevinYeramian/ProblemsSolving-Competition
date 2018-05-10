#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <bitset>
using namespace std;
int n;
int m;
vector<int> etat[2097152];
vector<int> adj[21];
long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}
bool compare(vector<int> a , vector<int> b){
  if(a.size()<b.size())return true;
  if(a.size()>b.size())return false;
  for(unsigned i = 0 ; i < a.size() ;i++){
    if(a[i] < b[i])return true;
    if(a[i] > b[i])return false;
  }
  return false;
}


int Dist[21][21];
void FloydWarshall() {
  fill_n((int*) Dist, 21*21, 21);
  for(int u = 0; u < n ;u++){
    Dist[u][u] = 0;
    for(auto tmp :adj[u]){

      Dist[u][tmp] = 1;
    }
  }
  for(int k = 0 ; k < n ; k++){
    for(int i = 0; i <n ;i++){
      for(int j = 0; j < n ;j++){
        Dist[i][j] = min(Dist[i][j],Dist[i][k] + Dist[k][j]);
      }
    }
  }
}


vector<int> parcours(int x0,int x1){
  vector<int> vu ;
  vu.push_back(x0);
  vector<vector<int>> toselect;

  for(auto voisin :adj[x0]){
    if(adj[voisin].size() != 1 && voisin != x1 ){
      toselect.push_back(parcours(voisin,x0));
    }
  }
  if(toselect.size() == 0)return vu;
  sort(toselect.begin(),toselect.end(),compare);
  //cout << toselect.size() << endl;
  //cout << "x0 = " << x0 << endl;
  if(toselect.size() != 1){
    for(unsigned i = 0 ; i < toselect.size(); i++){
      //cout << toselect[i].size() << " ";
      for(unsigned j = 0; j < toselect[i].size(); j++){
        vu.push_back(toselect[i][j]);

      }
      if(i != toselect.size() - 1) vu.push_back(x0);
    }
  }
  else{
    //cout << toselect[0].size() << " ";
    for(unsigned j = 0; j < toselect[0].size(); j++){
      vu.push_back(toselect[0][j]);

    }
  }
  //cout << endl;
  return vu;
}


void initialise(){
  int x;
  int y;
  for(int i = 0 ; i < n ; i++)adj[i].clear();
  for(int i = 0 ; i < m ; i++){
      cin >> x >> y;
      //cout << x << " " << y << endl;
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  for(int i = 0 ; i < n ; i++){
      sort(adj[i].begin(),adj[i].end());
  }
}
void poubelle(){
  int x;
  int y;
  for(int i = 0 ; i < m ; i++){
      cin >> x >> y;
  }
}

bool checker(vector<int> p1,vector<int> p2){
  vector<int>  *possible = new vector<int>();
  vector<int>  *possible2 = new vector<int>();
  vector<int>  *possible3;
  for(int i = 0; i < n ; i++)possible->push_back(i);
  for(auto shot : p1){
    if(possible->size() == 0)return true;
    for(auto position : *possible){
      if(position != shot){
        for(auto voisin : adj[position]){
          if(voisin != shot){
            if(find(possible2->begin(),possible2->end(),voisin) == possible2->end())possible2->push_back(voisin);
          }
        }
      }
    }
    possible->clear();
    possible3 = possible;
    possible = possible2;
    possible2 = possible3;

  }

  for(int i = 0; i < n ; i++)possible->push_back(i);
  for(auto shot : p2){
    if(possible->size() == 0)return true;
    for(auto position : *possible){
      if(position != shot){
        for(auto voisin : adj[position]){
          if(voisin != shot){
            if(find(possible2->begin(),possible2->end(),voisin) == possible2->end())possible2->push_back(voisin);
          }
        }
      }
    }
    possible->clear();
    possible3 = possible;
    possible = possible2;
    possible2 = possible3;

  }
  if(possible->size() == 0)return true;
  return false;
}
void solver(){
  initialise();
  FloydWarshall();
  int max = 1;
  int indicemax;
  vector<int> out;
  vector<int> out2;
  vector<int> starter;


  for(int i = 0; i < n ;i++){
    for(int j = i + 1; j < n ;j++){
        if(Dist[i][j] > max){
          max = Dist[i][j];
        }
    }
  }
  //cout << max << endl;

  for(int i = 0; i < n ;i++){
    for(int j = i + 1; j < n ;j++){
      if(Dist[i][j] == max - 1){
        //cout << i << " " << j << endl;
        if(adj[i].size() != 1 && find(starter.begin(),starter.end(),i) == starter.end())starter.push_back(i);
        if(adj[j].size() != 1 && find(starter.begin(),starter.end(),j) == starter.end())starter.push_back(j);
      }
    }
  }
  //cout << starter.size() << endl;
  sort(starter.begin(),starter.end());
  //cout << starter[0]<< endl;
  out = parcours(starter[0],starter[0]);





  if(out.size() % 2 == 1){

    if(checker(out,out)){
      cout << out.size()*2 << ": ";
      for(unsigned i = 0 ; i < out.size() ; i++)cout << out[i] << " ";
      for(unsigned i = 0 ; i < out.size() ; i++){
        cout << out[i];
        if(i != out.size() - 1) cout << " ";
      }
    }
    else{
      cout << "Impossible";
    }
  }
  else{
      indicemax = starter[1];
      max = Dist[starter[0]][starter[1]];
      for(unsigned i = 0; i < starter.size() ; i++){
          if(Dist[starter[0]][starter[i]] > max){
             max = Dist[starter[0]][starter[i]];
             indicemax = starter[i];
           }

      }

      out2 = parcours(indicemax,indicemax);
      if(checker(out,out2)){
        cout << out.size()*2 << ": ";
        for(unsigned i = 0 ; i < out.size() ; i++)cout << out[i] << " ";
        for(unsigned i = 0 ; i < out2.size() ; i++){
          cout << out2[i];
          if(i != out.size() - 1) cout << " ";
        }
      }
      else{
        cout << "Impossible";
      }

  }
  cout << endl;
  /*
  if(checker(out,out2))cout <<"true" << endl;
  else cout << "false" << endl;
  */
  //cout << starter.size() << endl;
}




int main(){
cin >> n >> m;
 while(n != 0 || m != 0){
   //cout << n << " " << m << endl;
   if(m>= n){
     cout << "Impossible" <<endl;
     poubelle();
   }
   else{
     if(n == 2){
       cout << "2: 0 0" << endl;
       poubelle();
     }
     else if(n == 1){
       cout << "1: 0"<< endl;
     }
     else solver();
   }
   cin >> n >> m;

 }

return 0;
}
