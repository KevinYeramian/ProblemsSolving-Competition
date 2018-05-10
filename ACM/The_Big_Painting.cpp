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
int w1,w2,h1,h2;
bool w[2001][2000];
bool s[4000000];
int nw;
int trie[4000001][2];
int compteur;
int fs;
int endw[4000001];
int s2[4000000];
int pointer[4000001];
int shortcut[4000001];
bool tocheck[2001];
int groupeid[2001];
int r[20002];
long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}


void initialise(){
  for(int i = 0 ; i < 2002; i++) groupeid[i] = 0;
  string lines;
  nw = h1;
  for(int i = 0 ; i < h1; i++){
    cin >> lines;

    for(int j = 0 ; j < w1;j++){
      w[i + 1][j] = (lines[j] == 'x') ? true : false;
    }
  }
  for(int i = 0 ; i < h2; i++){
    cin >> lines;
    for(int j = 0 ; j < w2;j++){
      s[(i * w2 + j)] = (lines[j] == 'x') ? true : false;
      s2[i + h2 *j] = 0;
      trie[(i * w2 + j)][0] = 0; trie[(i * w2 + j)][1] = 0;
      endw[(i * w2 + j)] = 0;
    }
  }
  for(int i = 0 ; i <= h1*w1 ;i++){
    shortcut[i] = 0; pointer[i] = 0;
  }
}

void insert_trie(int i,bool *s, int n){
  if(compteur == w1){
    endw[n] = i; return;
  }
  bool x = s[0];
  if(!trie[n][x]){
     trie[n][x] = fs++;

   }
  compteur++;
  return insert_trie(i,s+1,trie[n][x]);

}


int aho_partern(bool * s){
  int ns = w1;
  int pos = 1;
  for(int i = 0 ; i < ns;i++){
    bool x = s[i];
    if(trie[pos][x] != 0){
      pos = trie[pos][x];
    }
    else return 0;
  }
  return endw[pos];
}

void aho_init(){
  fs = 2;
  int indice = 1;
  for(int i = 1; i <= nw ; i++){
    compteur = 0;
    int pattern = aho_partern(w[i]);
    if(pattern == -1 || pattern == 0){
       insert_trie(indice,w[i],1);
       groupeid[i] = indice++;
     }
    else{
      groupeid[i] = pattern;
    }
    //cout << fs << endl;
    //cout << "nw = " << i << " pattern = " << groupeid[i] << endl;
  }
  //cout << "terminer" << endl;
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    //cout << q.size() << endl;
    int n = q.front();q.pop();
    for(int x = 0; x <= 1;x++){
      int n2 = trie[n][x];
      if(n2){
        int p = pointer[n];
        while(p && !trie[p][x]){
          p = pointer[p];
        }
        if(!p) pointer[n2] = 1;
        else pointer[n2] = trie[p][x];
        if(endw[pointer[n2]]) shortcut[n2] = pointer[n2];
        else shortcut[n2] = shortcut[pointer[n2]];
        q.push(n2);
      }

    }

  }
}

void aho(){
  int ns = h2 * w2;
  int pos = 1;
  for(int i = 0 ; i < ns;i++){
    bool x = s[i];
    while(pos && !trie[pos][x]) pos = pointer[pos];
    pos = trie[pos][x];
    if(!pos) pos = 1;
    int posb = pos;
    do{
      if(endw[posb]){

        int a = i - w1 + 1;
        //out << a << endl;
        int groupe = endw[posb];
        //cout << groupe << endl;
        //cout << a%w2 << endl;
        if( a%w2 <= w2-w1){
          //cout << a << endl;
          int xi = a %w2;
          int yi = (int)(a/w2);
          s2[xi * h2 + yi] = groupe;
          //s2[a] = groupe;
          //cout << groupe << endl;
          //cout << "y = " << a/w2 << " x = " << a % w2 << "base = " << a << endl;

        }
      }
      posb = shortcut[posb];
    }while(endw[posb]);

  }
}

void knuth_morris_pratt_init(){
  for(int i = 0; i < 2002;i++) r[i] = 0;
  int j =  0;
  r[0] = -1;

  for(int i = 1; i < h1+1; i++){
    r[i] = j;
        while( j >= 0  && groupeid[i + 1] != groupeid[j + 1] ){
          j = r[j];
        }
        j++;
    }
  }

void knuth_morris_pratt(){
  int j = 0;
  int out = 0;
  for(int i = 0; i < w2*h2 ;i++){

    while(j >=0 && groupeid[j + 1] != s2[i]){
      j = r[j];
    }
    j++;
    //cout << i  << " j = " << j<< endl;
    if(j == h1){

      if(( i - h1 + 1)%h2 <= h2-h1)out++;
    }
  }
  cout << out << endl;
}

void solver(){
  initialise();

  aho_init();
  aho();
  knuth_morris_pratt_init();
  knuth_morris_pratt();



}

int main(){

 while(cin >> h1 >> w1 >> h2 >> w2){
   solver();
 }

return 0;
}
