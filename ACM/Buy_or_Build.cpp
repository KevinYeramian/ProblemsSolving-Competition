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
int q;
long long price[8];
int subGraphe[8][1000];
long long position[1000][2];
int subGrapheSize[8];
int inG [1000];
vector<pair<long long , int>> edge;
string take;
long long mini( long long a , long long b){
  if(a<b)return a;
  return b;
}
long long maxi(long long a , long long b){
  if(a<b)return b;
  return a;
}



void initialise(){
  cin >> n >> q;
  int number_vertex_sub;
  long long distance;
  //cout << "q = " << q << endl;

  for(int i = 0; i < q ; i++){
    cin >> number_vertex_sub;
    cin >> price[i];
    subGrapheSize[i] = number_vertex_sub;
    //cout << "The " << i << " sub " << " price = " << price[i] << " nb_n" << subGrapheSize[i] << endl;
    for(int j = 0 ; j < number_vertex_sub ; j++){
      cin >> subGraphe[i][j];
      subGraphe[i][j]--;
    }
  }
  for( int i = 0 ; i < n ; i++){
    cin >> position[i][0] >> position[i][1];
  }

  for(int i = 0; i < n ; i++){
    for(int j = 0; j < i ; j++){
      if(i != j){
        distance = pow((position[i][0] - position[j][0]) , 2) + pow((position[i][1] - position[j][1]) , 2);
        edge.push_back(pair<long long ,int>(distance,i*n + j));
        }
      }
    }
  sort(edge.begin(), edge.end());
}

long long Kruskal(string init){
  long long out_score = 0;
  //cout <<init <<endl;
  for(int i = 0; i < n;i++) inG[i] =0;
  int groupe_np = 1;
  for(int index = 7 ; index >= 8-q ; index--){
    //cout << init[index];
    //cout << init[index] <<endl;

    if(init[index] == '1'){
      int flagnow = groupe_np;
      int flagpast = groupe_np;
      for(int i = 0 ; i < subGrapheSize[7 - index]; i++){
        if(inG[subGraphe[7 - index][i]] == 0){
            inG[subGraphe[7 - index][i]] = flagnow;
          }
        else if(inG[subGraphe[7 - index][i]] != flagnow){
            flagpast = inG[subGraphe[7 - index][i]];
            for(int j = 0; j <= i ; j++){
              inG[subGraphe[7 - index][j]] = flagpast;
            }
            flagnow = flagpast;
        }
    }
    out_score += price[7 - index];
    groupe_np++;
  }
}
  //cout << endl;
  //cout <<  "for = " << out_score<< endl;
  auto cursor = edge.begin();
  long long score;
  int key;
  int x , y ;

  while(cursor != edge.end()){
    //cout << "ici"<<endl;
    score = cursor->first;
    key = cursor->second;
    x = key/n;
    y = key%n;

    if(inG[x]== 0 && inG[y] == 0){
      //cout << x << " " << y << " " << score <<endl;
      inG[x] = groupe_np;
      inG[y] = groupe_np;
      groupe_np++;
      out_score += score;
    }
    else if(inG[x] == 0){
      //cout << x << " " << y << " " << score <<endl;
      inG[x] = inG[y];
      out_score += score;
    }
    else if(inG[y] == 0){
      //cout << x << " " << y << " " << score <<endl;
      inG[y] = inG[x];
      out_score += score;
    }
    else if(inG[y]!=inG[x]){
      //cout << x << " " << y << " " << score <<endl;
      out_score += score;
      int valuex = inG[x];
      for(int i = 0 ; i < n ;i++){
          if(inG[i] == valuex)inG[i] = inG[y];
      }
    }
    cursor++;
  }

  //cout << out_score << endl;

return out_score;
}

void solver(){
  initialise();
  long long score_aux;
  long long min = LLONG_MAX;

  for(int i = 0 ;i < pow(2,q) ;i++){
      score_aux = Kruskal(bitset< 8 >(i).to_string()) ;
      //cout << score_aux << " " << bitset< 8 >(i).to_string()<<endl;
      if(score_aux < min){
        min= score_aux;
      }
    }

  cout<< min << endl;
  //cout << mins << endl;

}
int main(){
  int N;
  cin >> N;
  for(long long i = 0 ; i < N ; i++){
    solver();

    edge.clear();
    if(i != N-1)cout<<endl;
  }

return 0;
}
