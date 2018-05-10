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
#include <iomanip>
using namespace std;
long long int n ;
long long int best_pos;
long long int worst_pos;
long long int O_plus;
long long int O_moins;
vector<pair<long double,bool>> tosort;
long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}

void testcasegene(){
  for(int i = 0; i < 500;i++){
    cout << 15 << endl;
    for(int j = 0; j < 15; j++){
      cout << rand() % 1000 << " " << rand() % 1000 << endl;
    }
  }
}

void initialise(){
  long double x1,x2,x3;
  cin >> x1 >> x2;
  O_plus = 0;
  O_moins = 0;
  x3 = x1 - x2;
  best_pos = 1;
  worst_pos = n;
  //int out_compteur;
  long long int y1,y2;
  long double y3,z;
  for(long long i = 1 ; i < n ; i++){

    cin >> y1 >> y2;
    ///cout << y1 << " " << y2 << endl;
    y3 = y1 - y2;

    if(y3 == x3){
      if(x2 != y2){
        if(x2 > y2)worst_pos--;
        else best_pos++;
      }
    }
    else{
      if(x2 == y2){

        if(x3 > y3)O_plus++;
        else O_moins++;
      }
      else{
        //cout << "ici" << endl;
        z = (long double)(x2 - y2)/(y3 - x3);
        //cout << z << endl;
        //cout << y1 << " " << y2 << endl;
        if(z < 0){
          //cout << "ici" << endl;
          if(x3 > y3)worst_pos--;
          else best_pos++;
        }
        else if(z > 1){
          //cout << "ici2" << endl;
          if(x3 > y3)best_pos++;
          else worst_pos--;
        }
        else{
          //cout << y1 << " " << y2 << endl;
          //cout << z << endl;
          if(x3>y3){
            best_pos++;
            //cout << y1 << " " << y2 << endl;
            tosort.push_back(pair<long double,bool>(z,true));
          }
          else{
            worst_pos--;
            tosort.push_back(pair<long double,bool>(z,false));
          }
        }
      }
    }
  }
  //cout << best_pos << " " << worst_pos << endl;

}
void solver(){
  initialise();
  long long int best = best_pos;
  long long int worst = worst_pos;
  best_pos+=O_moins;
  worst_pos-= O_plus;
  if(tosort.size() != 0){
    sort(tosort.begin(),tosort.end());
    long double last = (*tosort.begin()).first;

    long long int plus = 0;
    long long int moins = 0;
    for(auto it = tosort.begin(); it != tosort.end();it++){
      //cout << (*it).first << endl;
      if(last == (*it).first){
        if((*it).second == true){
          //cout << "ici" << endl;
          moins++;
        }
        else{
          plus++;
        }
      }
      else{
        //cout << moins << " " << plus << endl;
        best_pos -= moins;
        worst_pos += plus;

        if(best_pos < best) best = best_pos;
        if(worst_pos > worst) worst = worst_pos;
        best_pos += plus;
        worst_pos -= moins;
        moins = 0;
        plus = 0;

        if((*it).second == true){
            moins++;
          }
          else{
            plus++;
          }

    }
    last = (*it).first;
    }
    best_pos -= moins;
    worst_pos += plus;

    if(best_pos < best) best = best_pos;
    if(worst_pos > worst) worst = worst_pos;

    tosort.clear();
  }
  cout << best << " " << worst << endl;

}
int main(){

 while(cin >> n){
   //cout << n << endl;
   solver();
 }
 //testcasegene();

return 0;
}
