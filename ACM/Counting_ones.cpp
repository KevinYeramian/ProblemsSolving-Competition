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

unsigned long long a;
unsigned long long b;
vector<unsigned long long> power;

long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(unsigned long long a , unsigned long  long b){
 if(a<b)return b;
 return a;
}
void make_power(){
  for(int i = 0; i < 63;i++){
    power.push_back(0);
  }
  power[0] = 1;
  power[1] = 2;
  for(int i = 2; i < 63;i++){
    power[i] = (power[i - 1] - 1)*2 + maxi( 0,pow(2, i - 1)) + 1;
  }
}
unsigned long long number_of_one(unsigned long long a){
  if(a == 0)return 0;
  if(a == 1)return 1;
  if(a == 2)return 2;
  bitset<64> a_bit(a);
  int start = 63;
  while(a_bit[start] == 0)start--;
  unsigned long long out = 0 ;
  int k = 0;
  while(start >=0){
    out +=power[start] +  maxi(0,k *pow(2,start));
    start--;
    k++;
    while(start >= 0 && a_bit[start] == 0 )start--;
  }
  return out;
}
void solver(){
  unsigned long long result = number_of_one(b);
  result -= maxi(0,number_of_one(a - 1));
  cout << result << endl;
}
int main(){
 make_power();

 while(cin >> a >> b){
   solver();
 }

return 0;
}
