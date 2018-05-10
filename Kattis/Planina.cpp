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
typedef long long ll;
typedef long l;
typedef long double ld;

long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}

void initialise(){

}

void solver(){
  
}




int main(){
	long long N;
	cin >> N;
	ll u1 = 3;
	ll u2 = 5;
	ll u3;
	ll nn = 5;
	if(N == 1) cout << u1 * u1 << endl;
	else if(N == 2) cout << u2 * u2 << endl;
	else{
		 for(long long i = 3; i <= N; i++){
		 	nn = nn *2 - 1;
		 }
		 //cout << nn <<endl;
		 cout << nn * nn << endl;
	}


return 0;
}
