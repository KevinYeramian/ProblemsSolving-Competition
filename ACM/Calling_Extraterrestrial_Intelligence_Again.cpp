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
vector<long double> premiers;
long double a,b,m;
void crible(){
  bitset<100001> P;
  P.set();
  P[0] = P[0] = 0;
  for(long long i = 2; i<50001;i++){
    if(P[i]){
      for(long long j = i*i ; j < 50001;j+=i){
        P[j] = 0;
      }
      premiers.push_back(i);
    }
  }
}

long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(unsigned long long a , unsigned long  long b){
 if(a<b)return b;
 return a;
}

void solver(){
  long double divions = a/b;
  //cout << divions << endl;
  long double max = 0;
  long double p_max = 0;
  long double q_max = 0;
  long double q = 0;
  long double divions2;
  for(auto p : premiers){
    q = 0;
    for(int i = 0; i <=premiers.size() ;i++){
      divions2 = (premiers[i] >= p) ? p/premiers[i] : premiers[i]/p;
      if((p*premiers[i]) <= m && divions2 >= divions){
        q = premiers[i];
      }
      else{
          if((p*premiers[i]) > m)break;
      }
    }
    //cout <<p << " " << q << endl;
    if(q == 0)break;
    divions2 = (q >= p) ? p/q : q/p;
    //cout << divions2 << endl;
    if(divions2 >= divions){
      if(p*q >= max){
        //cout << max << endl;
        max = p*q;
        p_max = p;
        q_max = q;
      }
    }

  }
  if(p_max <= q_max)cout << p_max<< " " << q_max << endl;
  else cout << q_max<< " " << p_max << endl;
}
int main(){

 crible();
 cin >> m >> a >> b;
 while(a || b || m){
   //cout << m << a << b;
   solver();
   cin >> m >> a >> b;
 }

return 0;
}
