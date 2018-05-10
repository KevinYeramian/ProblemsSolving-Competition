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
	int N,M;
	cin >> N >> M;
	if(M < 45){
		N = ((N - 1) + 24)  % 24;
		M = (M - 45 + 60) % 60;
		cout << N << " " << M << endl;
	}
	else cout << N << " " << M - 45 << endl;


return 0;
}
