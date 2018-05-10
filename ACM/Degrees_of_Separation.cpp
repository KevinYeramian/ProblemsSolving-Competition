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
int seen[50];
bool relation[50][50];
int mind[50][50];
map <string,int> indice;
long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}
long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}

void initialise(int P,int R){
  indice.clear();
  string R1,R2;
  int compteur = 0;
  for(int i = 0 ; i < P; i++ ){
    for(int j = 0 ; j < P ; j++){
      relation[i][j] = false;
      mind[i][j] = 500;
    }
  }
  for(int i = 0; i < R ; i++){
    cin >> R1 >> R2;

    if(indice.find(R1) == indice.end()){
      indice[R1] = compteur;
      compteur++;
    }
    if(indice.find(R2) == indice.end()){
      indice[R2] = compteur;
      compteur++;
    }
    relation[indice[R1]][indice[R2]] = true;
    relation[indice[R2]][indice[R1]] = true;
  }


}
int parcoursLargeur(int debut , int P){
  for(int i = 0 ; i < P ; i++)seen[i] = -1;
  seen[debut] = 0;
  queue<int> tosee;
  tosee.push(debut);
  int actual ;
  while(tosee.size() != 0){
    actual = tosee.front();tosee.pop();
    for(int i = 0; i < P;i++){
      if(seen[i] == -1 && relation[actual][i]){
        tosee.push(i);
        seen[i] = 1 + seen[actual];
      }
      else if(seen[i] != -1 && relation[actual][i]){
        seen[i] = min(seen[i],seen[actual] + 1);
      }
    }
  }
  int min_out = 0;
  for(int i = 0; i < P; i++){
      if(seen[i] == -1) return -1;
      mind[debut][i] = min(seen[i],mind[debut][i]);
      mind[i][debut] = mind[debut][i];

  }
  return 1;
}
void solver(int P){
  int min_out = 0;
  int out;
  for(int i = 0; i < P ; i++){
    out = parcoursLargeur(i,P);
    if(out == -1){
      cout <<"DISCONNECTED";
      return;
    }
  }
  for(int i = 0 ; i < P; i++){
    for(int j = 0 ; j < i; j++){
      min_out = max(min_out,mind[i][j]);
    }
  }
  cout << min_out;
}
int main(){
  int P;int R;
  string a,b;
  cin >> P >> R;
  int k = 1;
  while(P != 0 && R !=0 ){
    initialise(P,R);
    cout <<"Network " << k << ": ";
    solver(P);
    cout << endl;
    k++;
    cin >> P >> R;
    cout << endl;
  }

  return 0;

}
