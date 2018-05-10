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
string st;
unsigned long long start[1000000];
long long jump[1000000][3];
long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}



unsigned long long initialise(){
  unsigned long long out = 0;
  jump[st.size() - 1][0] = -1;
  jump[st.size() - 1][1] = -1;
  jump[st.size() - 1][2] = -1;
  start[st.size() - 1] = 0;
  if( st[st.size() - 1] >= 48 && st[st.size() - 1] <= 57 ){
    int cint = ((int)st[st.size() - 1]) % 3;
    if(cint == 0){
      start[st.size() - 1] = 1;
      jump[st.size() - 1][0] = st.size() - 1;
      out++;
    }
    else if(cint == 1){
      jump[st.size() - 1][1] = st.size() - 1;
    }
    else{
      jump[st.size() - 1][2] = st.size() - 1;
    }
  }
  auto end = st.end();
  end--;
  end--;
  long long i = st.size() - 2;
  for(auto it = end ; it >= st.begin() ; it--,i--){
    char c = *it;

    if(c >= 48 && c <= 57 ){
      //cout << "ici " << c << " " << i << endl;
      int cint = ((int)c) % 3;

      start[i] = 0;
      jump[i][0] = -1;
      jump[i][1] = -1;
      jump[i][2] = -1;
      if( cint == 0){
        jump[i][0] = i;
        jump[i][1] = jump[i + 1][1];
        jump[i][2] = jump[i + 1][2];
      }
      else if(cint == 1){
        jump[i][0] = jump[i + 1][2];
        jump[i][1] = i;
        jump[i][2] = jump[i + 1][1];
      }
      else{
        jump[i][0] = jump[i + 1][1];
        jump[i][1] = jump[i + 1][2];
        jump[i][2] = i;
      }
      if(cint == 0 ){
        start[i] = 1;
        start[i] += start[i + 1];
      }
      else {
        if(jump[i][0] != -1){
          start[i] = 1;
          if((jump[i][0] + 1) <= (long long)(st.size() - 1)){
            start[i] += start[jump[i][0] + 1];
          }
        }
      }
      out +=start[i];


    }
    else{
      jump[i][0] = -1;
      jump[i][1] = -1;
      jump[i][2] = -1;
      start[i] = 0;
      if(c >= 48 && c <= 57){
          if( (((int) c) % 3) == 0){
            start[i] = 1;
            jump[i][0]= i;
          }
          else if( (((int) c) % 3) == 1){
            start[i] = 0;
            jump[i][1]= i;
          }
          else{
            start[i] = 0;
            jump[i][2]= i;
          }
      }


      out += start[i];
    }
  }
  return out;
}

void solver(){
  cout << initialise() << endl;

  /*
  for(int i = 0; i < st.length(); i++){
    cout << i << " " <<  st[i] << " " << jump[i][0] << " " << jump[i][1] << " " << jump[i][2]  << " score : " << start[i] << endl;
  }*/


}
int main(){

 while(cin >> st){
   //cout  << st << endl;
   solver();
 }

return 0;
}
